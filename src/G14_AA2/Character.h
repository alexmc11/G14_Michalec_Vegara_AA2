#pragma once
enum playerTag {player1, player2};
class Character
{
public:
	
	Character(playerTag player);
	~Character();
	void movement();
};

