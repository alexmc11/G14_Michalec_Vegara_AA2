#pragma once
#include "Scene.h"
#include <iostream>
#include <SDL_mixer.h>

class Menu : public Scene
{
public:
	Menu();
	~Menu();
	SDL_Rect bgMenu;
	bool audioStarted;
	bool jugar;
	bool salir;
	bool mute, muted, done;
	SDL_Rect PlaytextRect, ExitTextRect, RankingTextRect, TitleTextRect, AudioTextRect;

	Vector2 medidaTextoPlay = Renderer::Instance()->GetTextureSize(TEXT_PLAY);
	Vector2 medidaTextoRanking = Renderer::Instance()->GetTextureSize(TEXT_RANKING);
	Vector2 medidaTextoExit = Renderer::Instance()->GetTextureSize(TEXT_EXIT);
	Vector2 medidaTextoTitle = Renderer::Instance()->GetTextureSize(TEXT_TITLE);
	Vector2 medidaTextoAudio = Renderer::Instance()->GetTextureSize(TEXT_AUDIO);

	void Update() override;
	void Draw() override; 
	void HandleEvents() override;
};

