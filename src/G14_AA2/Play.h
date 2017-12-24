#pragma once
#include "Scene.h"
#include "Character.h"
#include "Map.h"
#include "PowerUp.h"
#include "Ranking.h"
#include <SDL_mixer.h>
#include <time.h>
#include <sstream>
#include <string>

enum Levels {lvl1, lvl2};

class Play : public Scene
{
public:

	Play(Levels lvl);
	~Play();

	float timer = 0.f;
	float timer2 = 0.f;
	float timer3 = 0.f;

	float timerP2 = 0.f;
	float timer2P2 = 0.f;
	float timer3P2 = 0.f;

	bool audioStarted;

	Character *Player1;
	Character *Player2;

	Text time, livesP1, livesP2, pointsP1, pointsP2;
	SDL_Rect bgPlay, lives1, lives2, TimeRect, livesP1Rect, livesP2Rect, pointsP1Rect, pointsP2Rect, finalRect;
	Vector2 TimeTextSize, LivesTextSizeP1, LivesTextSizeP2, PointsTextSizeP1, PointsTextSizeP2;

	Vector2 LivesTextSize = Renderer::Instance()->GetTextureSize(TEXT_LIVES);
	Vector2 LivesTextSize2 = Renderer::Instance()->GetTextureSize(TEXT_LIVES2);
	Vector2 FinalTextSize = Renderer::Instance()->GetTextureSize(FINALTEXT);

	Levels level;

	Map map;

	PowerUp *bonus;

	bool power;
	bool speedUp, speedUp2;

	char buffer[50];

	clock_t lastTime;

	float timeDown;
	float deltaTime = 0;
	float timeUp = 0;

	bool damage = false;

	float frameTime = 0;

	bool collision(SDL_Rect* A, SDL_Rect* B);
	bool collisionIterator();
	bool collisionIterator2();
	void collisionMovement();
	void collisionMovement2();

	void powerUp(int posX, int posY);

	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

