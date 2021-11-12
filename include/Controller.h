#pragma once

#include "utilities.h"
#include "Player.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Theif.h"
#include "Board.h"
#include "Location.h"
#include "io.h"

#include <iostream>

#include <conio.h>
#include <vector>
#include <cstdlib>
#include <string>

//class Board;

class Controller
{
public:
	Controller(); //initialize board, game characters, num of steps, active character
	void run(std::string level); //
	std::string getActiveCharacterName()const;

	void changeActiveCharacter();

	//template<typename Character>
	//Character getActiveCharacter()const;
	Location getActiveCharacterLocation()const;
	bool checkValidMove(Location new_location);

	int getSteps()const;
	void increaseNumOfSteps();

	void print_b();
	//io
	//template<typename Character>
	bool readInput();
	bool theifHasKey() const;

	void setCharacterLocation(Location new_location);
private:
	short m_active_character = KING;
	std::string m_activeCharacterName;

	int m_numOfSteps;


	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Theif m_theif;

	Board m_board;

	//template<typename Character>
	char getSymbolC()const;
	char getObjectOnTile()const;
	bool moveCharc(Location newlocation);
	bool handleRegularKey(int c);
	void printGameData() const;

	//template<typename Character>
	bool handleSpecialKey(auto c);
};

