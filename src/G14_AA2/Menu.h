#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();
	SDL_Rect bgMenu;

	SDL_Surface *tmpSurf;

	SDL_Rect PlaytextRect, ExitTextRect, RankingTextRect;

	Vector2 medidaTextoPlay = Renderer::Instance()->GetTextureSize(TEXT_PLAY);
	Vector2 medidaTextoRanking = Renderer::Instance()->GetTextureSize(TEXT_RANKING);
	Vector2 medidaTextoExit = Renderer::Instance()->GetTextureSize(TEXT_EXIT);

	void Update() override;
	void Draw() override; 
	void HandleEvents() override;
};

