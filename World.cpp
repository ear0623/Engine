#include "World.h"
#include "Actor.h"//���峵����� ���� ����
#include <algorithm>

UWorld::UWorld()
{
}

UWorld::~UWorld()
{

}

void UWorld::SpawnActor(AActor* NewActor)
{
	if (NewActor)
	{
		Actors.push_back(NewActor);
	}

}

void UWorld::Tick()
{
	for (const auto& Actor : Actors)
	{
		Actor->Tick();//keycode
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::SortRenderOrder()
{
	std::sort(Actors.begin(),
		Actors.end(),
		[](const AActor* LHS, const AActor* RHS) {
			return LHS->SortOrder < RHS->SortOrder;
		});
	//std::sort(Actors.begin(), Actors.end(), std::greater<AActor*>());

}
