#include"AND3.h"
AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	inputpin = new Location[3];

	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	gate_12 = NULL;
	gate_22 = NULL;
	gate_33 = NULL;
	fanout = r_FanOut;
	fanout_count = 0;

	//setters for output pin
	outputpin.x = m_GfxInfo.x1 + 50;
	outputpin.y = m_GfxInfo.y1 + 25;

	//setters for inputpin1
	inputpin[0].x = m_GfxInfo.x1;
	inputpin[0].y = m_GfxInfo.y1 + 10;

	//setters for inputpin2
	inputpin[1].x = m_GfxInfo.x1;
	inputpin[1].y = m_GfxInfo.y1 + 25;

	//setters for inputpin3
	inputpin[2].x = m_GfxInfo.x1;
	inputpin[2].y = m_GfxInfo.y1 + 35;

	inputPin1_reserved = false;
	inputPin2_reserved = false;
	inputPin3_reserved = false;

	m_InputPins = new InputPin[3];

}


void AND3::Operate()
{
	if (gate_12 == NULL || gate_22 == NULL|| gate_33 ==NULL)
	{
		m_OutputPin.setStatus(LOW);

	}
	else
	{
		if (gate_12->GetOutPinStatus() == HIGH && gate_22->GetOutPinStatus() == HIGH && gate_33->GetOutPinStatus() == HIGH)
		{
			m_OutputPin.setStatus(HIGH);
		}
		else
		{
			m_OutputPin.setStatus(LOW);
		}
	}
}



void AND3::Draw(Output* pOut, bool selected_arg)
{

	pOut->DrawAND3(m_GfxInfo, selected_arg);
}


int AND3::GetOutPinStatus()
{
	Operate();
	return m_OutputPin.getStatus();
}


void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

string AND3::name() const {
	return typeid(*this).name();
}

int AND3::getindex()
{
	return 10;
}

Location AND3::getInputPin1tLocation()
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
	else if(inputPin3_reserved == false)
	{
		Location L = inputpin[2];
		return L;
	}
	else if (inputPin2_reserved == true && inputPin1_reserved == true && inputPin3_reserved == true)
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

Location AND3::getoutputPinLocation()
{
	return outputpin;
}

int AND3::getReserved()
{
	if (inputPin1_reserved == false)
	{
		return 0;
	}
	if (inputPin1_reserved == true)
	{
		if (inputPin2_reserved == true)
		{
			if (inputPin3_reserved == true)
			{
				return 3;
			}
			if (inputPin3_reserved == false)
			{
				return 2;
			}
		}
		if (inputPin2_reserved == false)
		{
			return 1;
		}
	}
	return 3;

}

void AND3::connectTo(Component* gate_1, int x)
{
	if (x == 0)
	{
		gate_12 = gate_1;
	}
	else if (x == 1)
	{
		gate_22 = gate_1;
	}
	else if(x == 2)
	{
		gate_33 = gate_1;
	}
}

void AND3::setINputPin_1_Reserved()
{
	inputPin1_reserved = true;
}
void AND3::setINputPin_2_Reserved()
{
	inputPin2_reserved = true;
}

void AND3::setINputPin_3_Reserved()
{
	inputPin3_reserved = true;
}

void AND3::setINputPin_1_Unreserved()
{
	inputPin1_reserved = false;
}
void AND3::setINputPin_2_Unreserved()
{
	inputPin2_reserved = false;
}

void AND3::setINputPin_3_Unreserved()
{
	inputPin3_reserved = false;
}

Component* AND3::GetGate12() const {
	return gate_12;
}

Component* AND3::GetGate22() const {
	return gate_22;
}
Component* AND3::GetGate33() const {
	return gate_33;
}

void AND3::SetGate12() {
	gate_12 = NULL;
}
void AND3::SetGate22() {
	gate_22 = NULL;
}
void AND3::SetGate33() {
	gate_33 = NULL;
}

void AND3::disconnect_from_all() {

	if (gate_12 != NULL) {
		gate_12->Fanout_dec();
	}
	if (gate_22 != NULL) {
		gate_22->Fanout_dec();
	} if (gate_33 != NULL) {
		gate_33->Fanout_dec();
	}

	gate_12 = gate_22 = gate_33 = NULL;

	inputPin1_reserved = false;
	inputPin2_reserved = false;
	inputPin3_reserved = false;

	fanout_count = 0;
}

int AND3::Fanout_inc()
{
	fanout_count++;
	if (fanout_count <= fanout)
	{
		return 1;
	}
	return 0;
}
void AND3::Fanout_dec() {
	if (fanout_count > 0) {
		fanout_count--;
	}
	return;
}
