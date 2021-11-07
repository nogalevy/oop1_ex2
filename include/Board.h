#include <stdio.h>

using std::cout;
using std::endl;

const int SIZE = 7;

class Board
{
public:
	//constructor = builds initial board of level
	void printBoard() const;
private:
	char m_board[SIZE][SIZE];
	void printGameData();
	//player
};

void Board::printBoard()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << m_board[i][j];
		cout << endl;
	}
	printGameData();
}

void Board::printGameData()
{
	//name of active character
	//sum of all steps taken of all characters
	//if the theif has the key
}
