#pragma once
#include "Scene.h"
#include <iostream>
#include <SDL_mixer.h>



class Menu : public Scene
{

public:

	Menu();
	~Menu();

	bool audioStarted;
	bool play1, play2;
	bool exit;
	bool ranking;
	bool mute, muted, done;

	SDL_Rect bgMenu, Play1textRect, Play2textRect, ExitTextRect, RankingTextRect, TitleTextRect, AudioTextRect;

	Vector2 PlayTextSize1 = Renderer::Instance()->GetTextureSize(TEXT_PLAY1);
	Vector2 PlayTextSize2 = Renderer::Instance()->GetTextureSize(TEXT_PLAY2);
	Vector2 RankingTextSize = Renderer::Instance()->GetTextureSize(TEXT_RANKING);
	Vector2 ExitTextSize = Renderer::Instance()->GetTextureSize(TEXT_EXIT);
	Vector2 TitleTextSize = Renderer::Instance()->GetTextureSize(TEXT_TITLE);
	Vector2 AudioTextSize = Renderer::Instance()->GetTextureSize(TEXT_AUDIO);

	void Update() override;
	void Draw() override; 
	void HandleEvents() override;
};

