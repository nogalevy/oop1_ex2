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


class Controller
{
public:
	Controller();

	void run(std::string level); //load level
	std::string getActiveCharacterName()const;
	void changeActiveCharacter();
	bool endLevelMsg();
	Location getActiveCharacterLocation()const;
	bool checkValidMove(Location new_location);
	int getSteps()const;
	void increaseNumOfSteps();
	void print_b();
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

	char getSymbolC()const;
	char getObjectOnTile()const;
	bool moveCharc(Location newlocation, char onTile);
	bool handleRegularKey(int c);
	void printGameData() const;
	bool handleSpecialKey(auto c);
};

