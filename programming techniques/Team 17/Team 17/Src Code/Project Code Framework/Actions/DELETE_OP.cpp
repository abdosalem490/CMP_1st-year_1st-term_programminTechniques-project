#include "DELETE_OP.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"

DELETE_OP::DELETE_OP(ApplicationManager* pApp) :Action(pApp)
{
	p = pApp;
	OutputInterface = p->GetOutput();
}

DELETE_OP::~DELETE_OP(void)
{
}

void DELETE_OP::ReadActionParameters()
{

}

void DELETE_OP::Execute()
{
	OutputInterface->PrintMsg("Click on a component to delete.");
	window *pWind = OutputInterface->getWin();
	
	int x, y;
	int index;
	pWind->WaitMouseClick(x, y);

	TO_DELETE = p->DetectComponent(x, y, index, "gfx");
	if (TO_DELETE != NULL) {
		OutputInterface->PrintMsg("Deleting component. Exiting Deleting Mode.");
		pManager->RemoveConnections(TO_DELETE);
		TO_DELETE->disconnect_from_all();
		p->RemoveSpecifiedComponent(TO_DELETE, index);
	}
	else {
		OutputInterface->PrintMsg("Please click on a vaild location of a component. Exited Deleting Mode.");
	}
}

void DELETE_OP::Undo()
{
	p->AddComponent(TO_DELETE);
}

void DELETE_OP::Redo()
{
	p->RemoveLastComponent();
}
