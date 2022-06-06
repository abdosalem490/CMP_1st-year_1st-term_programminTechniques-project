#include "CUTANDPASTE_OP.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Gate.h"


CUTPASTE_OP::CUTPASTE_OP(ApplicationManager* pApp) :Action(pApp)
{
	p = pApp;
	OutputInterface = p->GetOutput();
}

CUTPASTE_OP::~CUTPASTE_OP(void)
{
}

void CUTPASTE_OP::ReadActionParameters()
{

}

void CUTPASTE_OP::CUTTING_LOOP(Component* TO_CUT) {

	int Cx, Cy;
	do {
		OutputInterface->PrintMsg("CUT. Click anywhere VALID in the drawing area to paste.");
		p->GetInput()->GetPointClicked(Cx, Cy);

		if (Cx > UI.width - UI.ToolItemWidth || Cy < UI.ToolBarHeight || Cy >= UI.height - UI.StatusBarHeight - (UI.AND2_Height / 2)) {
		}
		else {

			GraphicsInfo new_gfx;
			new_gfx.x1 = Cx - UI.AND2_Width / 2;
			new_gfx.x2 = Cx + UI.AND2_Width / 2;
			new_gfx.y1 = Cy - UI.AND2_Height / 2;
			new_gfx.y2 = Cy + UI.AND2_Height / 2;

			TO_CUT->SetGraphicsInfo(new_gfx);
			dynamic_cast<Gate*>(TO_CUT)->ResetOutputAndInputLocation();

		}
	} while (Cx > UI.width - UI.ToolItemWidth || Cy < UI.ToolBarHeight || Cy >= UI.height - UI.StatusBarHeight - (UI.AND2_Height / 2));
}

// HERE REMAINS THE CODE TO CUT THE CONNECTIONS TO A CERTAIN GATE.

void CUTPASTE_OP::Execute()
{
	// This is not really used here. But it is for consistent code.
	int index, x, y;
	OutputInterface->PrintMsg("CLICK TO CUT A COMPONENT!");

	p->GetInput()->GetPointClicked(x, y);
	Component* TO_CUT = p->DetectComponent(x, y, index, "gfx");
	if (TO_CUT == NULL) {
		OutputInterface->PrintMsg("Unvaild Component Area. Click On a component to cut, or another unvaild click to exit cutting mode.");

		p->GetInput()->GetPointClicked(x, y);
		TO_CUT = p->DetectComponent(x, y, index, "gfx");
		if (TO_CUT == NULL) {
			OutputInterface->PrintMsg("Exited Cutting mode.");
			return;
		}
		else {
			string label = TO_CUT->GetLabel();
			TO_CUT->SetLabel("");
			pManager->UpdateInterface();

			pManager->RemoveConnections(TO_CUT);
			OutputInterface->ClearComponentArea(TO_CUT->GetGraphicsInfo());

			TO_CUT->SetLabel(label);
			CUTTING_LOOP(TO_CUT);
		}
	}
	else {
		string label = TO_CUT->GetLabel();
		TO_CUT->SetLabel("");
		pManager->UpdateInterface();

		pManager->RemoveConnections(TO_CUT);
		OutputInterface->ClearComponentArea(TO_CUT->GetGraphicsInfo());

		TO_CUT->SetLabel(label);

		// DISCONNECTING FROM ALL COMPONENTS.
		TO_CUT->disconnect_from_all();
		CUTTING_LOOP(TO_CUT);
		
	}
	OutputInterface->ClearStatusBar();
}

void CUTPASTE_OP::Undo()
{
	
}

void CUTPASTE_OP::Redo()
{}
