#include "Play.h"



Play::Play(Levels lvl)
{
	lives1 = { 45, 15, LivesTextSize.x, LivesTextSize.y };
	lives2 = { 500, 15, LivesTextSize2.x, LivesTextSize2.y };
	finalRect = { 50, 330, FinalTextSize.x, FinalTextSize.y };
	bgPlay = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

	Player1 = new Character(player1);
	Player2 = new Character(player2);
	lastTime = clock();
	audioStarted = false;
	level = lvl;
	char buffer[50];
	int texW = 0;
	power = false;
	int textH = 0;
	if (level == lvl1)
	{
		map.ReadXML1();
		Player1->lives = map.livesNum;
		Player2->lives = map.livesNum;
		timeDown = map.time;
	}
	else
	{
		map.ReadXML2();
		Player1->lives = map.livesNum;
		Player2->lives = map.livesNum;
		timeDown = map.time;
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
	Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, tiempo);
	TimeTextSize = Renderer::Instance()->GetTextureSize(TEXT_TIME);
	TimeRect = { 345, 15, TimeTextSize.x, TimeTextSize.y };

	Text vidasP1{ TEXT_LIVES1NUM, std::to_string(Player1->lives),{ 0, 0, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, vidasP1);
	LivesTextSizeP1 = Renderer::Instance()->GetTextureSize(TEXT_LIVES1NUM);
	livesP1Rect = { 180, 15, LivesTextSizeP1.x, LivesTextSizeP1.y };

	Text vidasP2{ TEXT_LIVES2NUM, std::to_string(Player2->lives),{ 255, 0, 0, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, vidasP2);
	LivesTextSizeP2 = Renderer::Instance()->GetTextureSize(TEXT_LIVES2NUM);
	livesP2Rect = { 640, 15, LivesTextSizeP2.x, LivesTextSizeP2.y };

	Text pointsP1{ TEXT_POINTS1NUM, std::to_string(Player1->points),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, pointsP1);
	PointsTextSizeP1 = Renderer::Instance()->GetTextureSize(TEXT_POINTS1NUM);
	pointsP1Rect = { 280, 15, PointsTextSizeP1.x, PointsTextSizeP1.y };

	Text pointsP2{ TEXT_POINTS2NUM, std::to_string(Player2->points),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, pointsP2);
	PointsTextSizeP2 = Renderer::Instance()->GetTextureSize(TEXT_POINTS2NUM);
	pointsP2Rect = { 420, 15, PointsTextSizeP2.x, PointsTextSizeP2.y };

	if (audioStarted == false)
	{
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
		Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/game_theme.mp3") };
		Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
		Mix_PlayMusic(soundtrack, -1);
		audioStarted = true;
	}
	if (Player1->hasbomb == true)
	{
		timer += 0.05;
		if (timer > 12)
		{
			Player1->explode = true;
			timer = 0;
		}
	}

	if (Player2->hasbomb == true)
	{
		timerP2 += 0.05;
		if (timerP2 > 12)
		{
			Player2->explode = true;
			timerP2 = 0;
		}
	}

	if (Player1->hasimmunity == true)
	{
		timer2 += 0.05;
		if (timer2 > 30)
		{
			std::cout << "immunity player 1 reset" << std::endl;
			Player1->hasimmunity = false;
			timer2 = 0;
		}
	}

	if (Player2->hasimmunity == true)
	{
		timer2P2 += 0.05;
		if (timer2P2 > 30)
		{
			std::cout << "immunity player 2 reset" << std::endl;
			Player2->hasimmunity = false;
			timer2P2 = 0;
		}
	}

	if (speedUp == true)
	{
		timer3 += 0.05;
		if (timer3 > 30)
		{
			std::cout << "speed player 1 reset" << std::endl;
			Player1->speed = 2;
			speedUp = false;
			timer3 = 0;
		}
	}

	if (speedUp2 == true)
	{
		timer3P2 += 0.05;
		if (timer3P2 > 30)
		{
			std::cout << "speed player 2 reset" << std::endl;
			Player2->speed = 2;
			speedUp2 = false;
			timer3P2 = 0;
		}
	}
}

void Play::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, bgPlay);

	map.DrawFixBricks();
	map.DrawDesBricks();

	if (Player1->hasbomb == true)
	{
		Player1->bomb->placeBomb();
	}

	if (Player2->hasbomb == true)
	{
		Player2->bomb->placeBomb();
	}

	Renderer::Instance()->PushImage(TEXT_TIME, TimeRect);
	Renderer::Instance()->PushImage(TEXT_LIVES1NUM, livesP1Rect);
	Renderer::Instance()->PushImage(TEXT_LIVES2NUM, livesP2Rect);
	Renderer::Instance()->PushImage(TEXT_POINTS1NUM, pointsP1Rect);
	Renderer::Instance()->PushImage(TEXT_POINTS2NUM, pointsP2Rect);
	Renderer::Instance()->PushImage(TEXT_LIVES, lives1);
	Renderer::Instance()->PushImage(TEXT_LIVES2, lives2);
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, Player1->playerTarget, Player1->playerRect);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, Player2->playerTarget, Player2->playerRect);
	if (power == true)
	{
		if (bonus->active == true)
		{
			bonus->drawPowerUp();
			if (collision(&Player1->playerRect, &bonus->powerupRect) == 1)
			{
				if (bonus->powerUpType == 1 && speedUp != true)
				{
					std::cout << "speed player 1 active" << std::endl;
					Player1->speed*=2;
					speedUp = true;
				}
				if (bonus->powerUpType == 2)
				{
					std::cout << "immunity player 1 active" << std::endl;
					timer2 = 0;
					Player1->hasimmunity = true;
				}
				bonus->active = false;
				delete bonus;
			}
			if (collision(&Player2->playerRect, &bonus->powerupRect) == 1)
			{
				if (bonus->powerUpType == 1 && speedUp != true)
				{
					std::cout << "speed player 2 active" << std::endl;
					Player2->speed *= 2;
					speedUp2 = true;
				}
				if (bonus->powerUpType == 2)
				{
					std::cout << "immunity player 2 active" << std::endl;
					timer2P2 = 0;
					Player2->hasimmunity = true;
				}
				bonus->active = false;
				delete bonus;
			}
		}
		
	}
	if (Player1->explode == true)
	{
		Player1->bomb->bombExplode(Player1->bomb->PosX, Player1->bomb->PosY);
		if (Player1->hasimmunity == false && damage == false)
		{
			if (collision(&Player1->playerRect, &Player1->bomb->explodeCenter) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player1->bomb->explodeUp1) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player1->bomb->explodeUp2) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player1->bomb->explodeDown1) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player1->bomb->explodeDown2) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player1->bomb->explodeLeft1) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player1->bomb->explodeLeft2) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player1->bomb->explodeRight1) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player1->bomb->explodeRight2) == 1)
			{
				Player1->lives--;
				damage = true;
			}
			if (collision(&Player2->playerRect, &Player1->bomb->explodeCenter) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player1->bomb->explodeUp1) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player1->bomb->explodeUp2) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player1->bomb->explodeDown1) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player1->bomb->explodeDown2) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player1->bomb->explodeLeft1) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player1->bomb->explodeLeft2) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player1->bomb->explodeRight1) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player1->bomb->explodeRight2) == 1)
			{
				Player2->lives--;
				Player1->points += 100;
				damage = true;
			}
		}
		for (int i = 0; i < map.DesBricks.size(); i++)
		{
			if (collision(&map.DesBricks[i].desBrickRect, &Player1->bomb->explodeUp1) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player1->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player1->bomb->explodeUp2) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player1->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player1->bomb->explodeDown1) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player1->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player1->bomb->explodeDown2) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player1->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player1->bomb->explodeLeft1) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player1->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player1->bomb->explodeLeft2) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player1->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player1->bomb->explodeRight1) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player1->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player1->bomb->explodeRight2) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player1->points += 15;
			}
		}
		frameTime++;
		if (SCREEN_FPS / frameTime <= 9)
		{
			frameTime = 0;
			//Center
			if (Player1->bomb->centerTarget.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->centerTarget.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
			//Up1
			if (Player1->bomb->up1Target.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->up1Target.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
			//Up2
			if (Player1->bomb->up2Target.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->up2Target.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
			//Down1
			if (Player1->bomb->down1Target.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->down1Target.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
			//Down2
			if (Player1->bomb->down2Target.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->down2Target.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
			//Right1
			if (Player1->bomb->right1Target.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->right1Target.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
			//Right2
			if (Player1->bomb->right2Target.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->right2Target.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
			//Left
			if (Player1->bomb->left1Target.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->left1Target.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
			//Left
			if (Player1->bomb->left2Taget.x <= Player1->bomb->explodeImageSize.x)
			{
				Player1->bomb->left2Taget.x += 48;
			}
			else
			{
				Player1->explode = false;
				Player1->hasbomb = false;
				damage = false;
			}
		}
		
	}

	if (Player2->explode == true)
	{
		Player2->bomb->bombExplode(Player2->bomb->PosX, Player2->bomb->PosY);
		if (Player2->hasimmunity == false && damage == false)
		{
			if (collision(&Player2->playerRect, &Player2->bomb->explodeCenter) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player2->bomb->explodeUp1) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player2->bomb->explodeUp2) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player2->bomb->explodeDown1) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player2->bomb->explodeDown2) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player2->bomb->explodeLeft1) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player2->bomb->explodeLeft2) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player2->bomb->explodeRight1) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			else if (collision(&Player2->playerRect, &Player2->bomb->explodeRight2) == 1)
			{
				Player2->lives--;
				damage = true;
			}
			if (collision(&Player1->playerRect, &Player2->bomb->explodeCenter) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player2->bomb->explodeUp1) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player2->bomb->explodeUp2) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player2->bomb->explodeDown1) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player2->bomb->explodeDown2) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player2->bomb->explodeLeft1) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player2->bomb->explodeLeft2) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player2->bomb->explodeRight1) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
			else if (collision(&Player1->playerRect, &Player2->bomb->explodeRight2) == 1)
			{
				Player1->lives--;
				Player2->points += 100;
				damage = true;
			}
		}
		for (int i = 0; i < map.DesBricks.size(); i++)
		{
			if (collision(&map.DesBricks[i].desBrickRect, &Player2->bomb->explodeUp1) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player2->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player2->bomb->explodeUp2) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player2->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player2->bomb->explodeDown1) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player2->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player2->bomb->explodeDown2) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player2->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player2->bomb->explodeLeft1) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player2->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player2->bomb->explodeLeft2) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player2->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player2->bomb->explodeRight1) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player2->points += 15;
			}
			else if (collision(&map.DesBricks[i].desBrickRect, &Player2->bomb->explodeRight2) == 1)
			{
				powerUp(map.DesBricks[i].desBrickRect.x, map.DesBricks[i].desBrickRect.y);
				map.DesBricks.erase(map.DesBricks.begin() + i);
				Player2->points += 15;
			}
		}
		frameTime++;
		if (SCREEN_FPS / frameTime <= 9)
		{
			frameTime = 0;
			//Center
			if (Player2->bomb->centerTarget.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->centerTarget.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
			//Up1
			if (Player2->bomb->up1Target.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->up1Target.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
			//Up2
			if (Player2->bomb->up2Target.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->up2Target.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
			//Down1
			if (Player2->bomb->down1Target.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->down1Target.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
			//Down2
			if (Player2->bomb->down2Target.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->down2Target.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
			//Right1
			if (Player2->bomb->right1Target.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->right1Target.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
			//Right2
			if (Player2->bomb->right2Target.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->right2Target.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
			//Left
			if (Player2->bomb->left1Target.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->left1Target.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
			//Left
			if (Player2->bomb->left2Taget.x <= Player2->bomb->explodeImageSize.x)
			{
				Player2->bomb->left2Taget.x += 48;
			}
			else
			{
				Player2->explode = false;
				Player2->hasbomb = false;
				damage = false;
			}
		}

	}

	Renderer::Instance()->Render();

}

bool Play::collision(SDL_Rect* A, SDL_Rect* B)
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

bool Play::collisionIterator()
{
	for (int i = 0; i < map.FixBricks.size(); i++)
	{
		if (collision(&map.FixBricks[i].fixBrickRect, &Player1->playerRect) == 1)
		{
			return true;
		}
	}
	for (int i = 0; i < map.DesBricks.size(); i++)
	{
		if (collision(&map.DesBricks[i].desBrickRect, &Player1->playerRect) == 1)
		{
			return true;
		}
	}
	return false;
}

bool Play::collisionIterator2()
{
	for (int i = 0; i < map.FixBricks.size(); i++)
	{
		if (collision(&map.FixBricks[i].fixBrickRect, &Player2->playerRect) == 1)
		{
			return true;
		}
	}
	for (int i = 0; i < map.DesBricks.size(); i++)
	{
		if (collision(&map.DesBricks[i].desBrickRect, &Player2->playerRect) == 1)
		{
			return true;
		}
	}
	return false;
}

void Play::collisionMovement()
{
	if (Player1->lastkey == UP)
	{
		if (collisionIterator() == true)
		{
			Player1->position.y += Player1->speed;
			Player1->lastkey = DEFAULT;
		}
	}
	if (Player1->lastkey == DOWN)
	{
		if (collisionIterator() == true)
		{
			Player1->position.y -= Player1->speed;
			Player1->lastkey = DEFAULT;
		}
	}
	if (Player1->lastkey == LEFT)
	{
		if (collisionIterator() == true)
		{
			Player1->position.x += Player1->speed;
			Player1->lastkey = DEFAULT;
		}
	}
	if (Player1->lastkey == RIGHT)
	{
		if (collisionIterator() == true)
		{
			Player1->position.x -= Player1->speed;
			Player1->lastkey = DEFAULT;
		}
	}
}

void Play::collisionMovement2()
{
	if (Player2->lastkey == UP)
	{
		if (collisionIterator2() == true)
		{
			Player2->position.y += Player2->speed;
			Player2->lastkey = DEFAULT;
		}
	}
	if (Player2->lastkey == DOWN)
	{
		if (collisionIterator2() == true)
		{
			Player2->position.y -= Player2->speed;
			Player2->lastkey = DEFAULT;
		}
	}
	if (Player2->lastkey == LEFT)
	{
		if (collisionIterator2() == true)
		{
			Player2->position.x += Player2->speed;
			Player2->lastkey = DEFAULT;
		}
	}
	if (Player2->lastkey == RIGHT)
	{
		if (collisionIterator2() == true)
		{
			Player2->position.x -= Player2->speed;
			Player2->lastkey = DEFAULT;
		}
	}
}

void Play::powerUp(int posX, int posY)
{
	int result = rand() % 101;
	if (result < 21)
	{
		bonus = new PowerUp();
		bonus->createPowerUp(posX, posY);
		power = true;
	}
}

void Play::HandleEvents()
{

	Player1->movement();

	collisionMovement();

	Player2->movement();

	collisionMovement2();

	if (timeDown < timeUp || Player1->lives <= 0 || Player2->lives <= 0)
	{
		Renderer::Instance()->Clear();
		Renderer::Instance()->PushImage(FINALTEXT, finalRect);
		Renderer::Instance()->Render();
		Mix_CloseAudio();
		int points;
		bool draw = false;

		if (Player1->points > Player2->points)
		{
			points = Player1->points;
			std::cout << "Player 1 Won!" << std::endl;
		}
		else if (Player2->points > Player1->points)
		{
			points = Player2->points;
			std::cout << "Player 2 Won!" << std::endl;
		}
		else
		{
			draw = true;
			std::cout << "Draw!" << std::endl;
		}

		std::ofstream fsalida("../../res/files/ranking.bin", std::ios::app|std::ios_base::binary);
		std::string name;
		if (draw == false)
		{
			std::cout << std::endl << "Write your name: ";
			std::cin >> name;
			std::cout << std::endl;
			std::cout << "Name registered succesfully!" << std::endl;
			std::cout << std::endl;
		}

		

		if (fsalida.good() && draw == false)
		{
				fsalida.write(name.c_str(), name.size()); // write string to binary file
				fsalida.write("\0", sizeof(char)); // null end string for easier reading
				fsalida.write(reinterpret_cast<char*>(&points), sizeof(points)); // write int to binary file				
		}
		fsalida.close();
		
		state = GameState::GOTO;

	}
}