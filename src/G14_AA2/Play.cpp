#include "Play.h"



Play::Play()
{
	bgPlay = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	jugador1 = new Character(player1);
	jugador2 = new Character(player2);
	lastTime = clock();
	audioStarted = false;
	char buffer[50];
	int texW = 0;
	int textH = 0;

	

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

	//std::cout << timeDown << std::endl;

	if (audioStarted == false)
	{
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
		Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/game_theme.mp3") };
		Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
		Mix_PlayMusic(soundtrack, -1);
		audioStarted = true;
	}
	if (jugador1->hasbomb == true)
	{
		timer += 0.05;
		if (timer > 12)
		{
			jugador1->explode = true;
			timer = 0;
		}
	}
}

void Play::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, bgPlay);

	mapa.DrawMap();
	mapa.DrawBricks();
	if (jugador1->hasbomb == true)
	{
		jugador1->bomba->placeBomb();
	}

	interfaz.DrawHud();
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, jugador1->playerTarget, jugador1->playerRect);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, jugador2->playerTarget, jugador2->playerRect);
	if (jugador1->explode == true)
	{
		jugador1->bomba->bombExplode(jugador1->bomba->posicionX, jugador1->bomba->posicionY);
		jugador1->explode = false;
		jugador1->hasbomb = false;
	}

	Renderer::Instance()->Render();

}

void Play::HandleEvents()
{
	jugador1->movement();
	jugador1->collisionMovement();
	jugador2->movement();
	if (timeDown < timeUp || jugador1->vidas == 0 || jugador2->vidas == 0)
	{
		std::cout << "Se acabó el tiempo";
		Mix_CloseAudio();
		state = GameState::GOTO;
	}
}