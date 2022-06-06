#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate

}
/*void ::disconnect_from_all() {

	gate_12 = gate_22 = gate_33 = NULL;

	inputPin1_reserved = false;
	inputPin2_reserved = false;
	inputPin3_reserved = false;

	// fanout_count = 0;
}*/


/*Component* ::GetGate12() const{
	return gate_12;
}

Component* ::GetGate22() const{
	return gate_22;
}
Component* ::GetGate33() const{
	return gate_33;
}

void ::SetGate12() {
	gate_12 = NULL;
}
void ::SetGate22() {
	gate_22 = NULL;
}
void ::SetGate33() {
	gate_33 = NULL;
}*/

// Resetting outputpin location for a new graphicsInfo of the component (CUT OPERATION)
void Gate::ResetOutputAndInputLocation() {

	outputpin.x = dynamic_cast<Component*>(this)->GetGraphicsInfo().x1 + 50;
	outputpin.y = dynamic_cast<Component*>(this)->GetGraphicsInfo().y1 + 25;

	if (sizeof(inputpin) / sizeof(inputpin[0]) == 1) {
		inputpin[0].x = dynamic_cast<Component*>(this)->GetGraphicsInfo().x1;
		inputpin[0].y = dynamic_cast<Component*>(this)->GetGraphicsInfo().y1 + 25;
	}
	else if (sizeof(inputpin) / sizeof(inputpin[0]) == 2) {
		inputpin[0].x = dynamic_cast<Component*>(this)->GetGraphicsInfo().x1;
		inputpin[0].y = dynamic_cast<Component*>(this)->GetGraphicsInfo().y1 + 12;
		inputpin[1].x = dynamic_cast<Component*>(this)->GetGraphicsInfo().x1;
		inputpin[1].y = dynamic_cast<Component*>(this)->GetGraphicsInfo().y1 + 34;
	}
	else {
		inputpin[0].x = dynamic_cast<Component*>(this)->GetGraphicsInfo().x1;
		inputpin[0].y = dynamic_cast<Component*>(this)->GetGraphicsInfo().y1 + 10;
		inputpin[1].x = dynamic_cast<Component*>(this)->GetGraphicsInfo().x1;
		inputpin[1].y = dynamic_cast<Component*>(this)->GetGraphicsInfo().y1 + 25;
		inputpin[2].x = dynamic_cast<Component*>(this)->GetGraphicsInfo().x1;
		inputpin[2].y = dynamic_cast<Component*>(this)->GetGraphicsInfo().y1 + 35;
	}
}
/*void ::setINputPin_1_Reserved()
{
	inputPin1_reserved = true;
}
void ::setINputPin_2_Reserved()
{
	inputPin2_reserved = true;
}

void ::setINputPin_3_Reserved()
{
	inputPin3_reserved = true;
}

void ::setINputPin_1_Unreserved()
{
	inputPin1_reserved = false;
}
void ::setINputPin_2_Unreserved()
{
	inputPin2_reserved = false;
}

void ::setINputPin_3_Unreserved()
{
	inputPin3_reserved = false;
}*/

/*void ::Fanout_dec() {
	if (fanout_count > 0) {
		fanout_count--;
	}
	return;
}*/