#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Brick.h"
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

	posicionLadrillo ladrillos[5][6];

	int **md;

	Brick ladrillu;
	Brick ladrilluDestructible;

	int posiciones[29][2];

	/*Brick ladrillu;
	Brick ladrilluDestructible;*/
};

