#pragma once
#include "Scene.h"
#include "Character.h"
#include "HUD.h"
#include "Map.h"
#include <SDL_mixer.h>
#include <time.h>

class Play : public Scene
{
public:
	Play();
	~Play();

	SDL_Rect bgPlay;
	bool audioStarted;
	Character *jugador1;
	Character *jugador2;

	HUD interfaz;

	Brick ladrillo;

	Map mapa;

	clock_t lastTime;

	float timeDown = 81;

	float deltaTime = 0;

	float timeUp = 0;

	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

