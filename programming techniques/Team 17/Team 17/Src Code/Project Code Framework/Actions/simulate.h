#ifndef _SIMULATE_OP_H
#define _SIMULATE_OP_H

#include "Action.h"
#include "..\GUI\Output.h"

class simulate : public Action
{
private:
	ApplicationManager* p;
	Output* OutputInterface;

public:

	simulate(ApplicationManager* pApp);
	virtual ~simulate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif