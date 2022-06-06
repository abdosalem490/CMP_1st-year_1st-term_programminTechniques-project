#include "action.h"
#include "..\Components\NOR3.h"

class AddNORgate3 : public Action
{
private:

	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	AddNORgate3(ApplicationManager* pApp);
	virtual ~AddNORgate3(void);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};



