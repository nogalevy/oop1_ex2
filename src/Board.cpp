#include "Board.h"
#include <filesystem>
using std::filesystem::current_path;
//#include <unistd.h>

void Board::printToConsole(Controller& c) const
{
	printBoard();
	printGameData(c);
}

<<<<<<< Updated upstream
Board::Board():m_BoardSize(0) {}

Board::Board(std::string level, Controller& c)
=======
Board::Board(char* level, Controller& c)
>>>>>>> Stashed changes
{
	ifstream flevel;
	auto line = std::string();
	int row, col;
<<<<<<< Updated upstream
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
		c.getActiveCharacter().setLocation(Location(row, col));
		c.changeActiveCharacter();
	}
	
	//read teleport cells
}

<<<<<<< HEAD

void Board::printGameData() const
=======
=======

	flevel.open(level);
	if (!flevel.is_open)
	{
		cerr << "Cannont open level file\n";
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
		c.getActivePlayer().setLocation(Location(row, col));
		c.changeActivePlayer();
	}

	//read teleport cells
}

>>>>>>> Stashed changes
int Board::getBoardSize() const
{
	return m_BoardSize;
}
void Board::printBoard()const
<<<<<<< Updated upstream
>>>>>>> 66deee1f500e0e6b4ecdfe968cde5bbd8ad4d255
{
	for (size_t i = 0; i < m_BoardSize; i++)
		cout << m_currentBoard[i] << endl;
}

<<<<<<< HEAD
=======
=======
{
	for (size_t i = 0; i < m_currentBoard.getBoardSize(); i++)
		cout << m_currentBoard[i] << endl;
}

>>>>>>> Stashed changes


void Board::printGameData(Controller& c) const
{
<<<<<<< Updated upstream
	cout << "Size of Board: " << m_BoardSize << endl;
	//cout << "Current Active Character: " << endl;
		/* << c.getActiveCharacterName() << endl;
	cout << "Sum of number of steps: " << c.getSteps() << endl;
	cout << "The Theif ";
	(c.m_theif.hasKey()) ? cout << "has " : cout << "does not have ";
	cout << "the key.\n";*/
}
>>>>>>> 66deee1f500e0e6b4ecdfe968cde5bbd8ad4d255
=======
	cout << "Current Active Character: " << c.getActiveCharacterName() << endl;
	cout << "Sum of number of steps: " << c.getSteps() << endl;
	//theif key
}
>>>>>>> Stashed changes
