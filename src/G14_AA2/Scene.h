#pragma once
#include "Renderer.h"

enum GameState { PLAY, MENU, RANKING, EXIT, GOTO };
enum CurrentScene { PLEI, MENIU, RANQUINC, ECSIT };
enum Level {LVL1, LVL2, RANK};

class Scene
{
	

public:
	Scene();
	~Scene();
	GameState state;
	CurrentScene escenActual;
	Level lvl;
	virtual void Update();
	virtual void Draw();
	virtual void HandleEvents();
};

