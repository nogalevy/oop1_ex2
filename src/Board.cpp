#include "Board.h"


void Board::printToConsole() const
{
	printBoard();
	printGameData();
}

void Board::printBoard() const
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << m_board[i][j];
		cout << endl;
	}
}

void Board::printGameData()
{
	//name of active character
	//sum of all steps taken of all characters
	//if the theif has the key
}
