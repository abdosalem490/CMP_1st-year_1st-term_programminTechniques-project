#ifndef _SELECT_OP_H
#define _SELECT_OP_H

#include "action.h"
#include "..\GUI\Output.h"

class SELECT_OP : public Action
{
private:
	ApplicationManager* p;
	Output* OutputInterface;

public:

	SELECT_OP(ApplicationManager* pApp);
	virtual ~SELECT_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif