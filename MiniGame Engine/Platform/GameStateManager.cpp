#include "GameStateManager.h"
#include <iostream>
#include "../Log/SimpleIni.h"

GameStateManager::GameStateManager()
{
	platform = new Platform("Tank");
	console = Console::Get();
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::GameLoop()
{
	CSimpleIniA ini;
	ini.LoadFile("C:\\Dev_WoWperro\\source\\repos\\7_Trimestre\\Diseño de Sistemas de juegos\\MiniGame Engine\\Debug\\EngineConfig\\Settings.ini");
	int buffer = std::stoi(ini.GetValue("Configuration", "buffer", ""));
	stackAllocator = new StackAllocator(1024 * 1024 * buffer);
	while (true)
	{
		try
		{
			if (states.size() == 0)
				throw std::exception("Error");
			auto state = states.top()->value;
			platform->CheckEvent(state, &GameState::Input);
			state->Update();
			state->Draw();

		}
		catch (...)
		{
			console->PrintFatal("Critical error Tank is closing");
			break;
		}
	}
}

void GameStateManager::SetState(GameState* state)
{
	state->Init(platform, this);
	states.push_front(state);
}

void GameStateManager::RealaseState()
{
	auto state = states.top()->value;
	state->Close();
	states.pop();
}