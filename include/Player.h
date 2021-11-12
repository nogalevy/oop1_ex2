#pragma	once

const int NUM_OF_CHARACTERS = 4;
const int NUM_OF_LEVELS = 3;

enum Characters { KING = 0, MAGE, WARRIOR, THEIF };


enum Keys
{
	KB_ENTER = 13,
	KB_Escape = 27,
	SpecialKey = 224,
};

enum SpecialKeys
{
	KB_Up = 72,
	KB_Down = 80,
	KB_Left = 75,
	KB_Right = 77,
};
/*

class Player
{
public:
	int getActiveCharacter() const;
	//setplayer
private:
	//active player
	Characters m_activeCharacter;
	//sum of steps
	//if theif has key

};

int Player::getActiveCharacter() const
{
	return m_activeCharacter;
}

*/
