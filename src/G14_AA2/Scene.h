#pragma once
#include "Renderer.h"

enum GameState { PLAY, MENU, RANKING, EXIT, GOTO };
enum CurrentScene { PLEI, MENIU, RANQUINC, ECSIT };

class Scene
{
	

public:
	Scene();
	~Scene();
	GameState state;
	CurrentScene escenActual;
	virtual void Update();
	virtual void Draw();
	virtual void HandleEvents();
};

