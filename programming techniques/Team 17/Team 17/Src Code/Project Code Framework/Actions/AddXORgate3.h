#include "action.h"
#include "..\Components\XOR3.h"

class AddXORgate3 : public Action
{
private:

	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	AddXORgate3(ApplicationManager* pApp);
	virtual ~AddXORgate3(void);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};



