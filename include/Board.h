#include <stdio.h>

using std::cout;
using std::endl;

const int SIZE = 7;

class Board
{
public:
	//constructor = builds initial board of level
	void printToConsole() const;
	void printBoard() const;

private:
	char m_board[SIZE][SIZE]; //CHANGE to vector type char (size = from level file)


	void printGameData() const;
	void printBoard() const;

	//player
};