#include "Controller.h"

Controller::Controller()
	: m_numOfSteps(0), m_king(King()), m_mage(Mage()), m_warrior(Warrior()), m_theif(Theif()), m_activeCharacter(KING)
{
}

void Controller::run(std::string level)
{
	m_board = Board(level, *this);
	m_board.printToConsole(*this);
}


void Controller::changeActiveCharacter()
{
	switch (m_activeCharacterName)
	{
	case 0:
		m_activeCharacter =
	}
}

auto Controller::getActiveCharacter()const
{
	return m_activeCharacter;
}

int Controller::getSteps()const
{
	return m_numOfSteps;
}

std::string Controller::getActiveCharacterName()const
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
