#include "simulate.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"


simulate::simulate(ApplicationManager* pApp) :Action(pApp)
{
	p = pApp;
	OutputInterface = p->GetOutput();
}

simulate::~simulate(void)
{
}

void simulate::ReadActionParameters()
{

}

void simulate::Execute()
{
	p->GetOutput()->PrintMsg("Simulated, and switched to simulation mode.");
	p->Simulate();
}

void simulate::Undo()
{}

void simulate::Redo()
{}
