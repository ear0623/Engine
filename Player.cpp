#include "Player.h"
#include "SimpleEgine.h"
#include "World.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
	SortOrder = 500;
}

APlayer::APlayer(int NewX, int NewY,int NewSortOrder)//생성자는 변경하는게 아니라 늘려야됨
{
	Shape = 'P';
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
}

APlayer::~APlayer()
{

}

void APlayer::Tick()
{
	//AActor::Tick(KeyCode);//정규 문법
	__super::Tick();//같은 기능 . ms전용
	int KeyCode = SimpleEgine::KeyCode;
	//
	if (KeyCode == 'A' || KeyCode == 'a')
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}

	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
		
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
	
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
		
	}
	if (KeyCode == 27)
	{
		GENGINE->Stop();

	}
	else
	{

	}
	
}

bool APlayer::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GENGINE->GetWorld()->GetAllActors())
	{
		if (this == Actor)
		{
			continue;
		}
		if (Actor->bCollide == true &&
			Actor->GetX() == NewX &&
			Actor->GetY() == NewY)
		{
			return true;
		}
	}
	return false;
}
