#pragma once
#include "Scene.h"
#include "Character.h"

class Play : public Scene
{
public:
	Play();
	~Play();

	SDL_Rect bgPlay;

	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

