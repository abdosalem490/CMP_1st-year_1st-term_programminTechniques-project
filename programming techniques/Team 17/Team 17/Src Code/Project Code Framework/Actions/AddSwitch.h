#ifndef _ADD_SWITCH_H
#define _ADD_SWITCH_H

#include "Action.h"
#include "..\Components\Switch.h"

class AddSwitch : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	GraphicsInfo GInfo;
	Input* pIn;
	Output* pOut;
	bool selected;
	int index;
public:
	AddSwitch(ApplicationManager* pApp, bool select = false);

	virtual ~AddSwitch(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	int getIndex();
	virtual void Undo();
	virtual void Redo();


};


#endif