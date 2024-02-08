#include "SimpleEgine.h"
#include "World.h"//컴파일전 파일을 읽을 수 있게.
#include <conio.h>
#include "Player.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"
#include "Monster.h"


SimpleEgine* SimpleEgine::Instance = nullptr;
int SimpleEgine::KeyCode = 0;

SimpleEgine::SimpleEgine()
{
	Init();
}

SimpleEgine::~SimpleEgine()
{
	Term();
}

void SimpleEgine::Init()
{
	IsRunning = true;
	World = new UWorld();
}

void SimpleEgine::Run()
{
	while (IsRunning)
	{
		Input();
		//collision
		Tick();
		system("cls");
		Render();
	}
}

void SimpleEgine::Stop()
{
	IsRunning = false;
	delete World;
}

void SimpleEgine::Term()
{

}
//file 바꾸자. 
void SimpleEgine::LoadLevel(std::string FileName)
{
	//memory- Disk : Serialize 일렬로(save), Text(Json,csv),binary(umap)

	//Disk -> Memory : Deserialize
	std::string Map[10] = {
		"**********",
		"*P       *",
		"*        *",
		"*        *",
		"*     M  *",
		"*        *",
		"*        *",
		"*        *",
		"*       G*",
		"**********"
	};
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (Map[Y][X] == '*')
			{
				GetWorld()->SpawnActor(new AWall(X, Y));
				
			}
			else if (Map[Y][X] == ' ')
			{
				//floor
			}
			else if (Map[Y][X] == 'P')
			{
				GetWorld()->SpawnActor(new APlayer(X, Y));
			}
			else if (Map[Y][X] == 'M')
			{
				GetWorld()->SpawnActor(new AMonster(X, Y));
				//fllor
			}
			else if (Map[Y][X] == 'G')
			{
				GetWorld()->SpawnActor(new AGoal(X, Y));
				//floor
			}
			GetWorld()->SpawnActor(new AFloor(X, Y));
		}
	}

	GetWorld()->SortRenderOrder();

}

int SimpleEgine::Input()
{

	int KeyCode = _getch();

	return KeyCode;
}

void SimpleEgine::Tick()
{
	GetWorld()->Tick();
}

void SimpleEgine::Render()
{
	GetWorld()->Render();
}

