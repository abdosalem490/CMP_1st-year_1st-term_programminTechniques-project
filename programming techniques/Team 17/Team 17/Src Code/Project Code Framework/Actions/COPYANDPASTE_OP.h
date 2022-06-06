#ifndef _COPYPASTE_OP_H
#define _COPYPASTE_OP_H

#include "action.h"
#include "..\GUI\Output.h"
#include "..\Components\Component.h"

class COPYPASTE_OP : public Action
{
private:

	ApplicationManager* p;
	Output* OutputInterface;

public:
	COPYPASTE_OP(ApplicationManager* pApp);
	virtual ~COPYPASTE_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	void COPYING_LOOP(Component* TO_COPY);

	virtual void Undo();
	virtual void Redo();


};

#endif