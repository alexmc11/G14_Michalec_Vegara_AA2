#pragma once
class Scene
{
public:
	Scene();
	~Scene();
	virtual void Update();
	virtual void Draw();
	virtual void HandleEvents();
};

