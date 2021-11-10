#pragma once

#include "utilities.h"
#include "Player.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Theif.h"
#include "Board.h"

#include <string>
//
//#include <iostream>
//#include <cstdlib> // for std::system()
//#include "io.h"
//
//#include <conio.h>
//#include <vector>
//#include <string>
//
//enum Keys
//{
//	KB_Escape = 27,
//	SpecialKey = 224,
//};
//
//enum SpecialKeys
//{
//	KB_Up = 72,
//	KB_Down = 80,
//	KB_Left = 75,
//	KB_Right = 77,
//};

class Controller
{
public:
	Controller(); //initialize board, game characters, num of steps, active character
	Controller(std::string level); //initialize board, game characters, num of steps, active character
	void run(std::string level); //
	std::string getActiveCharacterName()const;

	auto changeActiveCharacter();

	int getSteps()const;
	void increaseNumOfSteps();


	//io
	//bool readInput();
private:
	Characters m_active_character;
	std::string m_activeCharacterName;

	bool handleRegularKey(int c);
	void handleSpecialKey(std::vector<std::string>& v, int& col, int& row);

	void print_b(std::vector<std::string> v);

	int m_numOfSteps;
	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Theif m_theif;

	Board m_board;

};

