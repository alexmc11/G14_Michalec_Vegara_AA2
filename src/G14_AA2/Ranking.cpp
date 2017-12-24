#include "Ranking.h"

Ranking::Ranking()
{
	returnMenuRect = { 20, 650, medidaTextMenu.x, medidaTextMenu.y };
	HighscoresRect = { SCREEN_WIDTH/4, 15, medidaTextHigh.x, medidaTextHigh.y };
	returnMenu = false;

	std::string auxname;
	int auxscore = 0;
	playerData aux;
	playerData Player1{ "Satan", 10 };
	playerData Player2{ "Bulma", 20 };
	playerData Player3{ "Roshi", 30 };
	playerData Player4{ "Piccolo", 40 };
	playerData Player5{ "Goten", 50 };
	playerData Player6{ "Trunks", 70 };
	playerData Player7{ "Gohan", 60 };
	playerData Player8{ "Freezer", 80 };
	playerData Player9{ "Vegeta", 90 };
	playerData Player10{ "Goku", 100 };

	Highscores.push_back(Player1);
	Highscores.push_back(Player2);
	Highscores.push_back(Player3);
	Highscores.push_back(Player4);
	Highscores.push_back(Player5);
	Highscores.push_back(Player6);
	Highscores.push_back(Player7);
	Highscores.push_back(Player8);
	Highscores.push_back(Player9);
	Highscores.push_back(Player10);

	std::ofstream fsalida("../../res/files/ranking.bin", std::ios_base::binary);
	std::ifstream fentrada("../../res/files/ranking.bin", std::ios_base::binary);
	if (fsalida.good())
	{		

		for (int i = 0; i < 10; i++)
		{
			fsalida.write(Highscores[i].name.c_str(), Highscores[i].name.size()); // write string to binary file
			fsalida.write("\0", sizeof(char)); // null end string for easier reading
			fsalida.write(reinterpret_cast<char*>(&Highscores[i].score), sizeof(Highscores[i].score)); // write int to binary file
		}
		fsalida.close();
	}
	
	if (fentrada.good())
	{		
		for (int i = 0; fentrada.eof() != true; i++)
		{
			std::getline(fentrada, auxname, '\0'); // get player name (remember we null ternimated in binary)
			fentrada.read(reinterpret_cast<char *>(&auxscore), sizeof(auxscore));
			// read int bytes
			aux = { auxname, auxscore };
			ReadScores.push_back(aux);			
		}
	}
	ReadScores.erase(ReadScores.end()-1);
	
	std::sort(ReadScores.begin(), ReadScores.end(), comparePoints);
	
	for (int i = 0; i < ReadScores.size(); i++)
	{
		std::cout << "Player " << i+1 << " name: " << ReadScores[i].name << std::endl;
		std::cout << "Player " << i+1 << " score: " << ReadScores[i].score << std::endl;
	}

	Text Name1{ NAME1, ReadScores[0].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name1);
	medidaTextoName1 = Renderer::Instance()->GetTextureSize(NAME1);
	Name1Rect = { 100, 100, medidaTextoName1.x, medidaTextoName1.y };

	Text Name2{ NAME2, ReadScores[1].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name2);
	medidaTextoName2 = Renderer::Instance()->GetTextureSize(NAME2);
	Name2Rect = { 100, 150, medidaTextoName2.x, medidaTextoName2.y };

	Text Name3{ NAME3, ReadScores[2].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name3);
	medidaTextoName3 = Renderer::Instance()->GetTextureSize(NAME3);
	Name3Rect = { 100, 200, medidaTextoName3.x, medidaTextoName3.y };

	Text Name4{ NAME4, ReadScores[3].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name4);
	medidaTextoName4 = Renderer::Instance()->GetTextureSize(NAME4);
	Name4Rect = { 100, 250, medidaTextoName4.x, medidaTextoName4.y };

	Text Name5{ NAME5, ReadScores[4].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name5);
	medidaTextoName5 = Renderer::Instance()->GetTextureSize(NAME5);
	Name5Rect = { 100, 300, medidaTextoName5.x, medidaTextoName5.y };

	Text Name6{ NAME6, ReadScores[5].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name6);
	medidaTextoName6 = Renderer::Instance()->GetTextureSize(NAME6);
	Name6Rect = { 100, 350, medidaTextoName6.x, medidaTextoName6.y };

	Text Name7{ NAME7, ReadScores[6].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name7);
	medidaTextoName7 = Renderer::Instance()->GetTextureSize(NAME7);
	Name7Rect = { 100, 400, medidaTextoName7.x, medidaTextoName7.y };

	Text Name8{ NAME8, ReadScores[7].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name8);
	medidaTextoName8 = Renderer::Instance()->GetTextureSize(NAME8);
	Name8Rect = { 100, 450, medidaTextoName8.x, medidaTextoName8.y };

	Text Name9{ NAME9, ReadScores[8].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name9);
	medidaTextoName9 = Renderer::Instance()->GetTextureSize(NAME9);
	Name9Rect = { 100, 500, medidaTextoName9.x, medidaTextoName9.y };

	Text Name10{ NAME10, ReadScores[9].name,{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Name10);
	medidaTextoName10 = Renderer::Instance()->GetTextureSize(NAME10);
	Name10Rect = { 100, 550, medidaTextoName10.x, medidaTextoName10.y };

	Text Score1{ SCORE1, std::to_string(ReadScores[0].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score1);
	medidaTextoScore1 = Renderer::Instance()->GetTextureSize(SCORE1);
	Score1Rect = { 500, 100, medidaTextoScore1.x, medidaTextoScore1.y };

	Text Score2{ SCORE2, std::to_string(ReadScores[1].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score2);
	medidaTextoScore2 = Renderer::Instance()->GetTextureSize(SCORE2);
	Score2Rect = { 500, 150, medidaTextoScore2.x, medidaTextoScore2.y };

	Text Score3{ SCORE3, std::to_string(ReadScores[2].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score3);
	medidaTextoScore3 = Renderer::Instance()->GetTextureSize(SCORE3);
	Score3Rect = { 500, 200, medidaTextoScore3.x, medidaTextoScore3.y };

	Text Score4{ SCORE4, std::to_string(ReadScores[3].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score4);
	medidaTextoScore4 = Renderer::Instance()->GetTextureSize(SCORE4);
	Score4Rect = { 500, 250, medidaTextoScore4.x, medidaTextoScore4.y };

	Text Score5{ SCORE5, std::to_string(ReadScores[4].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score5);
	medidaTextoScore5 = Renderer::Instance()->GetTextureSize(SCORE5);
	Score5Rect = { 500, 300, medidaTextoScore5.x, medidaTextoScore5.y };

	Text Score6{ SCORE6, std::to_string(ReadScores[5].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score6);
	medidaTextoScore6 = Renderer::Instance()->GetTextureSize(SCORE6);
	Score6Rect = { 500, 350, medidaTextoScore6.x, medidaTextoScore6.y };

	Text Score7{ SCORE7, std::to_string(ReadScores[6].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score7);
	medidaTextoScore7 = Renderer::Instance()->GetTextureSize(SCORE7);
	Score7Rect = { 500, 400, medidaTextoScore7.x, medidaTextoScore7.y };

	Text Score8{ SCORE8, std::to_string(ReadScores[7].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score8);
	medidaTextoScore8 = Renderer::Instance()->GetTextureSize(SCORE8);
	Score8Rect = { 500, 450, medidaTextoScore8.x, medidaTextoScore8.y };

	Text Score9{ SCORE9, std::to_string(ReadScores[8].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score9);
	medidaTextoScore9 = Renderer::Instance()->GetTextureSize(SCORE9);
	Score9Rect = { 500, 500, medidaTextoScore9.x, medidaTextoScore9.y };

	Text Score10{ SCORE10, std::to_string(ReadScores[9].score),{ 255, 255, 255, 255 }, 0, 0 };
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, Score10);
	medidaTextoScore10 = Renderer::Instance()->GetTextureSize(SCORE10);
	Score10Rect = { 500, 550, medidaTextoScore10.x, medidaTextoScore10.y };

}

bool Ranking::comparePoints(const playerData &a, const playerData &b)
{
	return a.score > b.score;
}

Ranking::~Ranking()
{
}

void Ranking::ponerNombre(int puntos)
{
	std::string nombre;
	std::cout << "Introduce tu nombre: ";
	std::cin >> nombre;
	playerData currentPlayer;
	currentPlayer.name = nombre;
	currentPlayer.score = puntos;
	ReadScores.push_back(currentPlayer);
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
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextMenu.x) + 20 && event.motion.y >= 650 && event.motion.y <= medidaTextMenu.y + 650)
			{
				std::cout << "return";
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
