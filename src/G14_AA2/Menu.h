#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();
	SDL_Rect bgMenu;

	SDL_Surface *tmpSurf;

	//SDL_Texture *textTexture{ SDL_CreateTextureFromSurface(m_renderer, tmpSurf) };

	SDL_Rect textRect;

	void Update() override;
	void Draw() override; 
	void HandleEvents() override;
};

