#include "Board.h"
#include "controller.h"
//#include <filesystem>

//using std::filesystem::current_path;
//#include <unistd.h>

void Board::printToConsole(Controller& c) const
{
	printBoard();
	printGameData(c);
}

Board::Board():m_BoardSize(0) {}

template<typename Character>
Board::Board(std::string level, Controller& c)
{
	ifstream flevel;
	auto line = std::string();
	int row, col;
	//char tmp[256];
	//cout << current_path() << endl;
	//std::string level_path = "../../../levels/" + level;

	flevel.open("../../../levels/" + level);
	if (!flevel.is_open())
	{
		std::cerr << "Cannont open level file\n";
		exit(EXIT_FAILURE);
	}

	flevel >> m_BoardSize;
	for (size_t i = 0; i < m_BoardSize; i++)
	{
		std::getline(flevel, line);//get line
		m_currentBoard.push_back(line);//push to end of file the line
	}
	
	for (int i = 0; i < NUM_OF_CHARACTERS; i++)
	{
		flevel >> row >> col;
		Character charc = c.getActiveCharacter();
		charc.setLocation(Location(row, col));

		//c.changeActiveCharacter();
	}
	
	//read teleport cells
}

int Board::getBoardSize() const
{
	return m_BoardSize;
}
void Board::printBoard()const
{
	for (size_t i = 0; i < m_BoardSize; i++)
		cout << m_currentBoard[i] << endl;
}


void Board::printGameData(Controller& c) const
{
	cout << "Current Active Character: " << c.getActiveCharacterName() << endl;
	cout << "Sum of number of steps: " << c.getSteps() << endl;
	cout << "The Theif ";
	(c.theifHasKey()) ? cout << "has " : cout << "does not have ";
	cout << "the key.\n";
}

void Board::moveSymbol(Location loc, char symbol)
{
	m_currentBoard[loc.row][loc.col] = symbol;
}

char Board::getTile(Location tile)const
{
	return m_currentBoard[tile.row][tile.col];
}