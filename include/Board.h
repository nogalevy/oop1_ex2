#pragma once

#include <stdio.h>
#include <fstream>
#include <cstdlib> //for exit
#include <vector>
#include <string>
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;

class Controller;

class Board
{
public:
	Board();
	Board(std::string level, Controller& c);
	void printToConsole(Controller& c) const;
	int getBoardSize() const;

private:
	std::vector <std::string> m_currentBoard;
	int m_BoardSize;

	void printGameData(Controller& c) const;
	void printBoard() const;
};

