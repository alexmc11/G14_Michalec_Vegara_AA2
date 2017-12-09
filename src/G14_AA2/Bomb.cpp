#include "Bomb.h"



Bomb::Bomb(int posX, int posY)
{
	bombRect = { posX, posY, 48, 48 };
	bombTarget = { 0, 48, 48, 48 };
	Renderer::Instance()->PushSprite(ITEMS_SPRITE, bombTarget, bombRect);
}

void Bomb::bombExplode(int posX, int posY)
{
	//Center
	explodeCenter = { posX, posY, 48, 48 };
	centerTarget = { 0,0,48,48 };

	//Up
	explodeUp1 = { posX, posY - 48, 48, 48 };
	up1Target = { 0, 336, 48, 48 };
	explodeUp2 = { posX, posY - 96, 48, 48 };
	up2Target = { 0, 144, 48, 48 };

	//Down
	explodeDown1 = { posX, posY + 48, 48, 48 };
	down1Target = { 0, 336, 48, 48 };
	explodeDown2 = { posX, posY + 96, 48, 48 };
	down2Target = { 0, 192, 48, 48 };

	//Left
	explodeLeft1 = { posX - 48, posY, 48, 48 };
	left1Target = { 0, 240, 48, 48 };
	explodeLeft2 = { posX - 96, posY, 48, 48 };
	left2Taget = { 0, 48, 48, 48 };

	//Right
	explodeRight1 = { posX + 48, posY, 48, 48 };
	right1Target = { 0, 240, 48, 48 };
	explodeRight2 = { posX + 96, posY, 48, 48 };
	right2Target = { 0, 96, 48, 48 };

	//Center
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, centerTarget, explodeCenter);
	//UP
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, up1Target, explodeUp1);
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, up2Target, explodeUp2);
	//DOWN
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, down1Target, explodeDown1);
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, down2Target, explodeDown2);
	//LEFT
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, left1Target, explodeLeft1);
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, left2Taget, explodeLeft2);
	//RIGHT
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, right1Target, explodeRight1);
	Renderer::Instance()->PushSprite(EXPLOSION_SPRITE, right2Target, explodeRight2);
}


Bomb::~Bomb()
{
}
