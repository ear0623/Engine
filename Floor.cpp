#include "Floor.h"

AFloor::AFloor()
{
	Shape = ' ';
	X = 10;
	Y = 10;
	SortOrder = 100;
	bCollide = false;
}

AFloor::AFloor(int NewY, int NewX, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
	bCollide = false;
}

AFloor::~AFloor()
{
}
