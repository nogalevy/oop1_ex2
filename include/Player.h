#pragma	once

enum Characters { King, Mage, Theif, Warrior };



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