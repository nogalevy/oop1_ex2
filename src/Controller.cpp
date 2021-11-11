#include "Controller.h"
#include "Board.h"

#include <string>


Controller::Controller()
	: m_numOfSteps(0), m_king(King()), m_mage(Mage()), m_warrior(Warrior()), m_theif(Theif()), m_active_character(KING)
{}

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
	int BoardSize;

	std::vector <std::string> currentBoard;
	std::getline(flevel, numOfLines);

	BoardSize = std::stoi(numOfLines);
	currentBoard.reserve(BoardSize);

	for (size_t i = 0; i < BoardSize; i++)
	{
		std::getline(flevel, line);//get line
		currentBoard.push_back(line);//push to end of file the line
	}


	m_board = Board(currentBoard);


	for (int i = 0; i < NUM_OF_CHARACTERS; i++)
	{
		flevel >> row >> col;
		//Character charc = c.getActiveCharacter();
		setCharacterLocation(Location(row, col));
		changeActiveCharacter();
	}

	//m_board = Board(level);

	//m_board = &newboard;

	 //m_board = new Board(level, *this);
	m_board.printToConsole(m_active_character);
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

	auto c = getch();
	//c = getch();

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
	//case 'P':
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
//template<typename Character>
bool Controller::handleSpecialKey(auto c)
{
	c = getch();

	Location characterLocation = getActiveCharacterLocation();
	//cout << c;
	Location new_location(0, 0);
	int r = characterLocation.row, co = characterLocation.col;
	bool exit = false;
	switch (c)
	{
	case KB_Up:
		new_location = Location((r - 1 >= 0 ? r -1 : r), co); //change to get location
		break;
	case KB_Down:
		new_location = Location((r + 1 < 10 ? r + 1 : r) , co); //change to get location
		break;
	case KB_Left:
		new_location = Location(r, ( co - 1 >= 0 ? co - 1  :co));
		break;
	case KB_Right:
	default:
		new_location = Location(r, (co + 1 < 10 ? co + 1 : co));
		break;
	}

	if ((new_location.col < 10) && (new_location.row < 10) && checkValidMove(new_location)) //check is valid
	{
		//std::cout << "\n" << new_location.row << " " << new_location.col << "\n";
		exit = moveCharc(new_location);
		//if ontile = @continue next level
		increaseNumOfSteps();
		print_b();
	}
	else
	{
		print_b();
	}
	return exit;
}

void Controller::print_b()
{
	Screen::resetLocation();
	m_board.printToConsole(m_active_character);
}


//template<typename Character>
bool Controller::moveCharc(Location newlocation)
{
	//if teleporte type && not mage -> find new location
	m_board.moveSymbol(newlocation, getSymbolC());
	m_board.moveSymbol(getActiveCharacterLocation(), getObjectOnTile());
	setCharacterLocation(newlocation);

	if (m_active_character == KING && getObjectOnTile() == '@')
	{
		return true;
	}
	return false;
	//if king && @ exit = return true
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