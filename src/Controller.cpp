#include "Controller.h"
#include "Board.h"

#include <string>

//==================================================

Controller::Controller()
	: m_numOfSteps(0), m_king(King()), m_mage(Mage()), m_warrior(Warrior()), m_theif(Theif()), m_active_character(KING)
{}

//==================================================

void Controller::run(std::string level)
{
	int row, col;
	auto flevel = ifstream(level);
	if (!flevel.is_open())
	{
		std::cerr << "Cannont open level file\n";
		exit(EXIT_FAILURE);
	}

	auto line = std::string();
	auto numOfLines = std::string();
	int boardSize;

	std::vector <std::string> currentBoard;
	std::getline(flevel, numOfLines);

	boardSize = std::stoi(numOfLines);
	currentBoard.reserve(boardSize);

	for (size_t i = 0; i < boardSize; i++)
	{
		std::getline(flevel, line);//get line
		currentBoard.push_back(line);//push to end of file the line
	}

	m_board = Board(currentBoard, boardSize);

	for (int i = 0; i < NUM_OF_CHARACTERS; i++)
	{
		flevel >> row >> col;
		setCharacterLocation(Location(row, col));
		changeActiveCharacter();
	}
	print_b();
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
	case KING:
		return "King   ";
		break;
	case MAGE:
		return "Mage   ";
		break;
	case WARRIOR:
		return "Warrior ";
		break;
	case THEIF:
		return "Theif   ";
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
//template<typename Character>
bool Controller::readInput()
{
	bool exit = false;
	Screen::resetLocation();
	auto c = _getch();

	switch (c)
	{
	case 0:
	case SpecialKey:
			exit = handleSpecialKey(c);
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
	case 'p':
		changeActiveCharacter();
		print_b();
		break;
	case KB_Escape:
		return true;
	default:
		break;
	}
	return false;
}

bool Controller::checkValidMove(Location new_location)
{
	char tile = m_board.getTile(new_location);

	switch (m_active_character)
	{
	default:
	case KING:
		return m_king.isValidMove(tile);
		break;
	case MAGE:
		return m_mage.isValidMove(tile);
		break;
	case WARRIOR:
		return m_warrior.isValidMove(tile);
		break;
	case THEIF:
		return m_theif.isValidMove(tile);
		break;
	}
}

Location Controller::getActiveCharacterLocation()const
{
	switch (m_active_character)
	{
	default:
	case KING:
		return m_king.getLocation();
		break;
	case MAGE:
		return m_mage.getLocation();
		break;
	case WARRIOR:
		return m_warrior.getLocation();
		break;
	case THEIF:
		return m_theif.getLocation();
		break;
	}
}

bool Controller::handleSpecialKey(auto c)
{
	c = _getch();
	char on_tile = getObjectOnTile();;
	int board_size = m_board.getBoardSize();
	Location characterLocation = getActiveCharacterLocation(), new_location(0, 0);
	int r = characterLocation.row, co = characterLocation.col;
	bool exit = false;

	switch (c)
	{
	case KB_Up:
		new_location = Location((r - 1 >= 0 ? r -1 : r), co); //change to get location
		break;
	case KB_Down:
		new_location = Location((r + 1 < board_size ? r + 1 : r) , co); //change to get location
		break;
	case KB_Left:
		new_location = Location(r, ( co - 1 >= 0 ? co - 1  :co));
		break;
	case KB_Right:
	default:
		new_location = Location(r, (co + 1 < m_board.get_col_length() ? co + 1 : co));
		break;
	}

	if ((new_location.col < m_board.get_col_length()) && (new_location.row < board_size) &&
		(new_location.col >= 0 ) && (new_location.row >= 0) 
		&& checkValidMove(new_location))
	{
		exit = moveCharc(new_location, on_tile);
		increaseNumOfSteps();
		print_b();
	}
	return exit;
}

void Controller::print_b()
{
	Screen::resetLocation();
	m_board.printToConsole(m_active_character);
	printGameData();
}

void Controller::printGameData() const
{
	cout << "Current Active Character: " << getActiveCharacterName() << "    \n";
	cout << "Sum of number of steps: " << getSteps() << endl;
	cout << "Key: ";
	(theifHasKey()) ? cout << "V" : cout << "X" << endl;
}

bool Controller::moveCharc(Location newlocation, char onTile)
{
	//if teleporte type && not mage -> find new location
	char cc = getObjectOnTile();
	char cur = getSymbolC();
	m_board.moveSymbol(getActiveCharacterLocation(), onTile);
	m_board.moveSymbol(newlocation, cur);
	setCharacterLocation(newlocation);

	if (m_active_character == KING && getObjectOnTile() == '@')
	{
		return true;
	}
	return false;
}

void Controller::setCharacterLocation(Location new_location)
{
	switch (Characters(m_active_character))
	{
	default:
	case KING:
		return m_king.setLocation(new_location);

		break;
	case MAGE:
		return m_mage.setLocation(new_location);
		break;
	case WARRIOR:
		return m_warrior.setLocation(new_location);
		break;
	case THEIF:
		return m_theif.setLocation(new_location);
		break;
	}
}

char Controller::getSymbolC()const
{
	switch (m_active_character)
	{
	default:
	case KING:
		return m_king.getSymbol();
		break;
	case MAGE:
		return m_mage.getSymbol();
		break;
	case WARRIOR:
		return m_warrior.getSymbol();
		break;
	case THEIF:
		return m_theif.getSymbol();
		break;
	}
}

char Controller::getObjectOnTile()const
{
	switch (m_active_character)
	{
	default:
	case KING:
		return m_king.getObjectOnTile();
		break;
	case MAGE:
		return m_mage.getObjectOnTile();
		break;
	case WARRIOR:
		return m_warrior.getObjectOnTile();
		break;
	case THEIF:
		return m_theif.getObjectOnTile();
		break;
	}
}


bool Controller::endLevelMsg()
{
	Screen::resetLocation();
	std::system("cls");
	cout << "\n * * * * * * * * * * * * * * * * * * * *";
	cout << "\n * * *   YOU FINISHED THE LEVEL :) * * *";
	cout << "\n * * * * * * * * * * * * * * * * * * * *";

	cout << "\n\n\n click enter to continue and esc to exit";

	while (true)
	{
		char c = _getch();

		switch (c)
		{
		case KB_Escape:
			return false;
		case KB_ENTER:
			return true;
		default:
			break;
		}
	}
	
}