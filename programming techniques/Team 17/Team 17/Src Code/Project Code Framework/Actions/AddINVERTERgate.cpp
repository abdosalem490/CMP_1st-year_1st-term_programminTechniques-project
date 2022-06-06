#include "AddINVERTERgate.h"
#include "..\ApplicationManager.h"

AddINVERTERgate::AddINVERTERgate(ApplicationManager* pApp) :Action(pApp)
{
}

AddINVERTERgate::~AddINVERTERgate(void)
{
}

void AddINVERTERgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input Inverter Gate: Click Somewhere empty to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	while (Cx > UI.width - UI.ToolItemWidth || Cy <= UI.ToolBarHeight + (UI.AND2_Height / 2) || Cy >= UI.height - UI.StatusBarHeight - (UI.AND2_Height / 2)) {
		pOut->PrintMsg("Click somewhere valid.");
		pIn->GetPointClicked(Cx, Cy);
	}


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddINVERTERgate::Execute()
{
	//Get Center point of the Gate
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	GraphicsInfo GInfo;

	// trash variable for calling the function DetectComponent.
	int index = 0;
	INVERTER* pA = NULL;

	do {
		ReadActionParameters();
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		pA = new INVERTER(GInfo, AND2_FANOUT);
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

void AddINVERTERgate::Undo()
{
	pManager->RemoveLastComponent();
}

void AddINVERTERgate::Redo()
{
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the INVERTER gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	INVERTER* pA = new INVERTER(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

