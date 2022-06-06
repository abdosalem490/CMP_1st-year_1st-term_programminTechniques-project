#include "LOAD_OP.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
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
#include <sstream>

LOAD_OP::LOAD_OP(ApplicationManager* pApp) :Action(pApp)
{
	pManager = pApp;
}

LOAD_OP::~LOAD_OP(void)
{
}

void LOAD_OP::ReadActionParameters()
{

}

void LOAD_OP::Execute()
{
	pManager->GetOutput()->PrintMsg("Enter the name of the file to load the circuit from: ");
	string filename = pManager->GetInput()->GetSrting(pManager->GetOutput(), "Enter the name of the file to load the circuit from: ");

	circuit_to_load.open(filename);
	pManager->GetOutput()->ClearStatusBar();

	string name, l, label, id_stream, x_stream, y_stream, start_of_the_line;
	int ID, x, y;

	if (circuit_to_load.is_open()) {

		// Clearing and deleting all components.
		for (int i = pManager->GetCompCount() - 1; i >= 0; i--)
			pManager->RemoveLastComponent();

		// ignoring the first two lines.
		for (int i = 0; i < 2; i++)
			getline(circuit_to_load, l);

		l = "";
		Component* to_ADD;

		while (getline(circuit_to_load, l)) {

			if (l == "-1") break;

			if (l != "") {

				if (l.substr(0, l.find_last_not_of(WHITESPACE) + 1) != "CONNECTIONS") {

					name = l.substr(0, l.find_first_of(WHITESPACE));

					l = l.substr(name.length() + 1, string::npos);

					id_stream = l.substr(0, l.find_first_of(WHITESPACE));

					stringstream id(id_stream);
					id >> ID;

					l = l.substr(id_stream.length() + 1, string::npos);

					label = l.substr(0, l.find_first_of(WHITESPACE));

					l = l.substr(label.length() + 1, string::npos);

					if (label == "#NO_LABEL") label = "";

					x_stream = l.substr(0, l.find_first_of(WHITESPACE));
					stringstream X(x_stream);
					X >> x;

					l = l.substr(x_stream.length() + 1, string::npos);

					y_stream = l.substr(0, string::npos);
					stringstream Y(y_stream);
					Y >> y;

					GraphicsInfo Gfx;
					Gfx.x1 = x;
					Gfx.y1 = y;
					Gfx.x2 = x + UI.AND2_Width;
					Gfx.y2 = y + UI.AND2_Height;

					if (name == "AND2")
						to_ADD = new AND2(Gfx, AND2_FANOUT);

					else if (name == "OR2")
						to_ADD = new OR2(Gfx, AND2_FANOUT);

					else if (name == "AND3")
						to_ADD = new AND3(Gfx, AND2_FANOUT);

					else if (name == "INVERTER")
						to_ADD = new INVERTER(Gfx, AND2_FANOUT);

					else if (name == "BUFFER")
						to_ADD = new BUFFER(Gfx, AND2_FANOUT);

					else if (name == "NOR2")
						to_ADD = new NOR2(Gfx, AND2_FANOUT);

					else if (name == "NOR3")
						to_ADD = new NOR3(Gfx, AND2_FANOUT);

					else if (name == "XOR2")
						to_ADD = new XOR2(Gfx, AND2_FANOUT);

					else if (name == "BUFFER")
						to_ADD = new BUFFER(Gfx, AND2_FANOUT);

					else if (name == "XOR3")
						to_ADD = new XOR3(Gfx, AND2_FANOUT);

					else if (name == "XNOR2")
						to_ADD = new XNOR2(Gfx, AND2_FANOUT);

					else if (name == "NAND2")
						to_ADD = new NAND2(Gfx, AND2_FANOUT);

					else if (name == "Led")
						to_ADD = new Led(Gfx, AND2_FANOUT);

					else if (name == "Switch")
						to_ADD = new Switch(Gfx, AND2_FANOUT);

					to_ADD->SetLabel(label);
					to_ADD->SetGraphicsInfo(Gfx);
					pManager->AddComponent(to_ADD);
					to_ADD->SetID(ID);

				}
				else
					break;
			}
		}

		int id1, id2, pin;
		string id1stream, id2stream;
		while (getline(circuit_to_load, l)) {

			if (l == "-1") break;

			if (l != "") {

				id1stream = l.substr(0, l.find_first_of(WHITESPACE));
				stringstream i1(id1stream);
				i1 >> id1;

				l = l.substr(id1stream.length() + 1, string::npos);

				id2stream = l.substr(0, l.find_first_of(WHITESPACE));
				stringstream i2(id2stream);
				i2 >> id2;

				l = l.substr(id1stream.length() + 1, string::npos);

				l = l.substr(0, l.find_last_not_of(WHITESPACE) + 1);
				stringstream p(l);
				p >> pin;

				// this is not used, it's just for storing a value of a referenced parameter.
				int trash;
				
				to_ADD = new Connection(pManager->GetOutput(), pManager->DetectComponent(0, 0, trash, "id", id1), pManager->DetectComponent(0,0, trash, "id", id2));
				pManager->AddComponent(to_ADD);
				pManager->DetectComponent(0, 0, trash, "id", id2)->connectTo(pManager->DetectComponent(0, 0, trash, "id", id1), pin - 1);
			}

		}


		// pManager->UpdateInterface();
	}
	else
		pManager->GetOutput()->PrintMsg("Unable to open file of the name: " + filename);

}

void LOAD_OP::Undo()
{}

void LOAD_OP::Redo()
{}
