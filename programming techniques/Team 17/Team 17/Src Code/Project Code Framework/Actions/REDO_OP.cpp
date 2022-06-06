#include "REDO_OP.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"


REDO_OP::REDO_OP(ApplicationManager* pApp) :Action(pApp)
{
	p = pApp;
}

REDO_OP::~REDO_OP(void)
{
}

void REDO_OP::ReadActionParameters()
{

}

void REDO_OP::Execute()
{
	/*int count;
	Action** list = p->GetActionList_Redo(count);

	if (count != 0) {
		// Drawing the component:
		list[count - 1]->Redo();

		// Notifying the user:
		p->GetOutput()->PrintMsg("Redone.");

		p->AddToActionList(list[count - 1]);

		// Removing the component from Redolist:
		list[count - 1] = NULL;
	}
	else {
		p->GetOutput()->PrintMsg("All operations already redone.");

	}*/

	p->GetOutput()->PrintMsg("REDO OPERATION IS NOT COMPLETE. There is existing coding structure for it but it may crash the program.");

	
	
}

void REDO_OP::Undo()
{}

void REDO_OP::Redo()
{}
