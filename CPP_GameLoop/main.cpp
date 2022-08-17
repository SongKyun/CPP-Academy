#include "GameEngine.h"
#include <iostream>

int main()
{
	GameEngine* engine = new GameEngine();

	engine->Initialize();

	engine->Run();

	delete engine;






	std::cin.get();
}