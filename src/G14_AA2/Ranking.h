#pragma once
#include "Scene.h"
#include <iostream>
class Ranking : public Scene
{
public:
	Ranking();
	~Ranking();
	SDL_Rect returnMenuRect;
	bool returnMenu;
	Vector2 medidaTextMenu = Renderer::Instance()->GetTextureSize(TEXT_RETURNMENU);
	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

