#include "AddSwitch.h"
#include "..\ApplicationManager.h"

AddSwitch::AddSwitch(ApplicationManager* pApp, bool select) :Action(pApp)
{
	selected = select;
	this->index = index;
}

AddSwitch::~AddSwitch(void)
{

}

void AddSwitch::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMsg("Switch: Click somewhere empty to add the gate");
	pIn->GetPointClicked(Cx, Cy);
	pOut->ClearStatusBar();


}

void AddSwitch::Execute()
{
	//Get Center point of the Gate
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	GraphicsInfo GInfo;

	// trash variable for calling the function DetectComponent.
	int index = 0;
	Switch* pA = NULL;

	do {
		ReadActionParameters();
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		pA = new Switch(GInfo, AND2_FANOUT);
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

int AddSwitch::getIndex()
{
	return index;
}

void AddSwitch::Undo()
{

}

void AddSwitch::Redo()
{

}