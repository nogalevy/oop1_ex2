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
	Controller(); //initialize board, game characters, num of steps, active character
	Controller(std::string level); //initialize board, game characters, num of steps, active character
	void run(std::string level); //
	std::string getActiveCharacterName()const;

	void changeActiveCharacter();
	auto getActive();

	int getSteps()const;
	void increaseNumOfSteps();

	Board getBoard();

	void print_b();
	//io
	bool readInput();
	bool theifHasKey() const;

private:
	short m_active_character;
	std::string m_activeCharacterName;

	int m_numOfSteps;
	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Theif m_theif;
	Board m_board;

	void moveCharc(Location newlocation, auto character);
	bool handleRegularKey(int c);
	void handleSpecialKey(int c);
};

