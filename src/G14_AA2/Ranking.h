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

	SDL_Rect returnMenuRect, HighscoresRect;

	Text Score1, Score2, Score3, Score4, Score5, Score6, Score7, Score8, Score9, Score10;
	SDL_Rect Score1Rect, Score2Rect, Score3Rect, Score4Rect, Score5Rect, Score6Rect, Score7Rect, Score8Rect, Score9Rect, Score10Rect;
	Vector2 ScoreTextSize1, ScoreTextSize2, ScoreTextSize3, ScoreTextSize4, ScoreTextSize5, ScoreTextSize6, ScoreTextSize7, ScoreTextSize8, ScoreTextSize9, ScoreTextSize10;

	Text Name1, Name2, Name3, Name4, Name5, Name6, Name7, Name8, Name9, Name10;
	SDL_Rect Name1Rect, Name2Rect, Name3Rect, Name4Rect, Name5Rect, Name6Rect, Name7Rect, Name8Rect, Name9Rect, Name10Rect;
	Vector2 NameTextSize1, NameTextSize2, NameTextSize3, NameTextSize4, NameTextSize5, NameTextSize6, NameTextSize7, NameTextSize8, NameTextSize9, NameTextSize10;

	static bool comparePoints(const playerData &a, const playerData &b);

	bool returnMenu;

	Vector2 MenuTextSize = Renderer::Instance()->GetTextureSize(TEXT_RETURNMENU);
	Vector2 HighscoreTextSize = Renderer::Instance()->GetTextureSize(TEXT_RANKING2);

	std::vector<playerData> auxVector;
	std::vector<playerData> Highscores;
	std::vector<playerData> ReadScores;

	void Update() override;
	void Draw() override;
	void HandleEvents() override;

};

