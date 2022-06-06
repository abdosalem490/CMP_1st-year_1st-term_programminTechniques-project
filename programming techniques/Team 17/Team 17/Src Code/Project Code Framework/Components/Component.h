#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
	int ID;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool selected = false;
public:
	Component(const GraphicsInfo& r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool selected = false) = 0;	//for each component to Draw itself

	GraphicsInfo Component::GetGraphicsInfo() const;





	virtual int GetOutPinStatus() = 0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s) = 0;	//set status of Inputpin # n, to be used by connection class.






	bool GetSelected() const;
	virtual void SetSelected(bool s);

	string GetLabel() const;
	void SetLabel(string s);

	void Component::SetGraphicsInfo(GraphicsInfo arg_gfx);

	virtual string name() const = 0;
	virtual Location getInputPin1tLocation() = 0;
	virtual Location getoutputPinLocation() = 0;
	virtual int getReserved() = 0;
	virtual void connectTo(Component* gate_1, int x) = 0;
	virtual int getindex() = 0;
	virtual int Fanout_inc() = 0;
	virtual void Fanout_dec() = 0;



	virtual void setINputPin_1_Reserved() = 0;
	virtual void setINputPin_2_Reserved() = 0;
	virtual void setINputPin_3_Reserved() = 0;

	virtual void setINputPin_1_Unreserved() = 0;
	virtual void setINputPin_2_Unreserved() = 0;
	virtual void setINputPin_3_Unreserved() = 0;


	virtual Component* GetGate12() const = 0;
	virtual Component* GetGate22() const = 0;
	virtual Component* GetGate33() const = 0;

	virtual void SetGate12() = 0;
	virtual void SetGate22() = 0;
	virtual void SetGate33() = 0;

	virtual void disconnect_from_all() = 0;

	int GetID() const {
		return ID;
	}
	void SetID(int c) {
		ID = c;
		return;
	}

	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
