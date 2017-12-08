#include "Map.h"



Map::Map()
{
	int posicionXinicial = 96;
	int posicionYinicial = 176;
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 6; i++)
		{
			new Brick(posicionXinicial, posicionYinicial);
			posicionXinicial += 96;
		}
		posicionXinicial = 96;
		posicionYinicial += 96;
	}
}




Map::~Map()
{
}
