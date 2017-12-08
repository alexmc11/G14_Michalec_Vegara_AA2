#include "Map.h"



Map::Map()
{
	int posicionX = 96;
	int posicionY = 176;
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 6; i++)
		{
			new Brick(posicionX, posicionY);
			posicionX += 96;
		}
		posicionX = 96;
		posicionY += 96;
	}
}




Map::~Map()
{
}
