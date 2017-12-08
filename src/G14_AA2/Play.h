#pragma once
#include "Scene.h"

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

