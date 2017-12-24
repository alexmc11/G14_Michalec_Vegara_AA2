#include "Ranking.h"

Ranking::Ranking()
{
	returnMenuRect = { 20, 650, MenuTextSize.x, MenuTextSize.y };
	HighscoresRect = { SCREEN_WIDTH / 4, 15, HighscoreTextSize.x, HighscoreTextSize.y };
	returnMenu = false;

	std::string auxname;
	int auxscore = 0;
	playerData aux;

	std::ifstream fentrada("../../res/files/ranking.bin", std::ios_base::binary);

	if (fentrada.good())
	{
		for (int i = 0; fentrada.eof() != true; i++)
		{
			std::getline(fentrada, auxname, '\0');
			fentrada.read(reinterpret_cast<char *>(&auxscore), sizeof(auxscore));
			aux = { auxname, auxscore };
			ReadScores.push_back(aux);
		}
		fentrada.close();
	}
	if (ReadScores.size() > 1)
	{
		ReadScores.erase(ReadScores.end() - 1);
	}

	std::sort(ReadScores.begin(), ReadScores.end(), comparePoints);

	std::cout << std::endl;
	std::cout << "All Scores List: " << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < ReadScores.size(); i++)
	{
		std::cout << "Player " << ReadScores[i].name << " score: " << ReadScores[i].score << std::endl;
	}
	{
		if (ReadScores.size() > 0)
		{
			Text Name1{ NAME1, ReadScores[0].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name1);
			NameTextSize1 = Renderer::Instance()->GetTextureSize(NAME1);
			Name1Rect = { 100, 100, NameTextSize1.x, NameTextSize1.y };
		}
		if (ReadScores.size() > 1)
		{
			Text Name2{ NAME2, ReadScores[1].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name2);
			NameTextSize2 = Renderer::Instance()->GetTextureSize(NAME2);
			Name2Rect = { 100, 150, NameTextSize2.x, NameTextSize2.y };
		}
		if (ReadScores.size() > 2)
		{
			Text Name3{ NAME3, ReadScores[2].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name3);
			NameTextSize3 = Renderer::Instance()->GetTextureSize(NAME3);
			Name3Rect = { 100, 200, NameTextSize3.x, NameTextSize3.y };
		}
		if (ReadScores.size() > 3)
		{
			Text Name4{ NAME4, ReadScores[3].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name4);
			NameTextSize4 = Renderer::Instance()->GetTextureSize(NAME4);
			Name4Rect = { 100, 250, NameTextSize4.x, NameTextSize4.y };
		}
		if (ReadScores.size() > 4)
		{
			Text Name5{ NAME5, ReadScores[4].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name5);
			NameTextSize5 = Renderer::Instance()->GetTextureSize(NAME5);
			Name5Rect = { 100, 300, NameTextSize5.x, NameTextSize5.y };
		}
		if (ReadScores.size() > 5)
		{
			Text Name6{ NAME6, ReadScores[5].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name6);
			NameTextSize6 = Renderer::Instance()->GetTextureSize(NAME6);
			Name6Rect = { 100, 350, NameTextSize6.x, NameTextSize6.y };
		}
		if (ReadScores.size() > 6)
		{
			Text Name7{ NAME7, ReadScores[6].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name7);
			NameTextSize7 = Renderer::Instance()->GetTextureSize(NAME7);
			Name7Rect = { 100, 400, NameTextSize7.x, NameTextSize7.y };
		}
		if (ReadScores.size() > 7)
		{
			Text Name8{ NAME8, ReadScores[7].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name8);
			NameTextSize8 = Renderer::Instance()->GetTextureSize(NAME8);
			Name8Rect = { 100, 450, NameTextSize8.x, NameTextSize8.y };
		}
		if (ReadScores.size() > 8)
		{
			Text Name9{ NAME9, ReadScores[8].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name9);
			NameTextSize9 = Renderer::Instance()->GetTextureSize(NAME9);
			Name9Rect = { 100, 500, NameTextSize9.x, NameTextSize9.y };
		}
		if (ReadScores.size() > 9)
		{
			Text Name10{ NAME10, ReadScores[9].name,{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Name10);
			NameTextSize10 = Renderer::Instance()->GetTextureSize(NAME10);
			Name10Rect = { 100, 550, NameTextSize10.x, NameTextSize10.y };
		}
		if (ReadScores.size() > 0)
		{
			Text Score1{ SCORE1, std::to_string(ReadScores[0].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score1);
			ScoreTextSize1 = Renderer::Instance()->GetTextureSize(SCORE1);
			Score1Rect = { 500, 100, ScoreTextSize1.x, ScoreTextSize1.y };
		}
		if (ReadScores.size() > 1)
		{
			Text Score2{ SCORE2, std::to_string(ReadScores[1].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score2);
			ScoreTextSize2 = Renderer::Instance()->GetTextureSize(SCORE2);
			Score2Rect = { 500, 150, ScoreTextSize2.x, ScoreTextSize2.y };
		}
		if (ReadScores.size() > 2)
		{
			Text Score3{ SCORE3, std::to_string(ReadScores[2].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score3);
			ScoreTextSize3 = Renderer::Instance()->GetTextureSize(SCORE3);
			Score3Rect = { 500, 200, ScoreTextSize3.x, ScoreTextSize3.y };
		}
		if (ReadScores.size() > 3)
		{
			Text Score4{ SCORE4, std::to_string(ReadScores[3].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score4);
			ScoreTextSize4 = Renderer::Instance()->GetTextureSize(SCORE4);
			Score4Rect = { 500, 250, ScoreTextSize4.x, ScoreTextSize4.y };
		}
		if (ReadScores.size() > 4)
		{
			Text Score5{ SCORE5, std::to_string(ReadScores[4].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score5);
			ScoreTextSize5 = Renderer::Instance()->GetTextureSize(SCORE5);
			Score5Rect = { 500, 300, ScoreTextSize5.x, ScoreTextSize5.y };
		}
		if (ReadScores.size() > 5)
		{
			Text Score6{ SCORE6, std::to_string(ReadScores[5].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score6);
			ScoreTextSize6 = Renderer::Instance()->GetTextureSize(SCORE6);
			Score6Rect = { 500, 350, ScoreTextSize6.x, ScoreTextSize6.y };
		}
		if (ReadScores.size() > 6)
		{
			Text Score7{ SCORE7, std::to_string(ReadScores[6].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score7);
			ScoreTextSize7 = Renderer::Instance()->GetTextureSize(SCORE7);
			Score7Rect = { 500, 400, ScoreTextSize7.x, ScoreTextSize7.y };
		}
		if (ReadScores.size() > 7)
		{
			Text Score8{ SCORE8, std::to_string(ReadScores[7].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score8);
			ScoreTextSize8 = Renderer::Instance()->GetTextureSize(SCORE8);
			Score8Rect = { 500, 450, ScoreTextSize8.x, ScoreTextSize8.y };
		}
		if (ReadScores.size() > 8)
		{
			Text Score9{ SCORE9, std::to_string(ReadScores[8].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score9);
			ScoreTextSize9 = Renderer::Instance()->GetTextureSize(SCORE9);
			Score9Rect = { 500, 500, ScoreTextSize9.x, ScoreTextSize9.y };
		}
		if (ReadScores.size() > 9)
		{
			Text Score10{ SCORE10, std::to_string(ReadScores[9].score),{ 255, 255, 255, 255 }, 0, 0 };
			Renderer::Instance()->LoadTextureText(GAME_OVERLIVES2, Score10);
			ScoreTextSize10 = Renderer::Instance()->GetTextureSize(SCORE10);
			Score10Rect = { 500, 550, ScoreTextSize10.x, ScoreTextSize10.y };
		}
	}
}

bool Ranking::comparePoints(const playerData &a, const playerData &b)
{
	return a.score > b.score;
}

Ranking::~Ranking()
{
}


void Ranking::Update()
{
}

void Ranking::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(NAME1, Name1Rect);
	Renderer::Instance()->PushImage(NAME2, Name2Rect);
	Renderer::Instance()->PushImage(NAME3, Name3Rect);
	Renderer::Instance()->PushImage(NAME4, Name4Rect);
	Renderer::Instance()->PushImage(NAME5, Name5Rect);
	Renderer::Instance()->PushImage(NAME6, Name6Rect);
	Renderer::Instance()->PushImage(NAME7, Name7Rect);
	Renderer::Instance()->PushImage(NAME8, Name8Rect);
	Renderer::Instance()->PushImage(NAME9, Name9Rect);
	Renderer::Instance()->PushImage(NAME10, Name10Rect);

	Renderer::Instance()->PushImage(SCORE1, Score1Rect);
	Renderer::Instance()->PushImage(SCORE2, Score2Rect);
	Renderer::Instance()->PushImage(SCORE3, Score3Rect);
	Renderer::Instance()->PushImage(SCORE4, Score4Rect);
	Renderer::Instance()->PushImage(SCORE5, Score5Rect);
	Renderer::Instance()->PushImage(SCORE6, Score6Rect);
	Renderer::Instance()->PushImage(SCORE7, Score7Rect);
	Renderer::Instance()->PushImage(SCORE8, Score8Rect);
	Renderer::Instance()->PushImage(SCORE9, Score9Rect);
	Renderer::Instance()->PushImage(SCORE10, Score10Rect);
	Renderer::Instance()->PushImage(TEXT_RETURNMENU, returnMenuRect);
	Renderer::Instance()->PushImage(TEXT_RANKING2, HighscoresRect);
	Renderer::Instance()->Render();
}

void Ranking::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEMOTION:	
			if (event.motion.x >= 20 && event.motion.x <= (MenuTextSize.x) + 20 && event.motion.y >= 650 && event.motion.y <= MenuTextSize.y + 650)
			{
				returnMenu = true;
			}
			else
			{
				returnMenu = false;
			}

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (returnMenu == true)
			{
				state = GameState::GOTO;
			}
		default:;
		}
	}
}
