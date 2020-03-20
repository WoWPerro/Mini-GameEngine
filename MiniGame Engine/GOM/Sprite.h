#pragma once
#include "GameObject.h"

class Sprite : GameObject
{
private:
	float _x;
	float _y;
	float sizeX;
	float sizeY;
public:
	Sprite();
	~Sprite();
	void Init() override;
	void Draw() override;
	void Update() override;
	float GetsizeX();
	float GetsizeY();
	float GetX();
	float GetY();
	void SetX(float x);
	void SetY(float y);
	void SetsizeX(float x);
	void SetsizeY(float y);
};