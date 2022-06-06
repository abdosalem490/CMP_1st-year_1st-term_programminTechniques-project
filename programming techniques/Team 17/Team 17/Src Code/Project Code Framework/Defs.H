#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType 
{
	ADD_BUFF,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	CREATE_TRUTHTABLE,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled
	VALIDATE,
	PROBE,
	CUT,
	COPY,

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	
	DSN_MODE2, 

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	MAIN_TOOL
};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION,
	
	// this is added to solve something with the design toolbar.
	// it's not the best solution, but it is what worked, or what came up in my mind.
	// input class is modified according to this. Please consider it while working.
	DESIGN2 
	
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_BUFF,
	ITM_INV,			//Add 1-input Inverter gate
	ITM_AND_GATE_2,		//Add 2-input AND gate
	ITM_OR_GATE_2,
	ITM_NAND_GATE_2,
	ITM_NOR_GATE_2,
	ITM_XOR_GATE_2,
	ITM_XNOR_GATE_2,
	ITM_AND_GATE_3,
	ITM_NOR_GATE_3,
	ITM_XOR_GATE_3,
	ITM_ARROW_RIGHT,
	ITM_RIGHT
};

// These are the items of the second part of the design toolbar, for which I added another mode (DESIGN2)
enum DsgnMenuItem2 {

	ITM_LED,
	ITM_SWITCH,
	ITM__CONNECTION,
	ITM_DELETE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_EDIT_LABEL,
	// ITM_MOVE,
	ITM_SELECT,
	ITM_CUT,
	ITM_COPY,
	ITM_ARROW_LEFT,
	ITM_LEFT		//no. of design menu items ==> This should be the last line in this enum

};

enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM,	//Simulate menu item
	ITM_VALIDATE,
	ITM_PROBE,
	ITM_TRUTH,	//Truth table menu item


	//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};


// These are the itmes of the main menu for switching between design mode, simulation mode, and exiting.
enum mainMenuItem {

	ITM_EXIT,
	ITM_DESIGN,
	ITM_SIMULATE,
	ITM_UNDO,
	ITM_REDO,
	
	ITM_MAIN_CNT


};
struct Location
{
	int x, y;
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1,y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif