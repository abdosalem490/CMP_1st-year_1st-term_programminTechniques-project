#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1000, height = 750,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 80;		//Width of each item in toolbar menu

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	
		AND2_Width = 50,		//AND2 Gate Image default width
		AND2_Height = 50,		//AND2 Gate Image default height

		NAND2_Width = 50,		//NAND2 Gate Image default width
		NAND2_Height = 50,		//NAND2 Gate Image default height

		OR2_Width = 50,		    //OR2 Gate Image default width
		OR2_Height = 50,		//OR2 Gate Image default height

		NOR2_Width = 50,		 //NOR2 Gate Image default width
		NOR2_Height = 50,	 	//NOR2 Gate Image default height

		XNOR2_Width = 50,		 //XNOR2 Gate Image default width
		XNOR2_Height = 50,	 	//XNOR2 Gate Image default height

		XOR2_Width = 50,		 //XOR2 Gate Image default width
		XOR2_Height = 50,	 	//XOR2 Gate Image default height

		AND3_Width = 50,		 //AND3 Gate Image default width
		AND3_Height = 50,	 	//AND3 Gate Image default height

		NOR3_Width = 50,		 //NOR3 Gate Image default width
		NOR3_Height = 50,	 	//NOR3 Gate Image default height

		XOR3_Width = 50,		 //XOR3 Gate Image default width
		XOR3_Height = 50,	 	//XOR3 Gate Image default height

		BUFFER_Width = 50,		 //BUFFER Gate Image default width
		BUFFER_Height = 50,	 	//BUFFER Gate Image default height

		INVERTER_Width = 50,	 //INVERTER Gate Image default width
		INVERTER_Height = 50,	//INVERTER Gate Image default height

		LED_Width = 50,	     	 //LED Gate Image default width
		LED_Height = 50,	 	//LED Gate Image default height

		SWITCH_Width = 50,	     //SWITCH Gate Image default width
		SWITCH_Height = 50;	 	//SWITCH Gate Image default height
	
}UI;	//create a single global object UI

#endif