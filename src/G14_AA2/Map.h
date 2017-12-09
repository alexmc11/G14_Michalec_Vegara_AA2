#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Brick.h"
#include "Bomb.h"
#include <vector>

struct posicionLadrillo
{
	int posX;
	int posY;
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


	std::vector<Brick*> TodosLosMuros;

	

	posicionLadrillo ladrillos[5][6];

	int **md;
	Brick ladrillu;
	Brick ladrilluDestructible;

	int posiciones[29][2];
};

