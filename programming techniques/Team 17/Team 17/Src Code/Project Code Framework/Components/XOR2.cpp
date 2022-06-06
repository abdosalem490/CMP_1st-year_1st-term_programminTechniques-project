#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	gate_12 = NULL;
	gate_22 = NULL;
	fanout = r_FanOut;
	fanout_count = 0;

	inputpin = new Location[2];

	//setters for output pin
	outputpin.x = m_GfxInfo.x1 + 50;
	outputpin.y = m_GfxInfo.y1 + 25;

	//setters for inputpin1
	inputpin[0].x = m_GfxInfo.x1;
	inputpin[0].y = m_GfxInfo.y1 + 12;

	//setters for inputpin2
	inputpin[1].x = m_GfxInfo.x1;
	inputpin[1].y = m_GfxInfo.y1 + 34;

	inputPin1_reserved = false;
	inputPin2_reserved = false;
	inputPin3_reserved = true;

	m_InputPins = new InputPin[2];
}


void XOR2::Operate()
{
	//caclulate the output status as the XORing of the two input pins
	//Add you code here
	if (gate_12 == NULL || gate_22 == NULL)
	{
		m_OutputPin.setStatus(LOW);

	}
	else
	{
		if (gate_12->GetOutPinStatus() !=  gate_22->GetOutPinStatus() )
		{
			m_OutputPin.setStatus(HIGH);
		}
		else
		{
			m_OutputPin.setStatus(LOW);
		}
	}

}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut, bool selected_arg)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo, selected_arg);
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	Operate();
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

string XOR2::name() const {
	return typeid(*this).name();
}

int XOR2::getindex()
{
	return 18;
}

Location XOR2::getInputPin1tLocation()
{
	if (inputPin1_reserved == false)
	{
		Location L = inputpin[0];
		return L;
	}
	else if (inputPin2_reserved == false)
	{
		Location L = inputpin[1];
		return L;
	}
	else if (inputPin2_reserved == true && inputPin1_reserved == true)
	{
		Location L;
		L.x = 0;
		L.y = 0;
		return L;
	}
	Location L;
	L.x = 0;
	L.y = 0;
	return L;
}

Location XOR2::getoutputPinLocation()
{
	return outputpin;
}

int XOR2::getReserved()
{
	if (inputPin1_reserved == false)
	{
		return 0;
	}
	if (inputPin1_reserved == true)
	{
		if (inputPin2_reserved == true)
		{
			return 3;
		}
		if (inputPin2_reserved == false)
		{
			return 1;
		}
	}
	return 3;

}

void XOR2::setINputPin_1_Reserved()
{
	inputPin1_reserved = true;
}
void XOR2::setINputPin_2_Reserved()
{
	inputPin2_reserved = true;
}

void XOR2::setINputPin_3_Reserved()
{
}

void XOR2::setINputPin_1_Unreserved()
{
	inputPin1_reserved = false;
}
void XOR2::setINputPin_2_Unreserved()
{
	inputPin2_reserved = false;
}

void XOR2::setINputPin_3_Unreserved()
{
}

void XOR2::connectTo(Component* gate_1, int x)
{
	if (x == 0)
	{
		gate_12 = gate_1;
	}
	else if (x == 1)
	{
		gate_22 = gate_1;
	}
}
int XOR2::Fanout_inc()
{
	fanout_count++;
	if (fanout_count <= fanout)
	{
		return 1;
	}
	return 0;
}

Component* XOR2::GetGate12() const {
	return gate_12;
}

Component* XOR2::GetGate22() const {
	return gate_22;
}
Component* XOR2::GetGate33() const {
	return NULL;
}

void XOR2::SetGate12() {
	gate_12 = NULL;
}
void XOR2::SetGate22() {
	gate_22 = NULL;
}
void XOR2::SetGate33() {
}

void XOR2::disconnect_from_all() {

	if (gate_12 != NULL) {
		gate_12->Fanout_dec();
	}
	if (gate_22 != NULL) {
		gate_22->Fanout_dec();
	}

	gate_12 = gate_22 = NULL;


	inputPin1_reserved = false;
	inputPin2_reserved = false;

	fanout_count = 0;
}

void XOR2::Fanout_dec() {
	if (fanout_count > 0) {
		fanout_count--;
	}
	return;
}