#include "SimpleEgine.h"



int main()
{
	SimpleEgine* MyEngine = SimpleEgine::GetInstance();

	
	MyEngine->LoadLevel("a.smap");
	MyEngine->Run();

	delete MyEngine;



	return 0;
}