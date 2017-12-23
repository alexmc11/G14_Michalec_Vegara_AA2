#pragma once
#include "Scene.h"
#include <iostream>
#include <fstream>
#include <algorithm>


struct playerData
{
	std::string name;
	int score;
};

class Ranking : public Scene
{
public:
	Ranking();
	~Ranking();
	SDL_Rect returnMenuRect;
	std::vector<playerData> auxVector;
	static bool comparePoints(const playerData &a, const playerData &b);
	bool returnMenu;
	Vector2 medidaTextMenu = Renderer::Instance()->GetTextureSize(TEXT_RETURNMENU);
	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

