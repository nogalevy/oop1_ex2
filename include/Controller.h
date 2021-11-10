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
	void run(); //
	string getActiveCharacterName();
	void changeActiveCharacter();
	int getSteps()const;
	void increaseNumOfSteps();
private:
	auto m_activeCharacter;
	string m_activeCharacterName;
	int m_numOfSteps;
	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Theif m_theif;

	Board m_board;

};

Controller::Controller(level) : m_numOfSteps(0), m_king(King())
{
	//m_board = Board(level);
}

void Controller::run(char* level)
{
	m_board = board(level);
}

	/*
void Controller::changeActiveCharacter()
{
	switch (m_activeCharacterName)
	{
	case 0:
		m_activeCharacter =
	}
}
	*/

int Controller::getSteps()const
{
	return m_numOfSteps;
}

string Controller::getActiveCharacterName()
{
	switch (m_activeCharacterName)
	{
	case 0:
		return "King";
		break;
	case 1:
		return "Mage";
		break;
	case 2:
		return "Warrior";
		break;
	case 3:
		return "Theif";
		break;
	default:
		return "idk";
	}
}

void Controller::increaseNumOfSteps()
{
	m_numOfSteps++;
}
