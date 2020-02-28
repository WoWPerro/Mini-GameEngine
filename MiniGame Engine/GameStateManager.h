#pragma once
#include "GameState.h"
#include "Platform.h"
#include "StackT.h"
#include "Console.h"

class GameState;

class GameStateManager
{
private:
	StackT<GameState*> states;
	Platform* platform;
	Console* console;
public:
	GameStateManager();
	~GameStateManager();
	void GameLoop();
	void SetState(GameState* state);
	void RealaseState();
};