#include "UNDO_OP.h"
#include "..\ApplicationManager.h"

UNDO_OP::UNDO_OP(ApplicationManager *pApp):Action(pApp)
{
	p = pApp;
}

UNDO_OP::~UNDO_OP(void)
{
}

void UNDO_OP::ReadActionParameters()
{
	
}

void UNDO_OP::Execute()
{

	/*int count;
	Action** list = p->GetActionList(count);

	if (count != 0) {
		// Drawing the component:
		list[count - 1]->Undo();

		// Notifying the user:
		p->GetOutput()->PrintMsg("Undone.");

		// Removing the component from Redolist:		
		p->AddToRedoActionList(list[count - 1]);

		list[count - 1] = NULL;
	}
	else {
		p->GetOutput()->PrintMsg("All operations already undone.");
		
	}*/
	p->GetOutput()->PrintMsg("UNDO OPERATION IS NOT COMPLETE. There is existing coding structure for it but it may crash the program.");

}
void UNDO_OP::Undo()
{}

void UNDO_OP::Redo()
{}

