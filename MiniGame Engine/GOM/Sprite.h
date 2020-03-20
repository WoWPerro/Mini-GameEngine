#pragma once
#include "GameObject.h"

class Sprite: public virtual GameObject
{
private:
	float x;
	float y;
	float sizeX;
	float sizeY;
public:
	Sprite();
	~Sprite();
	void Init() override;
	void Draw() override;
	void Update() override;
};

