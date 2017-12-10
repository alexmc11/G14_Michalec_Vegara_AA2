#include "Play.h"



Play::Play()
{
	bgPlay = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	tiempoRect = { 400, 15, medidaImagen.x, medidaImagen.y };
	jugador1 = new Character(player1);
	jugador2 = new Character(player2);
	lastTime = clock();
	audioStarted = false;
	Text tiempo{ TEXT_TIEMPO, time_str,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS, tiempo);
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

	time_str = std::to_string(timeDown);

	//std::cout << timeDown << std::endl;

	if (audioStarted == false)
	{
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
		Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/game_theme.mp3") };
		Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
		Mix_PlayMusic(soundtrack, -1);
		audioStarted = true;
	}
	
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
	if (jugador1->hasbomb == true)
	{
		jugador1->bomba->placeBomb();
	}
	
	interfaz.DrawHud();
	Renderer::Instance()->PushImage(TEXT_TIEMPO, tiempoRect);
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, jugador1->playerTarget, jugador1->playerRect);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, jugador2->playerTarget, jugador2->playerRect);
	if (jugador1->explode == true)
	{
		jugador1->bomba->bombExplode(jugador1->bomba->posicionX, jugador1->bomba->posicionY);
		jugador1->explode = false;
	}
	Renderer::Instance()->Render();
	
}

void Play::HandleEvents()
{
	jugador1->movement();
	jugador1->movement2();
	jugador2->movement();
	if (timeDown < timeUp || jugador1->vidas == 0 || jugador2->vidas == 0)
	{
		Mix_CloseAudio();
		state = GameState::GOTO;
	}
}
