#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Brick.h"
#include <vector>
class Map
{
public:
	Map();

	void DrawMap();

	~Map();

	int **md[5][6];

	int posiciones[29][2];

	/*Brick ladrillu;
	Brick ladrilluDestructible;*/
};

