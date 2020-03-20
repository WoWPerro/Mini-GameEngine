#pragma once
#include "..\Platform\GameState.h"
#include "..\AssetManager\Text.h"
#include "..\GOM\Sprite.h"
#include <map>
#include "..\AssetManager\Text.h"

class Game : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
	std::map <int, Sprite> GameObjects;
	Text* t;
	Text* t2;
	Image* i;
public:
	Game();
	~Game();
	void Init(Platform* platform, GameStateManager* manager) override;
	void Draw() override;
	bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY) override;
	void Update() override;
	void Close() override;
};

