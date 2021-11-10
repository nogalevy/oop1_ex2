
#include <stdio.h>
#include <fstream>
#include <cstdlib> //for exit
#include <vector>
#include <string>
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;

//const int SIZE = 7;

class Board
{
public:
	Board(char* level, Controller& c);
	void printToConsole() const;
	int getBoardSize() const;

private:
	std::vector <std::string> m_currentBoard;
	int m_BoardSize;

	void printGameData() const;
	void printBoard() const;

	//player
};

Board::Board(char* level, Controller& c)
{
	ifstream flevel;
	auto line = std::string();
	int row, col;

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

int Board::getBoardSize() const
{
	return m_BoardSize;
}
void Board::printBoard()const
{
	for (size_t i = 0; i < m_currentBoard.getBoardSize(); i++)
		cout << m_currentBoard[i] << endl;
}



void Board::printGameData(Controller &c) const
{
	cout << "Current Active Character: " << c.getActiveCharacterName() << endl;
	cout << "Sum of number of steps: " << c.getSteps() << endl;
	//theif key
}
