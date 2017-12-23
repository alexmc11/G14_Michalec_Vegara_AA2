#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Brick.h"
#include "Bomb.h"
#include "Menu.h"
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>



struct posicionLadrillo
{
	int posX;
	int posY;
};

struct FixBrick
{
	SDL_Rect fixBrickRect, fixBrickTarget;
};

struct DestructibleBrick
{
	SDL_Rect destructibleBrickRect, destructibleBrickTarget;
};

class Map
{
public:
	Map();


	void DrawMap1();

	void DrawMap2();

	void DrawBricks1();

	void DrawBricks2();

	~Map();

	Menu mainmenu;

	bool level1 = false;
	bool level2 = false;

	int levelID = 0;
	int tiempo = 0;
	int cantidadVidas = 0;

	int craps[155] = { 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0,
					   0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
					   0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
					   0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1,
					   0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
					   0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
					   0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
					   0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
					   0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0,
					   0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
					   0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0};


	std::vector<SDL_Rect> TodosLosMuros;

	std::vector<FixBrick> MurosFijos;

	std::vector<FixBrick> MurosFijos2;

	std::vector<DestructibleBrick> MurosDestruibles;

	std::vector<DestructibleBrick> MurosDestruibles2;
	

	

	posicionLadrillo ladrillos[5][6];

	int **md;
	Brick ladrillu;
	Brick ladrilluDestructible;

	int posiciones[29][2];
};

