#include"Switch.h"

Switch::Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool select) :Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	
	//selected = select;

	//setters for output pin
	outputpin.x = m_GfxInfo.x1 + 50;
	outputpin.y = m_GfxInfo.y1 + 25;
	selected = false;
	L = LOW;
	inputPin1_reserved = true;
}

void Switch::Operate()
{
	setOutputPinStatus();

}

void Switch::Draw(Output* pOut, bool select)
{
	pOut->DrawSWITCH(m_GfxInfo, select);
}

int Switch::getindex()
{
	return 4;
}

int Switch::GetOutPinStatus()
{
	Operate();
	return m_OutputPin.getStatus();
}

int Switch::GetInputPinStatus(int n)
{
	return 0;
}


void Switch::setInputPinStatus(int n, STATUS s)
{
}

Location Switch::getInputPin1tLocation()
{
	Location L;
	L.x = 0;
	L.y = 0;
	return L;
}

Location Switch::getoutputPinLocation()
{
	return outputpin;
}

int Switch::getReserved()
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

void Switch::setOutputPinStatus()
{
	m_OutputPin.setStatus(L);
}

void Switch::connectTo(Component* gate_1, int x)
{
}

string Switch::name() const
{
	return typeid(*this).name();
}

void Switch::setINputPin_1_Reserved()
{
	inputPin1_reserved = true;
}
void Switch::setINputPin_2_Reserved()
{

}

void Switch::setINputPin_3_Reserved()
{

}

void Switch::setINputPin_1_Unreserved()
{
	inputPin1_reserved = false;
}
void Switch::setINputPin_2_Unreserved()
{

}

void Switch::setINputPin_3_Unreserved()
{

}

void Switch::SetSelected(bool s)
{
	selected = s;
	if (s == true)
	{
		L = HIGH;
	}
	else
	{
		L = LOW;
	}
}

int Switch::Fanout_inc()
{
	return 1;
}

void Switch::Fanout_dec() {
	return;
}