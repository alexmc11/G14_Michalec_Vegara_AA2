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

void Map::DrawBricks()
{
	int posX = 0;
	int posY = 80;
	for (int i = 0; i < 143; i++)
	{
		if (craps[i] == 1)
		{
			ladrillu.printDestructible(posX, posY);
			posX += 48;
		}
		else
		{
			posX += 48;
		}
		if (i % 13 == 0)
		{
			posY += 48;
			posX = 48;
		}
		
	}
}





Map::~Map()
{
}
