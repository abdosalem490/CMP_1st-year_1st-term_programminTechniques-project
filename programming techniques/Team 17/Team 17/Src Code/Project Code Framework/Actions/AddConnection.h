#ifndef _ADD_Connection_H
#define _ADD_Connection_H


#include "Action.h"
#include "..\Components\Connection.h"

class AddConnection : public  Action
{
private:
	GraphicsInfo gr;
	int x, pin;
	Component* gate_1, * gate_2;
public:

	AddConnection(ApplicationManager* pApp, Component* gate1, Component* gate2);
	~AddConnection(void);
	virtual void Undo();
	virtual void Redo();
	virtual void Execute();
	virtual void ReadActionParameters();
};



#endif 