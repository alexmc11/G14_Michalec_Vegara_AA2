#pragma once
#include "Renderer.h"

enum GameState { PLAY, MENU, RANKING, EXIT, GOTO };
enum CurrentScene { CURR_PLAY, CURR_MENU, CURR_RANKING, CURR_EXIT };
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

