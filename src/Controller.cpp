#include "Controller.h"
#include <string>


Controller::Controller()
	: m_numOfSteps(0), m_king(King()), m_mage(Mage()), m_warrior(Warrior()), m_theif(Theif())
{
}

void Controller::run(std::string level)
{
	m_board = Board(level, *this);
	m_board.printToConsole(*this);
}


void Controller::changeActiveCharacter()
{
	m_active_character = (short)(m_active_character + 1) % NUM_OF_CHARACTERS;
}

bool Controller::theifHasKey() const
{
	return m_theif.hasKey;
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


auto Controller::getActive()
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

void Controller::handleSpecialKey(int c)
{
	Location new_location(0, 0);
	auto character = getActive();
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
		new_location = Location(character.m_location.row + 1, character.m_location.col);
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
	m_board.printToConsole(*this);
}


void Controller::moveCharc(Location newlocation, auto character)
{
	m_board.moveSign(newlocation, character.getSymbol());
	m_board.moveSign(character.getLocation(), character.getObjectOnTile());
	character.setLocation(newlocation);

	//if theif && key update has_key
	//if king && @ exit = return true
}