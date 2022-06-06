#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200,
		MaxActionCount = 200
	};	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	int CompCount_Redo;

	// FOR UNDO
	int ActionCount;
	Action* ActionList[MaxActionCount];

	// FOR REDO
	int ActionCount_Redo;
	Component* RedoList[MaxCompCount];
	Action* ActionList_Redo[MaxActionCount];


	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void AddToRedoActionList(Action* TO_ADD);
	void AddToActionList(Action* TO_ADD);


	// Removes the last component, function for undo operation
	void RemoveLastComponent();

	// Removes a specified component for delete operation
	void RemoveSpecifiedComponent(Component* to_delete, int index);

	void RemoveConnections(Component* gate);

	// Returns the redo list of component for REDO operation and class.
	Action** GetActionList_Redo(int &n);

	Action** GetActionList(int &n);

	Component* DetectComponent(int x, int y, int &index, string by, int id = 0) const;
	void SelectComponent(int x, int y, int& index);


	// For loading and saving
	int GetCompCount() const;
	Component** GetComponentList();

	Component* GetGate(int i);
	void Simulate();

	//destructor
	~ApplicationManager();
};

#endif