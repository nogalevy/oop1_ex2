#include "Controller.h"
#include "Board.h"

#include <string>


Controller::Controller()
	: m_numOfSteps(0), m_king(King()), m_mage(Mage()), m_warrior(Warrior()), m_theif(Theif()), m_board(NULL), m_active_character(KING)
{
}

void Controller::run(std::string level)
{
	Board newboard = (Board());
	m_board = &newboard;
	m_board-> printToConsole(*this);
}


void Controller::changeActiveCharacter()
{
	m_active_character = (short)(m_active_character + 1) % NUM_OF_CHARACTERS;
}

bool Controller::theifHasKey() const
{
	return m_theif.getHasKey();
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



template<typename Character>
Character Controller::getActiveCharacter()const
{
	switch (m_active_character)
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


//------- io
template<typename Character>
bool Controller::readInput()
{
	bool exit = false;

	Screen::resetLocation();

	auto c = _getch();
	switch (c)
	{
	case 0:
	case SpecialKey:
		handleSpecialKey(c);
		break;
	default:
		exit = handleRegularKey(c);
		break;
	}
	return exit;
}


bool Controller::handleRegularKey(int c)
{
	switch (c)
	{
	case 'P':
	case 'p':
		changeActiveCharacter();
		//change character
		break;
	case KB_Escape:
		return true;
	default:
		break;
	}
	return false;
}

template<typename Character>
void Controller::handleSpecialKey(int c)
{
	Location new_location(0, 0);
	Character character = getActiveCharacter();
	switch (c)
	{
	case KB_Up:
		new_location = Location(character.m_location.row - 1, character.m_location.col);
		if (character.isValidMove(m_board.getTile(new_location))) //check is valid
		{
			moveCharc(new_location, character);
			//if ontile = @continue next level
			increaseNumOfSteps();
			//save tile
			//++steps
			print_b();
		}
		break;
	case KB_Down:
		new_location = Location(character.m_location.row + 1, character.m_location.col); //change to get location
		m_board.getTile(new_location);
		if (character.isValidMove(m_board.getTile(new_location))) //check is valid
		{
			moveCharc(new_location, character);
			//if ontile = @continue next level
			increaseNumOfSteps();
			print_b();
		}
		break;
	case KB_Left:
		new_location = Location(character.m_location.row, character.m_location.col - 1);
		if (character.isValidMove(m_board.getTile(new_location))) //check is valid
		{
			moveCharc(new_location, character);
			//if ontile = @continue next level
			increaseNumOfSteps();
			print_b();
		}
		break;
	case KB_Right:
		new_location = Location(character.m_location.row - 1, character.m_location.col + 1);
		if (character.isValidMove(m_board.getTile(new_location))) //check is valid
		{
			moveCharc(new_location, character);
			//if ontile = @continue next level
			increaseNumOfSteps();
			print_b();
		}
		break;
	default:
		break;
	}
}

void Controller::print_b()
{
	m_board->printToConsole(*this);
}


void Controller::moveCharc(Location newlocation, auto character)
{
	m_board.moveSymbol(newlocation, character.getSymbol());
	m_board.moveSymbol(character.getLocation(), character.getObjectOnTile());
	character.setLocation(newlocation);

	//if theif && key update has_key
	//if king && @ exit = return true
}