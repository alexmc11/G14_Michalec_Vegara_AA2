#pragma once
#include "Renderer.h"

class Scene
{
	enum GameState { PLAY, MENU, RANKING, EXIT, GOTO };

public:
	Scene();
	~Scene();
	GameState state;
	virtual void Update();
	virtual void Draw();
	virtual void HandleEvents();
};

