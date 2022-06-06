#include "EditLabel.h"
#include "..\ApplicationManager.h"

EDITLABEL_OP::EDITLABEL_OP(ApplicationManager* pApp) :Action(pApp)
{
}

EDITLABEL_OP::~EDITLABEL_OP(void)
{
}

void EDITLABEL_OP::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();

	pIn->GetPointClicked(x, y);

}

void EDITLABEL_OP::Execute()
{
	
	pManager->GetOutput()->PrintMsg("Click on a component to add or edit its label.");
	
	//Get Center point of the Gate
	ReadActionParameters();

	int index;


	
	to_label = pManager->DetectComponent(x, y, index, "gfx");

	while (to_label == NULL) {

		pManager->GetOutput()->PrintMsg("Click on a valid component to label.");

		ReadActionParameters();

		to_label = pManager->DetectComponent(x, y, index, "gfx");
	}

	pManager->GetOutput()->PrintMsg("Enter Label (Maximum two characters), press escape to exit:");
	string label = pManager->GetInput()->GetSrting(pManager->GetOutput(), "Enter Label (Maximum two characters), press escape to exit:");
	
	if (label == "") {
		to_label->SetLabel("");
	}
	else {
		label = label.substr(0, 2);
		to_label->SetLabel(label);
	}
	pManager->GetOutput()->ClearStatusBar();
}

void EDITLABEL_OP::Undo()
{

}

void EDITLABEL_OP::Redo()
{
	
}

