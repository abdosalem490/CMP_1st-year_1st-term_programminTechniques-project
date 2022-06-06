//#include "Input.h"
#include "Output.h"
#include "..\Actions\SELECT_OP.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut, string message)
{
	//int x1, y1;
	char n;
	const int ESCAPE = 27;
	const int ENTER = 13;
	const int BACKSPACE = 8;

	string s = "";
	bool test1 = true;

	pWind->FlushKeyQueue();

	if (UI.AppMode == DESIGN || UI.AppMode == DESIGN2)
	{
		while (test1) {
			pWind->WaitKeyPress(n);
			if (n == BACKSPACE)
			{
				if (!s.empty())
				{
					s.pop_back();
				}
			}
			else if (n == ENTER)
			{
				pOut->ClearStatusBar();
				test1 = false;
			}
			else if (n == ESCAPE)
			{
				s.clear();
				break;
			}
			else {
				s += n;
			}
			pOut->PrintMsg(message + " " + s);
		}
	}
	return s;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(Output *pOut) const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click



	// THIS IS ADDED FOR The main menu bar. For SWITCHING BETWEEN DESIGN AND SIMULATION MODES, and Exiting

	if (x >= UI.width - UI.ToolItemWidth && x < UI.width && y > UI.ToolBarHeight && y < UI.height) {
		int ClickedItemOrder = (y - UI.ToolBarHeight) / UI.ToolBarHeight;
		switch (ClickedItemOrder)
		{
		case ITM_EXIT: return EXIT;

		case ITM_SIMULATE:
			pOut->ClearToolBar();
			pOut->CreateSimulationToolBar();
			return SIM_MODE;
			break;

		case ITM_DESIGN:
			pOut->ClearToolBar();
			pOut->CreateDesignToolBar();
			return DSN_MODE;
			break;

		case ITM_UNDO:
			return UNDO;
			break;

		case ITM_REDO:
			return REDO;
			break;


		case ITM_EDIT_LABEL:
			return EDIT_Label;
			break;

		case SELECT: 

		default: return MAIN_TOOL;
		}
	}

	// This is for the first part of the design toolbar.
	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int clicked_item_at_left = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (clicked_item_at_left)
			{
			case ITM_BUFF: return  ADD_BUFF;
			case ITM_INV:return ADD_INV;
			case ITM_AND_GATE_2: return ADD_AND_GATE_2;
			case  ITM_OR_GATE_2: return ADD_OR_GATE_2;
			case ITM_NAND_GATE_2:return ADD_NAND_GATE_2;
			case ITM_NOR_GATE_2: return ADD_NOR_GATE_2;
			case  ITM_XOR_GATE_2: return ADD_XOR_GATE_2;
			case ITM_XNOR_GATE_2: return ADD_XNOR_GATE_2;
			case ITM_AND_GATE_3:return ADD_AND_GATE_3;
			case ITM_NOR_GATE_3: return ADD_NOR_GATE_3;
			case ITM_XOR_GATE_3: return ADD_XOR_GATE_3;
			case ITM_ARROW_RIGHT:
				// function
				pOut->ClearToolBar();
				pOut->CreateDesignToolBar2();
				return DSN_MODE2;
				break;
			}
		}
	}

	// This is added for the second part of the design toolbar.
	if (UI.AppMode == DESIGN2) 
	{

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int clickeditem_at_right = (x / UI.ToolItemWidth);
			switch (clickeditem_at_right)
			{
			case ITM__CONNECTION: return ADD_CONNECTION;
			case  ITM_SWITCH: return ADD_Switch;
			case  ITM_LED: return ADD_LED;
			case  ITM_DELETE:return DEL;
			// case  ITM_MOVE: return MOVE;
			case ITM_SELECT: return SELECT;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_EDIT_LABEL:return EDIT_Label;
			case ITM_CUT: return CUT;
			case ITM_COPY: return COPY;

			case ITM_ARROW_LEFT:
				pOut->ClearToolBar();
				pOut->CreateDesignToolBar();
				return DSN_MODE;
				//case ITM_UNDO:return UNDO; (BONUS)
				//case ITM_REDO:return REDO; (BONUS)
			default:return DSN_TOOL;
			}
		}


	}

	
	// This is for checking if the click was on the drawing area or the status bar.
	// It doesn't matter whether which part (or mode) of the design toolbar is visible.
	if (UI.AppMode == DESIGN || UI.AppMode == DESIGN2) 
	{ 
		//[2] User clicks on the drawing area
		if (y > UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			pOut->PrintMsg("A click on the drawing area. Choose icon select, in the second part of the design toolbar to turn on/off a switch.");
		}

		// [3] User clicks on the status bar
		if (y < UI.height && y > UI.height - UI.StatusBarHeight)
		{
				return STATUS_BAR;	//user want to select/unselect a component
		}

	} else if (UI.AppMode == SIMULATION)
	{
		pOut->ClearStatusBar();
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			pOut->ClearStatusBar();
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)        //identifier NUMBER is defined at the begining of the function
			{
			case ITM_SIM:return SIM_MODE;
			case ITM_TRUTH:return CREATE_TRUTHTABLE;
			case ITM_VALIDATE: return VALIDATE;
			case ITM_PROBE: return PROBE;

			default: DSN_TOOL;

			}
		}
	}
	
}


Input::~Input()
{
}
