// Gem-Strike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Game.h"
#include <time.h>
#include <Windows.h>
#include "Console.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));
	GameStateManager* manager = new GameStateManager();
	Console::Get()->PrintRaw("Mi perro");
	Console::Get()->PrintFatal("AYUDAAAAAAAAAAAAAAAAAAA");
	manager->SetState(new Game());
	manager->GameLoop();
	delete manager;
	return 0;
}
