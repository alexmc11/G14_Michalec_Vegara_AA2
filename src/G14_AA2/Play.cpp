#include "Play.h"



Play::Play(Levels lvl)
{
	bgPlay = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	jugador1 = new Character(player1);
	jugador2 = new Character(player2);
	lastTime = clock();
	audioStarted = false;
	level = lvl;
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

	Text tiempo{ TEXT_TIME, std::to_string((int)timeDown),{ 127, 0, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, tiempo);
	medidaTextoTime = Renderer::Instance()->GetTextureSize(TEXT_TIME);
	TimeRect = { 345, 15, medidaTextoTime.x, medidaTextoTime.y };

	Text vidasP1{ TEXT_VIDAS1NUM, std::to_string(jugador1->vidas),{ 0, 0, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, vidasP1);
	medidaTextoVidasP1 = Renderer::Instance()->GetTextureSize(TEXT_VIDAS1NUM);
	vidasP1Rect = { 180, 15, medidaTextoVidasP1.x, medidaTextoVidasP1.y };

	Text vidasP2{ TEXT_VIDAS2NUM, std::to_string(jugador2->vidas),{ 255, 0, 0, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, vidasP2);
	medidaTextoVidasP2 = Renderer::Instance()->GetTextureSize(TEXT_VIDAS2NUM);
	vidasP2Rect = { 640, 15, medidaTextoVidasP2.x, medidaTextoVidasP2.y };

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

	if (level == lvl1)
	{
		mapa.DrawMap();
		mapa.DrawBricks();
	}
	else
	{

	}
	if (jugador1->hasbomb == true)
	{
		jugador1->bomba->placeBomb();
	}

	interfaz.DrawHud();
	Renderer::Instance()->PushImage(TEXT_TIME, TimeRect);
	Renderer::Instance()->PushImage(TEXT_VIDAS1NUM, vidasP1Rect);
	Renderer::Instance()->PushImage(TEXT_VIDAS2NUM, vidasP2Rect);
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, jugador1->playerTarget, jugador1->playerRect);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, jugador2->playerTarget, jugador2->playerRect);
	if (jugador1->explode == true)
	{
		jugador1->bomba->bombExplode(jugador1->bomba->posicionX, jugador1->bomba->posicionY);
		frameTime++;
		if (SCREEN_FPS / frameTime <= 9)
		{
			frameTime = 0;
			//Center
			if (jugador1->bomba->centerTarget.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->centerTarget.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
			//Up1
			if (jugador1->bomba->up1Target.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->up1Target.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
			//Up2
			if (jugador1->bomba->up2Target.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->up2Target.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
			//Down1
			if (jugador1->bomba->down1Target.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->down1Target.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
			//Down2
			if (jugador1->bomba->down2Target.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->down2Target.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
			//Right1
			if (jugador1->bomba->right1Target.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->right1Target.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
			//Right2
			if (jugador1->bomba->right2Target.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->right2Target.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
			//Left
			if (jugador1->bomba->left1Target.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->left1Target.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
			//Left
			if (jugador1->bomba->left2Taget.x <= jugador1->bomba->explodeImageSize.x)
			{
				jugador1->bomba->left2Taget.x += 48;
			}
			else
			{
				jugador1->explode = false;
				jugador1->hasbomb = false;
			}
		}
		
	}

	Renderer::Instance()->Render();

}

void Play::HandleEvents()
{
	jugador1->movement();
	if (level == lvl1)
	{
		jugador1->collisionMovement();
	}
	jugador2->movement();
	if (timeDown < timeUp || jugador1->vidas == 0 || jugador2->vidas == 0)
	{
		std::cout << "Se acab� el tiempo";
		Mix_CloseAudio();
		state = GameState::GOTO;
	}
}