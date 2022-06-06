#include "..\ApplicationManager.h"
#include "AddConnection.h"

AddConnection::AddConnection(ApplicationManager* pApp, Component* gate1, Component* gate2) :Action(pApp)
{
	gate_1 = gate1;
	gate_2 = gate2;
}

AddConnection::~AddConnection(void)
{
}
void AddConnection::Execute()
{
	Output* p = pManager->GetOutput();

	Connection* cA = new Connection(p, gate_1, gate_2);
	pManager->AddComponent(cA);

}

void AddConnection::ReadActionParameters()
{
}

void AddConnection::Undo()
{
}

void AddConnection::Redo()
{
}