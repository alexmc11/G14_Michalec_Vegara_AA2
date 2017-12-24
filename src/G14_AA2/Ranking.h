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
	Vector2 medidaTextoScore1, medidaTextoScore2, medidaTextoScore3, medidaTextoScore4, medidaTextoScore5, medidaTextoScore6, medidaTextoScore7, medidaTextoScore8, medidaTextoScore9, medidaTextoScore10;

	Text Name1, Name2, Name3, Name4, Name5, Name6, Name7, Name8, Name9, Name10;
	SDL_Rect Name1Rect, Name2Rect, Name3Rect, Name4Rect, Name5Rect, Name6Rect, Name7Rect, Name8Rect, Name9Rect, Name10Rect;
	Vector2 medidaTextoName1, medidaTextoName2, medidaTextoName3, medidaTextoName4, medidaTextoName5, medidaTextoName6, medidaTextoName7, medidaTextoName8, medidaTextoName9, medidaTextoName10;

	std::vector<playerData> auxVector;
	static bool comparePoints(const playerData &a, const playerData &b);
	bool returnMenu;
	Vector2 medidaTextMenu = Renderer::Instance()->GetTextureSize(TEXT_RETURNMENU);
	Vector2 medidaTextHigh = Renderer::Instance()->GetTextureSize(TEXT_RANKING2);
	void ponerNombre(int puntos);
	std::vector<playerData> Highscores;
	std::vector<playerData> ReadScores;
	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

