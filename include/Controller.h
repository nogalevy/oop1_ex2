#pragma once

#include "Player.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Theif.h"
#include "Board.h"
#include <string>


class Controller
{
public:
	Controller(); //initialize board, game characters, num of steps, active character
	void run(std::string level); //
	std::string getActiveCharacterName()const;
	auto getActiveCharacter()const;
	void changeActiveCharacter();
	int getSteps()const;
	void increaseNumOfSteps();
private:
	Characters m_activeCharacter;
	std::string m_activeCharacterName;
	int m_numOfSteps;
	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Theif m_theif;

	Board m_board;

};
