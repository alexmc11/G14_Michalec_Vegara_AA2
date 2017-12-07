#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();
	SDL_Rect bgMenu;
	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

