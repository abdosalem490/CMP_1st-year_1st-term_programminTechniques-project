#ifndef _XOR2_H
#define _XOR2_H

/*
  Class XOR2
  -----------
  represent the 2-input OR gate
*/

#include "Gate.h"
#include <typeinfo>

class XOR2 :public Gate
{
private:
	int fanout, fanout_count;
	bool inputPin1_reserved;
	bool inputPin2_reserved;
	bool inputPin3_reserved;
	Component* gate_12, * gate_22;
public:
	XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the XOR gate
	virtual void Draw(Output* pOut, bool selected_arg = false);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual string name() const;
	virtual int getindex();
	Location getInputPin1tLocation();
	Location getoutputPinLocation();
	virtual int getReserved();
	virtual void connectTo(Component* gate_1, int x);
	int Fanout_inc();
	virtual void Fanout_dec();

	virtual void setINputPin_1_Reserved();
	virtual void setINputPin_2_Reserved();
	virtual void setINputPin_3_Reserved();

	virtual void setINputPin_1_Unreserved();
	virtual void setINputPin_2_Unreserved();
	virtual void setINputPin_3_Unreserved();

	virtual Component* GetGate12() const;
	virtual Component* GetGate22() const;
	virtual Component* GetGate33() const;

	virtual void SetGate12();
	virtual void SetGate22();
	virtual void SetGate33();

	virtual void disconnect_from_all();
};

#endif