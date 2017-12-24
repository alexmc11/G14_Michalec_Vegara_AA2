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
	power = false;
	int textH = 0;
	if (level == lvl1)
	{
		mapa.ReadXML1();
		jugador1->vidas = mapa.cantidadVidas;
		jugador2->vidas = mapa.cantidadVidas;
		timeDown = mapa.tiempo;
	}
	else
	{
		mapa.ReadXML2();//
		jugador1->vidas = mapa.cantidadVidas;
		jugador2->vidas = mapa.cantidadVidas;
		timeDown = mapa.tiempo;
	}
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

	Text pointsP1{ TEXT_POINTS1NUM, std::to_string(jugador1->points),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, pointsP1);
	medidaTextoPointsP1 = Renderer::Instance()->GetTextureSize(TEXT_POINTS1NUM);
	pointsP1Rect = { 280, 15, medidaTextoPointsP1.x, medidaTextoPointsP1.y };

	Text pointsP2{ TEXT_POINTS2NUM, std::to_string(jugador2->points),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, pointsP2);
	medidaTextoPointsP2 = Renderer::Instance()->GetTextureSize(TEXT_POINTS2NUM);
	pointsP2Rect = { 420, 15, medidaTextoPointsP2.x, medidaTextoPointsP2.y };

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

	if (jugador1->hasimmunity == true)
	{
		timer2 += 0.05;
		if (timer2 > 30)
		{
			std::cout << "immunity reset" << std::endl;
			jugador1->hasimmunity = false;
			timer2 = 0;
		}
	}

	if (speedUp == true)
	{
		timer3 += 0.05;
		if (timer3 > 30)
		{
			std::cout << "speed reset" << std::endl;
			jugador1->speed = 2;
			speedUp = false;
			timer3 = 0;
		}
	}
}

void Play::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, bgPlay);

	if (level == lvl1)
	{
		mapa.DrawMap1();
		mapa.DrawBricks1();
	}
	else
	{
		mapa.DrawMap1();
		mapa.DrawBricks1();
	}
	if (jugador1->hasbomb == true)
	{
		jugador1->bomba->placeBomb();
	}

	interfaz.DrawHud();
	Renderer::Instance()->PushImage(TEXT_TIME, TimeRect);
	Renderer::Instance()->PushImage(TEXT_VIDAS1NUM, vidasP1Rect);
	Renderer::Instance()->PushImage(TEXT_VIDAS2NUM, vidasP2Rect);
	Renderer::Instance()->PushImage(TEXT_POINTS1NUM, pointsP1Rect);
	Renderer::Instance()->PushImage(TEXT_POINTS2NUM, pointsP2Rect);
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, jugador1->playerTarget, jugador1->playerRect);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, jugador2->playerTarget, jugador2->playerRect);
	if (power == true)
	{
		if (bonus->active == true)
		{
			bonus->drawPowerUp();
			if (colisiones(&jugador1->playerRect, &bonus->powerupRect) == 1)
			{
				if (bonus->powerUpType == 1 && speedUp != true)
				{
					std::cout << "speed active" << std::endl;
					jugador1->speed*=2;
					speedUp = true;
				}
				if (bonus->powerUpType == 2)
				{
					std::cout << "immunity active" << std::endl;
					timer2 = 0;
					jugador1->hasimmunity = true;
				}
				bonus->active = false;
				delete bonus;
			}
		}
		
	}
	if (jugador1->explode == true)
	{
		jugador1->bomba->bombExplode(jugador1->bomba->posicionX, jugador1->bomba->posicionY);
		if (jugador1->hasimmunity == false && damage == false)
		{
#pragma region 1suicidio
			if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeCenter) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
			else if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeUp1) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
			else if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeUp2) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
			else if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeDown1) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
			else if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeDown2) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
			else if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeLeft1) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
			else if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeLeft2) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
			else if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeRight1) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
			else if (colisiones(&jugador1->playerRect, &jugador1->bomba->explodeRight2) == 1)
			{
				jugador1->vidas--;
				damage = true;
			}
#pragma endregion
#pragma region 1daña2
			if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeCenter) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
			else if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeUp1) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
			else if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeUp2) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
			else if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeDown1) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
			else if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeDown2) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
			else if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeLeft1) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
			else if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeLeft2) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
			else if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeRight1) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
			else if (colisiones(&jugador2->playerRect, &jugador1->bomba->explodeRight2) == 1)
			{
				jugador2->vidas--;
				jugador1->points += 100;
				damage = true;
			}
#pragma endregion
		}
		for (int i = 0; i < mapa.MurosDestruibles.size(); i++)
		{
			if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->bomba->explodeUp1) == 1)
			{
				powerUp(mapa.MurosDestruibles[i].destructibleBrickRect.x, mapa.MurosDestruibles[i].destructibleBrickRect.y);
				mapa.MurosDestruibles.erase(mapa.MurosDestruibles.begin() + i);
				jugador1->points += 15;
			}
			else if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->bomba->explodeUp2) == 1)
			{
				powerUp(mapa.MurosDestruibles[i].destructibleBrickRect.x, mapa.MurosDestruibles[i].destructibleBrickRect.y);
				mapa.MurosDestruibles.erase(mapa.MurosDestruibles.begin() + i);
				jugador1->points += 15;
			}
			else if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->bomba->explodeDown1) == 1)
			{
				powerUp(mapa.MurosDestruibles[i].destructibleBrickRect.x, mapa.MurosDestruibles[i].destructibleBrickRect.y);
				mapa.MurosDestruibles.erase(mapa.MurosDestruibles.begin() + i);
				jugador1->points += 15;
			}
			else if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->bomba->explodeDown2) == 1)
			{
				powerUp(mapa.MurosDestruibles[i].destructibleBrickRect.x, mapa.MurosDestruibles[i].destructibleBrickRect.y);
				mapa.MurosDestruibles.erase(mapa.MurosDestruibles.begin() + i);
				jugador1->points += 15;
			}
			else if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->bomba->explodeLeft1) == 1)
			{
				powerUp(mapa.MurosDestruibles[i].destructibleBrickRect.x, mapa.MurosDestruibles[i].destructibleBrickRect.y);
				mapa.MurosDestruibles.erase(mapa.MurosDestruibles.begin() + i);
				jugador1->points += 15;
			}
			else if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->bomba->explodeLeft2) == 1)
			{
				powerUp(mapa.MurosDestruibles[i].destructibleBrickRect.x, mapa.MurosDestruibles[i].destructibleBrickRect.y);
				mapa.MurosDestruibles.erase(mapa.MurosDestruibles.begin() + i);
				jugador1->points += 15;
			}
			else if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->bomba->explodeRight1) == 1)
			{
				powerUp(mapa.MurosDestruibles[i].destructibleBrickRect.x, mapa.MurosDestruibles[i].destructibleBrickRect.y);
				mapa.MurosDestruibles.erase(mapa.MurosDestruibles.begin() + i);
				jugador1->points += 15;
			}
			else if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->bomba->explodeRight2) == 1)
			{
				powerUp(mapa.MurosDestruibles[i].destructibleBrickRect.x, mapa.MurosDestruibles[i].destructibleBrickRect.y);
				mapa.MurosDestruibles.erase(mapa.MurosDestruibles.begin() + i);
				jugador1->points += 15;
			}
		}
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
				damage = false;
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
				damage = false;
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
				damage = false;
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
				damage = false;
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
				damage = false;
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
				damage = false;
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
				damage = false;
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
				damage = false;
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
				damage = false;
			}
		}
		
	}

	Renderer::Instance()->Render();

}

bool Play::colisiones(SDL_Rect* A, SDL_Rect* B)
{
	if (A->y >= (B->y + B->h))
	{
		return 0;
	}
	if (A->x >= (B->x + B->w))
	{
		return 0;
	}
	if ((A->y + A->h) <= B->y)
	{
		return 0;
	}
	if ((A->x + A->w) <= B->x)
	{
		return 0;
	}

	return 1;

}

bool Play::iteradorcolisiones()
{
	for (int i = 0; i < mapa.MurosFijos.size(); i++)
	{
		if (colisiones(&mapa.MurosFijos[i].fixBrickRect, &jugador1->playerRect) == 1)
		{
			return true;
		}
	}
	for (int i = 0; i < mapa.MurosDestruibles.size(); i++)
	{
		if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &jugador1->playerRect) == 1)
		{
			return true;
		}
	}
	return false;
}

void Play::collisionMovement()
{
	if (jugador1->lastkey == UP)
	{
		if (iteradorcolisiones() == true)
		{
			jugador1->posicion.y += jugador1->speed;
			jugador1->lastkey = DEFAULT;
		}
	}
	if (jugador1->lastkey == DOWN)
	{
		if (iteradorcolisiones() == true)
		{
			jugador1->posicion.y -= jugador1->speed;
			jugador1->lastkey = DEFAULT;
		}
	}
	if (jugador1->lastkey == LEFT)
	{
		if (iteradorcolisiones() == true)
		{
			jugador1->posicion.x += jugador1->speed;
			jugador1->lastkey = DEFAULT;
		}
	}
	if (jugador1->lastkey == RIGHT)
	{
		if (iteradorcolisiones() == true)
		{
			jugador1->posicion.x -= jugador1->speed;
			jugador1->lastkey = DEFAULT;
		}
	}
}

void Play::powerUp(int posX, int posY)
{
	int result = rand() % 101;
	if (result < 60)
	{
		bonus = new PowerUp();
		bonus->createPowerUp(posX, posY);
		power = true;
	}
}

void Play::HandleEvents()
{
	jugador1->movement();

	collisionMovement();

	jugador2->movement();
	if (timeDown < timeUp || jugador1->vidas <= 0 || jugador2->vidas <= 0)
	{
		Mix_CloseAudio();

		std::ofstream fsalida("../../res/files/ranking.bin", std::ios::app|std::ios_base::binary);
		std::string name;
		std::cout << std::endl << "escribe tu nombre: ";
		std::cin >> name;
		int points = jugador1->points;

		if (fsalida.good())
		{
				fsalida.write(name.c_str(), name.size()); // write string to binary file
				fsalida.write("\0", sizeof(char)); // null end string for easier reading
				fsalida.write(reinterpret_cast<char*>(&points), sizeof(points)); // write int to binary file
				fsalida.close();
		}


		state = GameState::GOTO;
	}
}