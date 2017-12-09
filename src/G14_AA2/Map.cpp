#include "Map.h"



Map::Map()
{
	int posicionX = 96;
	int posicionY = 176;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			ladrillos[i][j].posX = posicionX;
			ladrillos[i][j].posY = posicionY;
			posicionX += 96;
		}
		posicionX = 96;
		posicionY += 96;
	}
}

void Map::DrawMap()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			ladrillu.printBrick(ladrillos[i][j].posX, ladrillos[i][j].posY);
		}
	}
}




Map::~Map()
{
}
