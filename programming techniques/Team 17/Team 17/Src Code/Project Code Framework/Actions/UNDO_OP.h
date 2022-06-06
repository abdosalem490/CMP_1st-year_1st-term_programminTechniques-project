#ifndef _UNDO_OP_H
#define _UNDO_OP_H

#include "action.h"

class UNDO_OP : public Action
{
private:
	
	ApplicationManager* p;

public:
	UNDO_OP(ApplicationManager* pApp);
	virtual ~UNDO_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif