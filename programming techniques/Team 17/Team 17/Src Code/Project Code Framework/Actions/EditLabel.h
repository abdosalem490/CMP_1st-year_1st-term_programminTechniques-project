#ifndef _EDIT_LABEL_H
#define _EDIT_LABEL_H

#include "action.h"
#include "..\Components\Component.h"


class EDITLABEL_OP : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int x, y;	//Center point of the gate
	Component* to_label;
public:
	EDITLABEL_OP(ApplicationManager* pApp);
	virtual ~EDITLABEL_OP(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif