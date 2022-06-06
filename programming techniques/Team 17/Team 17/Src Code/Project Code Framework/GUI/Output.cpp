#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = RED;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
	CreateMainToolBar();

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}



/// <summary>
/// The next three functions are for undo, redo and delete operations.
/// </summary>
void Output::ClearComponentArea(GraphicsInfo gfx) const 
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(gfx.x1, gfx.y1, gfx.x2, gfx.y2);
}
window *Output::getWin() const {
	return pWind;
}



//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width - UI.ToolItemWidth, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

}


//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	string MenuItemImages[ITM_RIGHT];
	MenuItemImages[ITM_AND_GATE_2] = "Images\\Gates\\2 - Input AND gate\\2 input normal AND gate.png.jpg";
	MenuItemImages[ITM_AND_GATE_3] = "Images\\Gates\\3 - Input AND gate\\3 input normal AND gate.jpg";
	MenuItemImages[ITM_NOR_GATE_3] = "Images\\Gates\\3 - Input NOR\\3 input normal NOR gate.jpg";
	MenuItemImages[ITM_XOR_GATE_3] = "Images\\Gates\\3 - Input XOR gate\\3 input normal XOR gate.jpg";
	MenuItemImages[ITM_OR_GATE_2] = "Images\\Gates\\2 - Input OR gate\\2 input normal OR gate .jpg";
	MenuItemImages[ITM_INV] = "Images\\Gates\\INVERTER\\normal INVERTER.jpg";
	MenuItemImages[ITM_BUFF] = "Images\\Gates\\BUFFER\\normal BUFFER .jpg";
	MenuItemImages[ITM_NAND_GATE_2] = "Images\\Gates\\2 - Input NAND gate\\2 input normal NAND gate.png.jpg";
	MenuItemImages[ITM_NOR_GATE_2] = "Images\\Gates\\2 - Input NOR gate\\2 input normal NOR gate.jpg";
	MenuItemImages[ITM_XOR_GATE_2] = "Images\\Gates\\2 - Input XOR gate\\2 input normal XOR gate.jpg";
	MenuItemImages[ITM_XNOR_GATE_2] = "Images\\Gates\\2 - Input XNOR gate\\2 input normal XNOR gate .jpg";
	MenuItemImages[ITM_ARROW_RIGHT] = "Images\\Gates\\RIGHT-LEFT\\LEFT.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_RIGHT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		pWind->SetPen(BLACK, 2);
		pWind->DrawLine(i * UI.ToolItemWidth, 0, i * UI.ToolItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

// This is the second part of the design toolbar.
void Output::CreateDesignToolBar2() const {

	UI.AppMode = DESIGN2;
	string MenuItemImages[ITM_LEFT];
	MenuItemImages[ITM_LED] = "Images\\Gates\\LED\\off LED.jpg";
	MenuItemImages[ITM__CONNECTION] = "Images\\Menu\\connection.jpg";
	MenuItemImages[ITM_SWITCH] = "Images\\Menu\\SWITCH.jpg";
	MenuItemImages[ITM_DELETE] = "Images\\Menu\\MENU_DELETE.jpg";
	MenuItemImages[ITM_SAVE] = "Images\\Menu\\MENU_SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "Images\\Menu\\MENU_LOAD.jpg";
	MenuItemImages[ITM_EDIT_LABEL] = "Images\\Menu\\LABEL.jpg";
	MenuItemImages[ITM_SELECT] = "Images\\Menu\\MENU_SELECT.jpg";
	MenuItemImages[ITM_CUT] = "Images\\Menu\\MENU_CUT.jpg";
	MenuItemImages[ITM_COPY] = "Images\\Menu\\MENU_COPY.jpg";
	MenuItemImages[ITM_ARROW_LEFT] = "Images\\Gates\\RIGHT-LEFT\\RIGHT.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_LEFT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		pWind->SetPen(BLACK, 2);
		pWind->DrawLine(i * UI.ToolItemWidth, 0, i * UI.ToolItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::CreateMainToolBar() const {

	string MenuItemImages[ITM_MAIN_CNT];
	MenuItemImages[ITM_EXIT] = "Images\\Menu\\Menu_EXIT.jpg";
	MenuItemImages[ITM_SIMULATE] = "Images\\Menu\\Menu_SIMULATE.jpg";
	MenuItemImages[ITM_DESIGN] = "Images\\Menu\\Menu_DESIGN.jpg";
	MenuItemImages[ITM_UNDO] = "Images\\Menu\\Menu_UNDO.jpg";
	MenuItemImages[ITM_REDO] = "Images\\Menu\\Menu_REDO.jpg";


	for (int i = 0; i < ITM_MAIN_CNT; i++) {
		pWind->DrawImage(MenuItemImages[i], UI.width - UI.ToolItemWidth, i * UI.ToolBarHeight + UI.ToolBarHeight,
			UI.ToolItemWidth, UI.ToolBarHeight);
		pWind->SetPen(BLACK, 2);
		pWind->DrawLine(UI.width - UI.ToolItemWidth, (i * UI.ToolBarHeight) + 2 * UI.ToolBarHeight,
			UI.width, (i * UI.ToolBarHeight) + 2 * UI.ToolBarHeight);
	}

	//Draw a line beside the toolbar
	pWind->SetPen(BLACK, 2);
	pWind->DrawLine(UI.width - UI.ToolItemWidth, UI.ToolBarHeight, UI.width - UI.ToolItemWidth, UI.height - UI.StatusBarHeight);

}


//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_TRUTH] = "Images\\Menu\\MENU_TRUTH.jpg";
	MenuItemImages[ITM_SIM] = "Images\\Menu\\MENU_SIMULATE.jpg";
	MenuItemImages[ITM_VALIDATE] = "Images\\Menu\\MENU_VALIDATE.jpg";
	MenuItemImages[ITM_PROBE] = "Images\\Menu\\MENU_PROBE.jpg";
	// add icons for the following

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		pWind->SetPen(BLACK, 2);
		pWind->DrawLine(i * UI.ToolItemWidth, 0, i * UI.ToolItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage=  "Images\\Gates\\2 - Input AND gate\\2 input highlighted AND gate.png.jpg";
	else  
		GateImage = "Images\\Gates\\2 - Input AND gate\\2 input normal AND gate.png.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2 - Input NAND gate\\2 input highlighted AND gate.jpg";
	else
		GateImage = "Images\\Gates\\2 - Input NAND gate\\2 input normal NAND gate.png.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2 - Input OR gate\\2 input highlighted OR gate .jpg";
	else
		GateImage = "Images\\Gates\\2 - Input OR gate\\2 input normal OR gate .jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2 - Input NOR gate\\2 input highlighted NOR gate.jpg";
	else
		GateImage = "Images\\Gates\\2 - Input NOR gate\\2 input normal NOR gate.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2 - Input XNOR gate\\2 input highlighted XNOR gate .jpg";
	else
		GateImage = "Images\\Gates\\2 - Input XNOR gate\\2 input normal XNOR gate .jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2 - Input XOR gate\\2 input highlighted XOR gate.jpg";
	else
		GateImage = "Images\\Gates\\2 - Input XOR gate\\2 input normal XOR gate.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3 - Input AND gate\\3 input highlighted AND gate.jpg";
	else
		GateImage = "Images\\Gates\\3 - Input AND gate\\3 input normal AND gate.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3 - Input NOR\\3 input highlighted NOR gate.jpg";
	else
		GateImage = "Images\\Gates\\3 - Input NOR\\3 input normal NOR gate.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3 - Input XOR gate\\3 input highlighted XOR gate.jpg";
	else
		GateImage = "Images\\Gates\\3 - Input XOR gate\\3 input normal XOR gate.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}
void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\BUFFER\\highlighted BUFFER .jpg";
	else
		GateImage = "Images\\Gates\\BUFFER\\normal BUFFER .jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUFFER_Width, UI.BUFFER_Height);
}
void Output::DrawINVERTER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\INVERTER\\highlighted INVERTER.jpg";
	else
		GateImage = "Images\\Gates\\INVERTER\\normal INVERTER.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.INVERTER_Width, UI.INVERTER_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED\\on LED.jpg";
	else
		GateImage = "Images\\Gates\\LED\\off LED.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}
void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH\\highlighted SWITCH.jpg";
	else
		GateImage = "Images\\Gates\\SWITCH\\normal SWITCH.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	color c;
	c = (selected ? UI.SelectColor : UI.ConnColor);

	pWind->SetPen(c, 2);

	// assuming that x1 and y1 are the co-ordinates of the source pin
	// and assuming that x2 and y2 are the co-ordinates of the destination pin
	// most likely will be edited/updated later.
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
}



Output::~Output()
{
	delete pWind;
}
