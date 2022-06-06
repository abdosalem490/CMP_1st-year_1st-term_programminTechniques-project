#ifndef _SAVE_OP_H
#define _SAVE_OP_H

#include "action.h"
#include "..\GUI\Output.h"

#include <fstream>

#include <algorithm>


#include <iostream>
#include <conio.h>
#include <windows.h>


class SAVE_OP : public Action
{
private:

	ApplicationManager* pManager;
	ofstream circuit_to_save;
	const string WHITESPACE = " \n\r\t\f\v";

public:
	SAVE_OP(ApplicationManager* pApp);
	virtual ~SAVE_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	int sudo() const;


	virtual void Undo();
	virtual void Redo();

};

#endif