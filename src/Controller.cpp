#include "Controller.h"
#include <string>


Controller::Controller()
	: m_numOfSteps(0), m_king(King()), m_mage(Mage()), m_warrior(Warrior()), m_theif(Theif()), m_activeCharacter(KING)
{
}

void Controller::run(std::string level)
{
	m_board = Board(level, *this);
	m_board.printToConsole(*this);
}




Controller::Controller(std::string level) : m_numOfSteps(0), m_king(King())
{
	m_board = Board();
	m_board.m_currentBoard = { "=======",
								"=     =",
								"=     =",
								"=     =",
								"=     =",
								"=    K=",
								"=======" };
	//m_board = Board(level);
}


auto Controller::changeActiveCharacter()
{
	switch ((m_active_character + 1) % NUM_OF_CHARACTERS)
	{
	default:
	case 0:
		return m_king;
		break;
	case 1:
		return m_mage;
		break;
	case 2:
		return m_warrior;
		break;
	case 3:
		return m_theif;
		break;
	}
}




std::string Controller::getActiveCharacterName()const
{
	switch (m_active_character)
	{
	default:
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
	}
}

int Controller::getSteps()const
{
	return m_numOfSteps;
}

void Controller::increaseNumOfSteps()
{
	m_numOfSteps++;
}









//------- io
bool Controller::readInput()
{
	bool exit = false;

	Screen::resetLocation();

	auto c = _getch();
	switch (c)
	{
	case 0:
	case SpecialKey:
		handleSpecialKey(v, k_col, k_row);
		break;
	default:
		exit = handleRegularKey(c);
		break;
	}
	retrun exit;
}


bool Controller::handleRegularKey(int c)
{
	switch (c)
	{
	case 'P':
	case 'p':
		//change character
		break;
	case KB_Escape:
		//exit game
		return true;
	default:
		break;
	}
	return false;
}

void Controller::handleSpecialKey(std::vector<std::string>& v, int& col, int& row)
{
	auto c = _getch();
	switch (c)
	{
	case KB_Up:
		if (k_row - 1 > 0) //check is valid
		{
			k_row = k_row - 1;
			v[k_row + 1][k_col] = ' ';
			v[k_row][k_col] = 'K';
			//save tile
			//++steps
			print_b(v);
		}
		break;
	case KB_Down:
		std::cout << "Arrow Down pressed\n";
		break;
	case KB_Left:
		std::cout << "Arrow Left pressed\n";
		break;
	case KB_Right:
		std::cout << "Arrow Right pressed\n";
		break;
	default:
		std::cout << "Unknown special key pressed (code = " << c << ")\n";
		break;
	}
}


void Controller::print_b(std::vector<std::string> v)
{
	m_board.printGameData(*this);
}
