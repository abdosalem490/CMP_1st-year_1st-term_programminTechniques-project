#include"Gate.h"
#include <typeinfo>


class AND3 :public Gate
{
private:
	int fanout, fanout_count;
	bool inputPin1_reserved;
	bool inputPin2_reserved;
	bool inputPin3_reserved;
	Component* gate_12, * gate_22, * gate_33;
public:
	AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut, bool selected_arg);
	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual string name() const;
	virtual int getindex();
	Location getInputPin1tLocation();
	Location getoutputPinLocation();
	virtual int getReserved();
	virtual void connectTo(Component* gate_1, int x);
	virtual int Fanout_inc();
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

	virtual void disconnect_from_all();

	virtual void SetGate12();
	virtual void SetGate22();
	virtual void SetGate33();


};