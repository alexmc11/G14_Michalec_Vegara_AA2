#include "Play.h"



Play::Play()
{
	bgPlay = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, bgPlay);
	Map::Map();
	Renderer::Instance()->PushImage(RECTANGULO_SPRITE, interfaz.BG);
	Renderer::Instance()->PushImage(VIDAS1_SPRITE, interfaz.player1Vidas);
	Renderer::Instance()->PushImage(VIDAS2_SPRITE, interfaz.player2Vidas);
}


Play::~Play()
{
}

void Play::Update()
{
}

void Play::Draw()
{
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, jugador1.player1Rect, jugador1.player1Position);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, jugador2.player2Rect, jugador2.player2Position);
	Renderer::Instance()->Render();
}

void Play::HandleEvents()
{
}
