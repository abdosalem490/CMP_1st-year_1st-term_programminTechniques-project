#include "COPYANDPASTE_OP.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Gate.h"
#include "..\Components\AND2.h"
#include "..\Components\AND3.h"
#include "..\Components\OR2.h"
#include "..\Components\NOR2.h"
#include "..\Components\NOR3.h"
#include "..\Components\XOR2.h"
#include "..\Components\XNOR2.h"
#include "..\Components\XOR3.h"
#include "..\Components\BUFFER.h"
#include "..\Components\INVERTER.h"
#include "..\Components\NAND2.h"
#include "..\Components\AND2.h"
#include "..\Components\Led.h"
#include "..\Components\Switch.h"
#include "..\Components\BUFFER.h"
#include "..\Components\Connection.h"
#include <string>


COPYPASTE_OP::COPYPASTE_OP(ApplicationManager* pApp) :Action(pApp)
{
	p = pApp;
	OutputInterface = p->GetOutput();
}

COPYPASTE_OP::~COPYPASTE_OP(void)
{
}

void COPYPASTE_OP::ReadActionParameters()
{

}

void COPYPASTE_OP::COPYING_LOOP(Component *TO_COPY) {

	int Cx, Cy;
	do {
		OutputInterface->PrintMsg("COPIED. Click anywhere VALID in the drawing area to paste.");
		p->GetInput()->GetPointClicked(Cx, Cy);

		if (Cx > UI.width - UI.ToolItemWidth || Cy < UI.ToolBarHeight || Cy >= UI.height - UI.StatusBarHeight - (UI.AND2_Height / 2)) {
		}
		else {

			Component* TO_PASTE;
			GraphicsInfo new_gfx;
			new_gfx.x1 = Cx - UI.AND2_Width / 2;
			new_gfx.x2 = Cx + UI.AND2_Width / 2;
			new_gfx.y1 = Cy - UI.AND2_Height / 2;
			new_gfx.y2 = Cy + UI.AND2_Height / 2;

			string name = TO_COPY->name().substr(6, string::npos);

			if (name == "AND2")
				TO_PASTE = new AND2(new_gfx, AND2_FANOUT);

			else if (name == "AND3")
				TO_PASTE = new AND3(new_gfx, AND2_FANOUT);

			else if (name == "OR2")
				TO_PASTE = new OR2(new_gfx, AND2_FANOUT);

			else if (name == "INVERTER")
				TO_PASTE = new INVERTER(new_gfx, AND2_FANOUT);

			else if (name == "BUFFER")
				TO_PASTE = new BUFFER(new_gfx, AND2_FANOUT);

			else if (name == "XOR2")
				TO_PASTE = new XOR2(new_gfx, AND2_FANOUT);

			else if (name == "XOR3")
				TO_PASTE = new XOR3(new_gfx, AND2_FANOUT);

			else if (name == "NAND2")
				TO_PASTE = new NAND2(new_gfx, AND2_FANOUT);

			else if (name == "NOR2")
				TO_PASTE = new NOR2(new_gfx, AND2_FANOUT);

			else if (name == "NOR3")
				TO_PASTE = new NOR3(new_gfx, AND2_FANOUT);

			else if (name == "Switch")
				TO_PASTE = new Switch(new_gfx, AND2_FANOUT);

			else if (name == "XNOR2")
				TO_PASTE = new XNOR2(new_gfx, AND2_FANOUT);

			else if (name == "Led")
				TO_PASTE = new Led(new_gfx, AND2_FANOUT);
			
			string label = TO_COPY->GetLabel();
			TO_PASTE->SetGraphicsInfo(new_gfx);
			TO_PASTE->SetLabel(label);
			dynamic_cast<Gate*>(TO_PASTE)->disconnect_from_all();

			p->AddComponent(TO_PASTE);

		}
	} while (Cx > UI.width - UI.ToolItemWidth || Cy < UI.ToolBarHeight || Cy >= UI.height - UI.StatusBarHeight - (UI.AND2_Height / 2));
}

// HERE REMAINS THE CODE TO CUT THE CONNECTIONS TO A CERTAIN GATE.

void COPYPASTE_OP::Execute()
{

	// This is not really used here. But it is for consistent code.
	int index, x, y;
	OutputInterface->PrintMsg("CLICK TO COPY A COMPONENT!");

	p->GetInput()->GetPointClicked(x, y);
	Component* TO_COPY = p->DetectComponent(x, y, index, "gfx");
	if (TO_COPY == NULL) {
		OutputInterface->PrintMsg("Unvaild Component Area. Click On a component to copy, or another unvaild click to exit copying mode.");
		
		p->GetInput()->GetPointClicked(x, y);
		TO_COPY = p->DetectComponent(x, y, index, "gfx");
		if (TO_COPY == NULL) {
			OutputInterface->PrintMsg("Exited Copying mode.");
			return;
		}
		else {
			COPYING_LOOP(TO_COPY);
		}
	}
	else {

		COPYING_LOOP(TO_COPY);
	}
	OutputInterface->ClearStatusBar();
}

void COPYPASTE_OP::Undo()
{
	
}

void COPYPASTE_OP::Redo()
{}
