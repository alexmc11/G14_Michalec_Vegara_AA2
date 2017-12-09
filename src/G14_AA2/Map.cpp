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
			TodosLosMuros.push_back(new Brick(posicionX, posicionY));
			// Para detectar colisiones cogemos el player y detectamos si se mueve en alguno de los bricks del vector con un iterador
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
	int posX = 96;
	int posY = 80;
	for (int i = 0; i < 155; i++)
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
		if (i % 14 == 0)
		{
			posY += 48;
			posX = 0;
		}
		
	}
}





Map::~Map()
{
}
