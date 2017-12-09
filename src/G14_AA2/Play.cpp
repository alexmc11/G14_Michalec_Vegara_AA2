#include "Play.h"



Play::Play()
{
	bgPlay = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	jugador1 = new Character(player1);
	jugador2 = new Character(player2);
	lastTime = clock();
}


Play::~Play()
{
}

void Play::Update()
{
	
	deltaTime = (clock() - lastTime);

	lastTime = clock();

	deltaTime /= CLOCKS_PER_SEC;

	timeDown -= deltaTime;

	std::cout << timeDown << std::endl;

	
}

void Play::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, bgPlay);
	mapa.DrawMap();
	mapa.DrawBricks();
	//Renderer::Instance()->PushImage(RECTANGULO_SPRITE, interfaz.BG);
	//Renderer::Instance()->PushImage(VIDAS1_SPRITE, interfaz.player1Vidas);
	//Renderer::Instance()->PushImage(VIDAS2_SPRITE, interfaz.player2Vidas);
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, jugador1->playerTarget, jugador1->playerRect);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, jugador2->playerTarget, jugador2->playerRect);
	Renderer::Instance()->Render();
}

void Play::HandleEvents()
{
	jugador1->movement();
	jugador2->movement();
	if (timeDown < timeUp)
	{
		state = GameState::GOTO;
	}
}
