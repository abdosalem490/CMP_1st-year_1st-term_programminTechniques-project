#ifndef _REDO_OP_H
#define _REDO_OP_H

#include "action.h"
#include "..\GUI\Output.h"

class REDO_OP : public Action
{
private:

	ApplicationManager* p;
	int RedoCount;

public:
	REDO_OP(ApplicationManager* pApp);
	virtual ~REDO_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif