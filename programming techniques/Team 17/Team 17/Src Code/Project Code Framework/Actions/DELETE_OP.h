#ifndef _DELETE_OP_H
#define _DELETE_OP_H

#include "action.h"
#include "..\GUI\Output.h"
#include "..\Components\Component.h"

class DELETE_OP : public Action
{
private:

	ApplicationManager* p;
	Output* OutputInterface;
	Component* TO_DELETE = NULL;
	int x;


public:
	DELETE_OP(ApplicationManager* pApp);
	virtual ~DELETE_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif