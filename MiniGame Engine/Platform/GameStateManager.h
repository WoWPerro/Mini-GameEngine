#pragma once
#include "GameState.h"
#include "Platform.h"
#include "..\DataBase\StackT.h"
#include "..\Log\Console.h"
#include "..\Platform\StackAllocator.h"

class GameState;

class GameStateManager
{
private:
	StackT<GameState*> states;
	Platform* platform;
	Console* console;
	StackAllocator* stackAllocator;
public:
	GameStateManager();
	~GameStateManager();
	void GameLoop();
	void SetState(GameState* state);
	void RealaseState();
};