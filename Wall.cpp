#include "Wall.h"
#include <vector>

AWall::AWall()
{
	Shape = '*';
	X = 0;
	Y = 0;
	SortOrder = 0;
	bCollide = true;
}

AWall::AWall(int NewX, int NewY, char NewShape, int NewSortOrder)//Ã£¾Ò´Ù.
{
	SetX(NewX);
	SetY(NewY);
	Shape=NewShape;
	SortOrder = NewSortOrder;
	bCollide = true;
}



AWall::~AWall()
{
}
