#include "Connection.h"

Connection::Connection(Output* p, Component* pS, Component* pD) : Component()
{
	gate_1 = pS;
	gate_2 = pD;

	Location L1, L2;
	L1 = gate_1->getoutputPinLocation();

	if (L1.x == 0 || L1.y == 0)
	{
		L1 = gate_2->getInputPin1tLocation();
		gr.x1 = L1.x;
		gr.y1 = L1.y;
		p->PrintMsg("you can't use LED as input to another gate");
	}
	else
	{
		gr.x1 = L1.x;
		gr.y1 = L1.y;
	}

	L2 = gate_2->getInputPin1tLocation();
	gr.x2 = L2.x;
	gr.y2 = L2.y;

	x = gate_2->getReserved();
	int y;
	if (x == 0)
	{
		y = gate_1->Fanout_inc();
		if (y == 1)
		{
			gate_2->setINputPin_1_Reserved();
			gate_2->connectTo(gate_1, x);
			gate_2->setInputPinStatus(1, (STATUS)pS->GetOutPinStatus());
			//Draw(p);
		}
		else
		{
			Location L = gate_1->getoutputPinLocation();
			gr.x2 = L.x;
			gr.y2 = L.y;
			p->PrintMsg("MAX number of FAN OUT for this gate");
		}
		

	}
	else if (x == 1)
	{
		y = pS->Fanout_inc();
		if (y == 1)
	   {
			gate_2->setINputPin_2_Reserved();
			gate_2->connectTo(gate_1, x);
			gate_2->setInputPinStatus(2, (STATUS)gate_1->GetOutPinStatus());
		//Draw(p);

	    }
	   else
	    {
		Location L = gate_1->getoutputPinLocation();
		gr.x2 = L.x;
		gr.y2 = L.y;
		p->PrintMsg("MAX number of FAN OUT for this gate");
	   }

	}
	else if(x == 2)
	{
		y = gate_1->Fanout_inc();
		if (y == 1)
		{
			pD->setINputPin_3_Reserved();
			gate_2->connectTo(gate_1, x);
			gate_2->setInputPinStatus(3, (STATUS)gate_1->GetOutPinStatus());
			//Draw(p);
		}
	    else
	    {
		Location L = gate_1->getoutputPinLocation();
		gr.x2 = L.x;
		gr.y2 = L.y;
		p->PrintMsg("MAX number of FAN OUT for this gate");
	    }
	}
	else if (x == 3)
	{
		Location L = gate_1->getoutputPinLocation();
		gr.x2 = L.x;
		gr.y2 = L.y;
		p->PrintMsg("you can't add another input ");
	}

}

void Connection::Draw(Output* pOut, bool select)
{
	pOut->DrawConnection(gr);
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	//DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(gr);

	//pOut->DrawConnection(m_GfxInfo);
}



Location Connection::getInputPin1tLocation()
{
	return Location();
}

Location Connection::getoutputPinLocation()
{
	return Location();
}

void Connection::setINputPin_1_Reserved()
{
}

void Connection::setINputPin_2_Reserved()
{
}

void Connection::setINputPin_3_Reserved()
{
}

void Connection::setINputPin_1_Unreserved()
{
}
void Connection::setINputPin_2_Unreserved()
{

}

void Connection::setINputPin_3_Unreserved()
{

}

int Connection::getReserved()
{
	return 0;
}

void Connection::connectTo(Component* gate_1, int x)
{
}


int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	//return DstPin->getStatus();
	return 0;
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return 0;
	//return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
	
}

int Connection::getindex()
{
	return 0;
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	//SrcPin->setStatus(s);
}

int Connection::GetX() const {
	return x;
}

// These two are for saving action.
Component* Connection::GetGate1() {
	try {
		return gate_1;
	}
	catch (...) {
		return NULL;
	}
}
Component* Connection::GetGate2() {
	return gate_2;
}

// This also is for saving and loading action.
string Connection::name() const
{
	return typeid(*this).name();
}

int Connection::Fanout_inc()
{
	return 0;
}
void Connection::Fanout_dec() {
	return;
}
