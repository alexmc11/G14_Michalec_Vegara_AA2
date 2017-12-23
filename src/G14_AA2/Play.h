#pragma once
#include "Scene.h"
#include "Character.h"
#include "HUD.h"
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
	SDL_Rect bgPlay;
	bool audioStarted;
	Character *jugador1;
	Character *jugador2;

	HUD interfaz;

	Text tiempo, vidasP1, vidasP2, pointsP1, pointsP2;
	SDL_Rect TimeRect, vidasP1Rect, vidasP2Rect, pointsP1Rect, pointsP2Rect;
	Vector2 medidaTextoTime, medidaTextoVidasP1, medidaTextoVidasP2, medidaTextoPointsP1, medidaTextoPointsP2;

	Levels level;
	Map mapa;
	PowerUp *bonus;
	Ranking clasif;
	bool power;
	bool speedUp;
	char buffer[50];

	clock_t lastTime;

	float timeDown = 81;

	float deltaTime = 0;

	float timeUp = 0;

	bool damage = false;

	clock_t lastTime2;

	float timeDown2 = 81;

	float deltaTime2 = 0;

	float frameTime = 0;

	void Update() override;
	void Draw() override;
	void HandleEvents() override;

	bool colisiones(SDL_Rect* A, SDL_Rect* B);

	bool iteradorcolisiones();

	void collisionMovement();

	void powerUp(int posX, int posY);
};

