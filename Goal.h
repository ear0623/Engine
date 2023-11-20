#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal();
	AGoal(int Newx, int NewY, char NewShape = 'G', int NewSortOrder = 200);
	virtual ~AGoal();
};

