#include "SELECT_OP.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"


SELECT_OP::SELECT_OP(ApplicationManager* pApp) :Action(pApp)
{
	p = pApp;
	OutputInterface = p->GetOutput();
}

SELECT_OP::~SELECT_OP(void)
{
}

void SELECT_OP::ReadActionParameters()
{

}

void SELECT_OP::Execute()
{
	int index, x, y;
	OutputInterface->PrintMsg("Click to turn a switch on/off.");

	p->GetInput()->GetPointClicked(x, y);
	if (y < UI.ToolBarHeight || x > UI.width - UI.ToolItemWidth) {
	}
	else {
		p->SelectComponent(x, y, index);
	}
	OutputInterface->ClearStatusBar();
}

void SELECT_OP::Undo()
{}

void SELECT_OP::Redo()
{}
