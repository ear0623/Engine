#include "Monster.h"

AMonster::AMonster()
{
	Shape = 'M';
	X = 10;
	Y = 10;
	SortOrder = 400;
	bCollide = false;
}

AMonster::AMonster(int NewX, int NewY, char NewShape,int NewSortOrder)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
}

AMonster::~AMonster()
{
}
