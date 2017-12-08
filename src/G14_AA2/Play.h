#pragma once
#include "Scene.h"
#include "Character.h"
#include "HUD.h"

class Play : public Scene
{
public:
	Play();
	~Play();

	SDL_Rect bgPlay;

	Character jugador1;
	Character jugador2;

	HUD interfaz;

	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

