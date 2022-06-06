#include "SAVE_OP.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
#include "..\Components\Gate.h"

SAVE_OP::SAVE_OP(ApplicationManager* pApp) :Action(pApp)
{
	pManager = pApp;
}


SAVE_OP::~SAVE_OP(void)
{
}

void SAVE_OP::ReadActionParameters()
{

}

int SAVE_OP::sudo() const {
	return 1;
}


void SAVE_OP::Execute()
{

	pManager->GetOutput()->PrintMsg("Enter the name of the file to save the circuit into: ");
	string filename = pManager->GetInput()->GetSrting(pManager->GetOutput(), "Enter the name of the file to save the circuit into: ");
	filename += ".txt";


	circuit_to_save.open(filename);

	Component* to_save;
	string name;

	if (circuit_to_save.is_open()) {

		circuit_to_save << pManager->GetCompCount() << "\n\n";
		for (int i = 0; i < pManager->GetCompCount(); i++) {

			to_save = pManager->GetComponentList()[i];

			name = to_save->name().substr(6, string::npos);

			if (name != "Connection") {

				circuit_to_save << name << "\t";

				// ADD WHEN ALL CODE IS COMPLETE
				circuit_to_save << to_save->GetID() << "\t";

				if (to_save->GetLabel() == "")
					circuit_to_save << "#NO_LABEL" << "\t";

				else
					circuit_to_save << to_save->GetLabel() << "\t";

				circuit_to_save << to_save->GetGraphicsInfo().x1 << "\t" << to_save->GetGraphicsInfo().y1;
				circuit_to_save << "\n\n";
			}
		}

		circuit_to_save << "CONNECTIONS" << "\n";

		for (int i = 0; i < pManager->GetCompCount(); i++) {

			to_save = pManager->GetComponentList()[i];
			name = to_save->name().substr(6, string::npos);

			if (name == "Connection") {
				circuit_to_save << ((Connection*)to_save)->GetGate1()->GetID() << "\t";
				circuit_to_save << ((Connection*)to_save)->GetGate2()->GetID() << "\t";
				


				if (((Connection*)to_save)->GetX() == 0)
					circuit_to_save << 1 << "\t";
				else if (((Connection*)to_save)->GetX() == 1)
					circuit_to_save << 2 << "\t";
				else if (((Connection*)to_save)->GetX() == 2)
					circuit_to_save << 3 << "\t";
				circuit_to_save << "\n";
			}
			
		}
		circuit_to_save << "\n-1";
		circuit_to_save.close();
		pManager->GetOutput()->PrintMsg("Saved circuit with name: " + filename);

	}
	else {
		pManager->GetOutput()->PrintMsg("Unable to open file of the name: " + filename);
	}
}
void SAVE_OP::Undo()
{}

void SAVE_OP::Redo()
{}
