#include "Play.h"



Play::Play()
{
	bgPlay = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
}


Play::~Play()
{
}

void Play::Update()
{
}

void Play::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, bgPlay);
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, )
	Renderer::Instance()->Render();
}

void Play::HandleEvents()
{
}
