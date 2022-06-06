#include "Led.h"

Led::Led(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

	gate_12 = NULL;

	inputpin = new Location[1];

	//setters for inputpin1
	inputpin[0].x = m_GfxInfo.x1 + 25;
	inputpin[0].y = m_GfxInfo.y1 + 50;



	inputPin1_reserved = false;

	m_InputPins = new InputPin[1];
}

void Led::Operate()
{

	if (gate_12 == NULL) {
		p->PrintMsg("Simulation failed. Check all connections.");
		p->ClearComponentArea(m_GfxInfo);
		selected = false;
		return;
	}
	if (gate_12->GetOutPinStatus() == HIGH)
	{
		p->ClearComponentArea(m_GfxInfo);
		selected = true;
	}
	else
	{
		p->ClearComponentArea(m_GfxInfo);
		selected = false;
	}
}

void Led::Draw(Output* pOut, bool select)
{
	p = pOut;
	pOut->DrawLED(m_GfxInfo, select);

}


int Led::GetOutPinStatus()
{
	return 0;
}

int Led::GetInputPinStatus(int n)
{
	return 0;
}

int Led::getindex()
{
	return 5;
}

void Led::setInputPinStatus(int n, STATUS s)
{
}

Location Led::getInputPin1tLocation()
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

Location Led::getoutputPinLocation()
{
	Location L;
	L.x = 0;
	L.y = 0;
	return L;
}

int Led::getReserved()
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

void Led::connectTo(Component* gate_1, int x)
{
	gate_12 = gate_1;
}

void Led::setINputPin_1_Reserved()
{
	inputPin1_reserved = true;
}
void Led::setINputPin_2_Reserved()
{

}

void Led::setINputPin_3_Reserved()
{

}

void Led::setINputPin_1_Unreserved()
{
	inputPin1_reserved = false;
}
void Led::setINputPin_2_Unreserved()
{

}

void Led::setINputPin_3_Unreserved()
{

}
Component* Led::GetGate12() const {
	return gate_12;
}

Component* Led::GetGate22() const {
	return NULL;
}
Component* Led::GetGate33() const {
	return NULL;
}

void Led::SetGate12() {
	gate_12 = NULL;
}
void Led::SetGate22() {
}
void Led::SetGate33() {
}

void Led::disconnect_from_all() {

	if (gate_12 != NULL) {
		gate_12->Fanout_dec();
	}

	gate_12 = NULL;

	inputPin1_reserved = false;

	fanout_count = 0;
}

string Led::name() const
{
	return typeid(*this).name();
}

int Led::Fanout_inc()
{
	return 0;
}
void Led::Fanout_dec() {
	return;
}