#pragma once

#include "Player.h"

#include <stdio.h>
#include <fstream>
#include <cstdlib> //for exit
#include <vector>
#include <string>
#include <iostream>
#include "Location.h"
//#include "Controller.h"

using std::ifstream;
using std::cout;
using std::endl;

class Controller;

class Board
{
public:
	Board();
	template<typename Character>
	Board(std::string level, Controller& c);
	void printToConsole(Controller& c) const;
	int getBoardSize() const;
	void moveSymbol(Location loc, char symbol);
	char getTile(Location tile)const;

private:
	std::vector <std::string> m_currentBoard;
	int m_BoardSize;

	void printGameData(Controller& c) const;
	void printBoard() const;
};

