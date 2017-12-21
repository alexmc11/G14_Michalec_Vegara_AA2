#pragma once
#include "Scene.h"
#include "Character.h"
#include "HUD.h"
#include "Map.h"
#include <SDL_mixer.h>
#include <time.h>
#include <sstream>
#include <string>

class Play : public Scene
{
public:
	Play();
	~Play();

	float timer = 0.f;
	SDL_Rect bgPlay;
	bool audioStarted;
	Character *jugador1;
	Character *jugador2;

	HUD interfaz;

	Text tiempo, vidasP1, vidasP2;
	SDL_Rect TimeRect, vidasP1Rect, vidasP2Rect;
	Vector2 medidaTextoTime, medidaTextoVidasP1, medidaTextoVidasP2;

	Map mapa;
	char buffer[50];

	clock_t lastTime;

	float timeDown = 81;

	float deltaTime = 0;

	float timeUp = 0;

	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

