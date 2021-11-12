#pragma once

#include "Player.h"

#include <stdio.h>
#include <fstream>
#include <cstdlib> //for exit
#include <vector>
#include <string>
#include <iostream>
#include "Location.h"
#include "Utilities.h"
//#include "Controller.h"

using std::ifstream;
using std::cout;
using std::endl;

//class Controller;

class Board
{
public:
	Board();
	Board(std::vector <std::string> b, int boardSize);
	//template<typename Character>
	Board(std::string level);
	void printToConsole(short charc) const;
	int getBoardSize() const;
	void moveSymbol(Location loc, char symbol);
	char getTile(Location tile);
	Location getCellPartner(Location cell)const;

private:
	std::vector <std::string> m_currentBoard;
	std::vector <struct Teleport> m_cells;
	int m_BoardSize;


	void printGameData(short charc) const;
	void printBoard() const;
};

