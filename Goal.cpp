#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';
	X = 10;
	Y = 10;
	SortOrder = 200;
}

AGoal::AGoal(int NewY, int NewX, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	X=(NewX);
	Y=(NewY);
	SortOrder = NewSortOrder;
}

AGoal::~AGoal()
{
}
