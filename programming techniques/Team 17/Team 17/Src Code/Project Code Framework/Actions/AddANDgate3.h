
#include "action.h"
#include "..\Components\AND3.h"

class AddANDgate3 : public Action
{
private:

	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	AddANDgate3(ApplicationManager* pApp);
	virtual ~AddANDgate3(void);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


