#pragma once

#include "King.h"
#include ".h"

class Controller
{
public:
	void run();
	//change character
	void changeActiveCharacter();
private:
	//Player m_player;
	auto m_activeCharacter;
};


void Controller::changeActiveCharacter()
{

}
