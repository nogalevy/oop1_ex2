#include "Board.h"
#include "Player.h"
#include <filesystem>

using std::filesystem::current_path;
//#include <unistd.h>

void Board::printToConsole(Controller& c) const
{
	printBoard();
	printGameData(c);
}

Board::Board():m_BoardSize(0) {}

Board::Board(std::string level, Controller& c)
{
	ifstream flevel;
	auto line = std::string();
	int row, col;
	char tmp[256];
	cout << current_path() << endl;
	std::string level_path = "../../../levels/" + level;

	flevel.open(level_path);
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
		//c.getActiveCharacter().setLocation(Location(row, col));
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
	cout << "Size of Board: " << m_BoardSize << endl;
	//cout << "Current Active Character: " << endl;
		/* << c.getActiveCharacterName() << endl;
	cout << "Sum of number of steps: " << c.getSteps() << endl;
	cout << "The Theif ";
	(c.m_theif.hasKey()) ? cout << "has " : cout << "does not have ";
	cout << "the key.\n";*/
}
