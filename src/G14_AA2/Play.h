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


	Map mapa;
	char buffer[50];

	clock_t lastTime;

	float timeDown = 81;

	float deltaTime = 0;

	float timeUp = 0;

	clock_t lastTime2;

	float timeDown2 = 81;

	float deltaTime2 = 0;

	float frameTime = 0;

	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

