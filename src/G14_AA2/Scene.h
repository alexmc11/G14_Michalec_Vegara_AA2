#pragma once
#include "Renderer.h"

enum GameState { PLAY, MENU, RANKING, EXIT, GOTO };

class Scene
{
	

public:
	Scene();
	~Scene();
	GameState state;
	virtual void Update();
	virtual void Draw();
	virtual void HandleEvents();
};

