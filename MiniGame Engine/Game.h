#pragma once
#include "GameState.h"
#include "Text.h"

class Game : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
public:
	Game();
	~Game();
	void Init(Platform* platform, GameStateManager* manager) override;
	void Draw() override;
	bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY) override;
	void Update() override;
	void Close() override;
};

