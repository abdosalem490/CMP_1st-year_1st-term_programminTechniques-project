#ifndef _LOAD_OP_H
#define _LOAD_OP_H

#include "action.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>

class LOAD_OP : public Action
{
private:

	ApplicationManager* pManager;
	ifstream circuit_to_load;
	const string WHITESPACE = " \n\r\t\f\v";

public:
	LOAD_OP(ApplicationManager* pApp);
	virtual ~LOAD_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif