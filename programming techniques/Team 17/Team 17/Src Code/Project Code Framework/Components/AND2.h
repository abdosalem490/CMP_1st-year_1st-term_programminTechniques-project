#ifndef _AND2_H
#define _AND2_H

/*
  Class AND2
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"
#include <typeinfo>

class AND2:public Gate
{
private:
	bool inputPin1_reserved;
	bool inputPin2_reserved;
	bool inputPin3_reserved;
	int fanout, fanout_count;
	Component* gate_12, * gate_22;
public:
	AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut, bool selected_arg);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual int getindex();
	Location getInputPin1tLocation();
	Location getoutputPinLocation();

	virtual int getReserved();
	virtual void connectTo(Component* gate_1, int x);
	virtual string name() const;

	virtual void setINputPin_1_Reserved();
	virtual void setINputPin_2_Reserved();
	virtual void setINputPin_3_Reserved();

	virtual void setINputPin_1_Unreserved();
	virtual void setINputPin_2_Unreserved();
	virtual void setINputPin_3_Unreserved();

	virtual Component* GetGate12() const;
	virtual Component* GetGate22() const;
	virtual Component* GetGate33() const;

	virtual void disconnect_from_all();

	virtual void SetGate12();
	virtual void SetGate22();
	virtual void SetGate33();

	int Fanout_inc();
	virtual void Fanout_dec();

};

#endif