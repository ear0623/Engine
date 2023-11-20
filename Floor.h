#pragma once
#include "Actor.h"
class AFloor :public AActor
{
public:
	AFloor();
	AFloor(int NewY, int NewX, char NewShape=' ',int NewSortOrder =1);
	virtual ~AFloor();
};

