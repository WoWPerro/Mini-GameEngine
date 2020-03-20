#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
};

