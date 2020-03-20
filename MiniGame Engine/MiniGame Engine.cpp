// Gem-Strike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#include "Platform\GameState.h"
#include "Platform\GameStateManager.h"
#include "Scenes\Game.h"
#include <time.h>
#include <Windows.h>
#include "Log\Console.h"


int main(int argc, char* argv[])
{
	srand(time(NULL));
	GameStateManager* manager = new GameStateManager();
	manager->SetState(new Game());
	manager->GameLoop();
	delete manager;
	return 0;
}
