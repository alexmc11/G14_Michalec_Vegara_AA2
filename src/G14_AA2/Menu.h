#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();
	SDL_Rect bgMenu;
	/*TTF_Font *font{ TTF_OpenFont("../../res/ttf/saiyan.ttf", 80) };

	SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font, "My first SDL game", SDL_Color{ 255, 150, 0, 255 }) };

	//SDL_Texture *textTexture{ SDL_CreateTextureFromSurface(m_renderer, tmpSurf) };

	SDL_Rect textRect{ 100, 50, tmpSurf->w, tmpSurf->h };*/

	void Update() override;
	void Draw() override; 
	void HandleEvents() override;
};

