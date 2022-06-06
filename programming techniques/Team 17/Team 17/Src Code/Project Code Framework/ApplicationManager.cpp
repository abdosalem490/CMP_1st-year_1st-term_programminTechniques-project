#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddINVERTERgate.h"
#include "Actions\AddBUFFER.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddANDgate3.h"
#include "Actions\UNDO_OP.h"
#include "Actions\REDO_OP.h"
#include "Actions\DELETE_OP.h"
#include "Actions\SELECT_OP.h"
#include "Actions\CUTANDPASTE_OP.h"
#include "Actions\COPYANDPASTE_OP.h"
#include "Actions\EditLabel.h"
#include "Actions\SAVE_OP.h"
#include "Actions\LOAD_OP.h"
#include "Actions\AddConnection.h"
#include"Actions\AddSwitch.h"
#include "Actions\AddLed.h"
#include "Actions\simulate.h"
#include <string>

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ActionCount = 0;
	ActionCount_Redo = 0;
	CompCount_Redo = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;

	// Giving IDs to all components except connections.
	if (dynamic_cast <Connection*>(pComp)) {
	}
	else {
		pComp->SetID(CompCount);
	}
}

void ApplicationManager::SelectComponent(int x, int y, int& index)
{
	Component *selectedComp = DetectComponent(x, y, index, "gfx");
	if (selectedComp != NULL && dynamic_cast<Switch*>(selectedComp)) {

		selectedComp->SetSelected(!(selectedComp->GetSelected()));
	}
	else {
			
		OutputInterface->PrintMsg(" NULL!");
	}
	
}

int ApplicationManager::GetCompCount() const {
	return CompCount;
}

Component** ApplicationManager::GetComponentList() {
	return CompList;
}

void ApplicationManager::RemoveConnections(Component* gate) {

	// not used
	int x = 0;

	// Removing any connection that the gate exists in as a source gate.
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < CompCount; i++) {
			if (dynamic_cast<Connection*>(CompList[i]))
				if (dynamic_cast<Connection*>(CompList[i])->GetGate1() == gate) {
					RemoveSpecifiedComponent(CompList[i], i);
					OutputInterface->ClearDrawingArea();
					UpdateInterface();
				}
		}
	}
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < CompCount; i++) {
			if (dynamic_cast<Connection*>(CompList[i]))
				if (dynamic_cast<Connection*>(CompList[i])->GetGate2() == gate) {
					RemoveSpecifiedComponent(CompList[i], i);

					if (dynamic_cast<Connection*>(CompList[i])->GetGate1() != NULL) {
						dynamic_cast<Connection*>(CompList[i])->GetGate1()->Fanout_dec();
					}

				}
		}
	}
	// Unconnect the gates connected to it.
	for (int i = 0; i < CompCount; i++) {
		if (dynamic_cast<Gate*>(CompList[i])) {

			// Sets the pins of all the connected gates (as destination gates) to the removed gate to NULL.

			if (CompList[i]->GetGate12() == gate) {
				CompList[i]->SetGate12();
				CompList[i]->setINputPin_1_Unreserved();

				if (dynamic_cast<Led*>(CompList[i])) {
					dynamic_cast<Led*>(CompList[i])->SetSelected(false);
				}
			}

			if (CompList[i]->GetGate22() == gate) {
				CompList[i]->SetGate22();
				CompList[i]->setINputPin_2_Unreserved();
			}

			if (CompList[i]->GetGate33() == gate) {
				CompList[i]->SetGate33();
				CompList[i]->setINputPin_3_Unreserved();
			}
		}
	}
	return;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::RemoveLastComponent()
{
	if (CompCount != 0) {
		
		// Clearing the component from the drawing area.
		OutputInterface->ClearDrawingArea();

		// Storing the component in a list for Redo operation.
		RedoList[CompCount_Redo++] = CompList[CompCount - 1];

		// Removing the components from the list of components.
		CompList[CompCount - 1] = NULL;
		CompCount--;

		// Notifying the user that the operation is undone:
		// OutputInterface->PrintMsg("Last Operation undone.");

		
	}
	else {
		// OutputInterface->PrintMsg("All operations already undone.");
	}
}

// FOR DELETE OPERATION
void ApplicationManager::RemoveSpecifiedComponent(Component *to_delete, int index) {

		// Clearing the component from the drawing area.
	if (dynamic_cast<Connection*>(to_delete) != NULL) {

		// Removing the components from the list of components.
		if (index == CompCount - 1) {
			to_delete = NULL;
			CompCount--;
		} else {
			for (int k = index; k < CompCount - 1; k++)
				CompList[k] = CompList[k + 1];
			CompCount--;
		}
		UpdateInterface();

	}
	else {
		OutputInterface->ClearComponentArea(to_delete->GetGraphicsInfo());

		// Removing the components from the list of components.
		if (index == CompCount - 1) {
			to_delete = NULL;
			CompCount--;
		}
		else {
			for (int k = index; k < CompCount - 1; k++)
				CompList[k] = CompList[k + 1];
			CompCount--;
		}
	}
		

}

Action** ApplicationManager::GetActionList_Redo(int& n) {


	if (ActionCount_Redo == 0) {
		n = ActionCount_Redo;
	}
	else {
		n = ActionCount_Redo;
		ActionCount_Redo--;
	}
	return ActionList_Redo;
}

Action** ApplicationManager::GetActionList(int& n) {


	if (ActionCount == 0) {
		n = ActionCount;
	}
	else {
		n = ActionCount;
		ActionCount--;
	}
	return ActionList;
}

void ApplicationManager::AddToRedoActionList(Action *TO_ADD) {

	ActionList_Redo[ActionCount_Redo++] = TO_ADD;

}

void ApplicationManager::AddToActionList(Action *TO_ADD) {

	ActionList[ActionCount++] = TO_ADD;

}

Component *ApplicationManager::DetectComponent(int x, int y, int &index, string by, int id) const {
	
	if (by == "gfx") {
		for (int i = 0; i < CompCount; i++) {
			int x1 = CompList[i]->GetGraphicsInfo().x1;
			int x2 = CompList[i]->GetGraphicsInfo().x2;
			int y1 = CompList[i]->GetGraphicsInfo().y1;
			int y2 = CompList[i]->GetGraphicsInfo().y2;

			if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
				index = i;
				return CompList[i];
			}
		}
	} else if (by == "id") {
		for (int i = 0; i < CompCount; i++)
			if (CompList[i]->GetID() == id)
				return CompList[i];
	}

	
	return NULL;

}

////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(OutputInterface);
}
////////////////////////////////////////////////////////////////////

Component* ApplicationManager::GetGate(int i)
{
	Component* gate2;
	Component* gate1;
	int x, y , z;

	if (i == 0)
	{
		OutputInterface->PrintMsg("Please select the source gate.");
		InputInterface->GetPointClicked(x, y);
		gate1 = DetectComponent(x, y , z, "gfx");
		if (gate1 != NULL)
		{
			return gate1;
		}
		else {
			return NULL;
		}
	}
	if (i == 1)
	{

		OutputInterface->PrintMsg("Please select the destination gate.");
		InputInterface->GetPointClicked(x, y);
		gate2 = DetectComponent(x, y ,z, "gfx");
		if (gate2 != NULL)
		{
			OutputInterface->ClearStatusBar();
			return gate2;
		}
		else {
			return NULL;
		}
	}
	OutputInterface->ClearStatusBar();
}

void ApplicationManager::Simulate()
{
	for (size_t i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getindex() == 5)
		{
			CompList[i]->Operate();
		}
	}
}

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;

		case ADD_INV:
			pAct = new AddINVERTERgate(this);
			break;

		case ADD_BUFF:
			pAct = new AddBUFFERgate(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;

		case UNDO:
			pAct = new UNDO_OP(this);
			break;

		case REDO:
			pAct = new REDO_OP(this);
			break;

		case DEL:
			pAct = new DELETE_OP(this);
			break;

		case SELECT:
			pAct = new SELECT_OP(this);
			break;

		case ADD_CONNECTION:
			Component* c[2];
			c[0] = GetGate(0);
			c[1] = GetGate(1);
			if (c[0] != NULL && c[1] != NULL)
			{
				if (dynamic_cast<Switch*>(c[1])) 
					OutputInterface->PrintMsg("You cannot add switch as a destination component.");
				else
					pAct = new AddConnection(this, c[0], c[1]);
			}
			break;

		case ADD_Switch:
			pAct = new AddSwitch(this, true);
		 	break;

	    case ADD_LED:
			pAct = new AddLed(this);
			break;

		case CUT:
			pAct = new CUTPASTE_OP(this);
			break;

		case SIM_MODE:
		{
			pAct = new simulate(this);
		}
		break;

		case COPY:
			pAct = new COPYPASTE_OP(this);
			break;

		case EDIT_Label:
			pAct = new EDITLABEL_OP(this);
			break;

		case SAVE:
			pAct = new SAVE_OP(this);
			break;
		
		case LOAD:
			pAct = new LOAD_OP(this);
			break;
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();



		// CHECK HERE IF THE ACTION IS UNDO OR REDO, IF SO, DO NOT ADD THEM.
		if (dynamic_cast<UNDO_OP*>(pAct) != 0 || dynamic_cast<REDO_OP*>(pAct) != 0 
			|| dynamic_cast<SAVE_OP*>(pAct) != 0 || dynamic_cast<LOAD_OP*>(pAct) != 0) {
			// NOT ADDING THEM TO THE LIST OF ACTIONS.
		}
		else {
			ActionList[ActionCount++] = pAct;
		}

		
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
	OutputInterface->getWin()->SetPen(BLACK, 1);
	
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->Draw(OutputInterface, CompList[i]->GetSelected());
		OutputInterface->getWin()->DrawString(CompList[i]->GetGraphicsInfo().x1, CompList[i]->GetGraphicsInfo().y1 - 25, CompList[i]->GetLabel());
	}
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}