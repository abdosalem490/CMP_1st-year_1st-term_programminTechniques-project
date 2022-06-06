#include "Component.h"
#include "InputPin.h"
#include "OutputPin.h"
#include "Gate.h"
#include "Switch.h"
#include <typeinfo>

class Connection :	public Component
{
	//Component*	SrcCmpnt;	//Connection source component
	//Component*	DstCmpnt;	//Connection Destination component
	//int		DstPin;		//The Input pin to which this connection is linked
	/*OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)*/
	
	GraphicsInfo gr;
	int x, pin;
	Component* gate_1, * gate_2;
	bool inputPin1_reserved;
	bool inputPin2_reserved;
	bool inputPin3_reserved;
public:
	Connection(Output* p, Component* pS = NULL, Component* pD = NULL);

	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool selected );	//for each component to Draw itself
	void Connection::Draw(Output* pOut);

	
	/*void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();*/
	
	virtual int getindex();
	
	virtual Location getInputPin1tLocation();
	virtual Location getoutputPinLocation();
	
	virtual void setINputPin_1_Reserved();
	virtual void setINputPin_2_Reserved();
	virtual void setINputPin_3_Reserved();

	virtual void setINputPin_1_Unreserved();
	virtual void setINputPin_2_Unreserved();
	virtual void setINputPin_3_Unreserved();

	virtual Component* GetGate12() const { return NULL; }
	virtual Component* GetGate22() const { return NULL; }
	virtual Component* GetGate33() const { return NULL; }

	virtual void SetGate12() {}
	virtual void SetGate22() {}
	virtual void SetGate33() {}

	virtual void disconnect_from_all() {}

	virtual int getReserved();
	virtual void connectTo(Component* gate_1, int x);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	
	int GetX() const;


	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual string name() const;
	virtual int Fanout_inc();
	virtual void Fanout_dec();

	Component* GetGate1();
	Component* GetGate2();

	void SetGate1(Component* );
	void SetGate2(Component* );
};