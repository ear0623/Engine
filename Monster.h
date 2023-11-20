#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:

	AMonster();
	AMonster(int Newx, int NewY, char NewShape ='M',int NewSortOrder=300);
	virtual	~AMonster();
};

