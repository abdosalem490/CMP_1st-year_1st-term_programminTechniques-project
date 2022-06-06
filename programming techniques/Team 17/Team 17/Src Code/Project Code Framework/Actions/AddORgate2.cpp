#include "AddORgate2.h"
#include "..\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click somewhere empty to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	while (Cx > UI.width - UI.ToolItemWidth || Cy <= UI.ToolBarHeight + (UI.AND2_Height / 2) || Cy >= UI.height - UI.StatusBarHeight - (UI.AND2_Height / 2)) {
		pOut->PrintMsg("Click somewhere valid.");
		pIn->GetPointClicked(Cx, Cy);
	}

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	GraphicsInfo GInfo;

	// trash variable for calling the function DetectComponent.
	int index = 0;
	OR2* pA = NULL;

	do {
		ReadActionParameters();
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		pA = new OR2(GInfo, AND2_FANOUT);
	} while (pManager->DetectComponent(Cx, Cy, index, "gfx") != NULL);


	pManager->AddComponent(pA);

	pManager->UpdateInterface();

	// Labeling

	pManager->GetOutput()->PrintMsg("Enter Label (Maximum two characters), press escape to exit:");
	string label = pManager->GetInput()->GetSrting(pManager->GetOutput(), "Enter Label (Maximum two characters), press escape to exit:");
	if (label == "") {
	}
	else {
		label = label.substr(0, 2);
		pA->SetLabel(label);
	}
	pManager->GetOutput()->ClearStatusBar();
}

void AddORgate2::Undo()
{
	pManager->RemoveLastComponent();
}

void AddORgate2::Redo()
{
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the OR2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	OR2* pA = new OR2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

