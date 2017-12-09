#include "Map.h"



Map::Map()
{
	/*int posicionX = 96;
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
	}*/

	md = new int*[5];
	for (int i = 0; i < 5; i++) {

		md[i] = new int[6];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++)
		{
			md[i][j] = '.';
		}
	}
}

void Map::DrawMap()
{
}




Map::~Map()
{
}
