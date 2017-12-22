#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Brick.h"
#include "Bomb.h"
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

	void DrawMap();

	void DrawBricks();

	~Map();

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

	std::vector<DestructibleBrick> MurosDestruibles;
	

	

	posicionLadrillo ladrillos[5][6];

	int **md;
	Brick ladrillu;
	Brick ladrilluDestructible;

	int posiciones[29][2];
};

