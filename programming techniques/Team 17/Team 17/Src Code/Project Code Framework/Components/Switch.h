#ifndef _SWITCH_H
#define _SWITCH_H

#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include "Gate.h"
#include <typeinfo>

class Switch : public Gate
{
private:
	int fanout, fanout_count;
	STATUS L;
	bool inputPin1_reserved;
	bool inputPin2_reserved;
	bool inputPin3_reserved;
public:
	Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool select = false);
	virtual void Operate();
	virtual void Draw(Output* pOut, bool select = false);
	virtual int getindex();
	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);
	virtual void setInputPinStatus(int n, STATUS s);
	Location getInputPin1tLocation();
	Location getoutputPinLocation();
	virtual int getReserved();
	void setOutputPinStatus();
	virtual void connectTo(Component* gate_1, int x);
	virtual string name() const;
	virtual void SetSelected(bool s);
	virtual int Fanout_inc();
	virtual void Fanout_dec();

	virtual void setINputPin_1_Reserved();
	virtual void setINputPin_2_Reserved();
	virtual void setINputPin_3_Reserved();

	virtual void setINputPin_1_Unreserved();
	virtual void setINputPin_2_Unreserved();
	virtual void setINputPin_3_Unreserved();

	virtual Component* GetGate12() const { return NULL; }
	virtual Component* GetGate22() const { return NULL;  }
	virtual Component* GetGate33() const { return NULL; }

	virtual void SetGate12() {}
	virtual void SetGate22() {}
	virtual void SetGate33() {}

	virtual void disconnect_from_all() {}

};


#endif