#include "Play.h"



Play::Play()
{
	bgPlay = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	Map::Map();
	jugadores = new Character();
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
	Renderer::Instance()->PushImage(RECTANGULO_SPRITE, interfaz.BG);
	Renderer::Instance()->PushImage(VIDAS1_SPRITE, interfaz.player1Vidas);
	Renderer::Instance()->PushImage(VIDAS2_SPRITE, interfaz.player2Vidas);
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, jugadores->player1Target, jugadores->player1Rect);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, jugadores->player2Target, jugadores->player2Rect);
	Renderer::Instance()->Render();
}

void Play::HandleEvents()
{
	
}
