#include "INVERTER.h"

INVERTER::INVERTER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo = r_GfxInfo;
	gate_12 = NULL;
	fanout = r_FanOut;
	fanout_count = 0;
	inputpin = new Location[1];

	//setters for output pin
	outputpin.x = m_GfxInfo.x1 + 50;
	outputpin.y = m_GfxInfo.y1 + 25;

	//setters for inputpin1
	inputpin[0].x = m_GfxInfo.x1;
	inputpin[0].y = m_GfxInfo.y1 + 25;


	inputPin1_reserved = false;
	inputPin2_reserved = true;
	inputPin3_reserved = true;

	m_InputPins = new InputPin[1];
}


void INVERTER::Operate()
{
	//caclulate the output status as the INVERSE of the input pin
	//Add you code here
	if (gate_12 == NULL)
	{
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		if (gate_12->GetOutPinStatus() == LOW)
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
// Draws INVERTER gate
void INVERTER::Draw(Output* pOut, bool selected_arg)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINVERTER(m_GfxInfo, selected_arg);
}

//returns status of outputpin
int INVERTER::GetOutPinStatus()
{

	Operate();
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INVERTER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INVERTER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

string INVERTER::name() const {
	return typeid(*this).name();
}

int INVERTER::getindex()
{
	return 12;
}

Location INVERTER::getInputPin1tLocation()
{
	if (inputPin1_reserved == false)
	{
		Location L = inputpin[0];
		return L;
	}
	else if (inputPin1_reserved == true)
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

Location INVERTER::getoutputPinLocation()
{
	return outputpin;
}

int INVERTER::getReserved()
{
	if (inputPin1_reserved == false)
	{
		return 0;
	}
	if (inputPin1_reserved == true)
	{
		return 3;
	}
	return 3;

}

void INVERTER::connectTo(Component* gate_1, int x)
{
	if (x == 0)
	{
		gate_12 = gate_1;
	}
}

void INVERTER::setINputPin_1_Reserved()
{
	inputPin1_reserved = true;
}
void INVERTER::setINputPin_2_Reserved()
{

}

void INVERTER::setINputPin_3_Reserved()
{

}

void INVERTER::setINputPin_1_Unreserved()
{
	inputPin1_reserved = false;
}
void INVERTER::setINputPin_2_Unreserved()
{

}

void INVERTER::setINputPin_3_Unreserved()
{

}

Component* INVERTER::GetGate12() const {
	return gate_12;
}

Component* INVERTER::GetGate22() const {
	return NULL;
}
Component* INVERTER::GetGate33() const {
	return NULL;
}

void INVERTER::SetGate12() {
	gate_12 = NULL;
}
void INVERTER::SetGate22() {
}
void INVERTER::SetGate33() {
}
void INVERTER::disconnect_from_all() {

	if (gate_12 != NULL) {
		gate_12->Fanout_dec();
	}
	gate_12 = NULL;

	inputPin1_reserved = false;

	fanout_count = 0;
}
int INVERTER::Fanout_inc()
{
	fanout_count++;
	if (fanout_count <= fanout)
	{
		return 1;
	}
	return 0;
}
void INVERTER::Fanout_dec() {
	if (fanout_count > 0) {
		fanout_count--;
	}
	return;
}