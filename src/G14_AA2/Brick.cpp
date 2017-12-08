#include "Brick.h"



Brick::Brick(int posX, int posY)
{
	frameWidth = imageSize.x / 3;
	frameHeight = imageSize.y / 2;
	nondestructibleBrick.x = 0;
	nondestructibleBrick.y = frameHeight * 2;
	nondestructibleBrick.w = nondestructibleBrick.h = 48;
	nondestructibleBrick = { posX, posY, nondestructibleBrick.w, nondestructibleBrick.h };
	Renderer::Instance()->PushImage(WALL_SPRITE, nondestructibleBrick);
	Renderer::Instance()->Render();
}


Brick::~Brick()
{
}
