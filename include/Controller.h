#pragma once

#include "King.h"
#include ".h"

/*
if we have enum, we can just ++ it to move to next, then in switch case in controller, call 
character to move accordingly
auto player = "character"
player.move(new_loc);
maybe enum in header file named players?
*/


class Controller
{
public:
	Controller();
	void run();
	//change character
	void changeActiveCharacter();
	int getSteps()const;
private:
	//Player m_player;
	auto m_activeCharacter; //enum? returns and plays accordingly 
	int m_numOfSteps;
};

Controller::Controller() : //initialize num of steps etc

void Controller::changeActiveCharacter()
{
	//checks current player, moves to next one (enum?)
}

int Controller::getSteps()const
{
	return m_numOfSteps;
}