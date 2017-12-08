#include "Bomb.h"



Bomb::Bomb()
{
	frameWidth = imageSize.x / 3;
	frameHeight = imageSize.y / 2;
	bombRect.x = 0;
	bombRect.y = frameHeight * 2;
	bombRect.w = bombRect.h = 48;
}


Bomb::~Bomb()
{
}
