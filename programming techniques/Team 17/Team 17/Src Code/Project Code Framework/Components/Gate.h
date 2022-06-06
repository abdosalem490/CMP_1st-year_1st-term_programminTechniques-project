#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include <typeinfo>

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	// Component* gate_12, * gate_22, * gate_33;

	Location outputpin;
	Location* inputpin;

public:
	Gate(int r_Inputs, int r_FanOut);
	// void disconnect_from_all();
	// void Fanout_dec();

	/*Component* GetGate12() const;
	Component* GetGate22() const;
	Component* GetGate33() const;

	void SetGate12();
	void SetGate22();
	void SetGate33();*/

	/*void setINputPin_1_Reserved();
	void setINputPin_2_Reserved();
	void setINputPin_3_Reserved();

	void setINputPin_1_Unreserved();
	void setINputPin_2_Unreserved();
	void setINputPin_3_Unreserved();*/

	void ResetOutputAndInputLocation();
};

#endif
