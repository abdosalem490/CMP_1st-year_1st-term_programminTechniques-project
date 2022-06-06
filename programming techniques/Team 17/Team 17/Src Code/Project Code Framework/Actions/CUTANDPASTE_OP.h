#ifndef _CUTPASTE_OP_H
#define _CUTPASTE_OP_H

#include "action.h"
#include "..\GUI\Output.h"
#include "..\Components\Component.h"


class CUTPASTE_OP : public Action
{
private:

	ApplicationManager* p;
	Output* OutputInterface;

public:
	CUTPASTE_OP(ApplicationManager* pApp);
	virtual ~CUTPASTE_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	void CUTTING_LOOP(Component* TO_CUT);

	virtual void Undo();
	virtual void Redo();


};

#endif