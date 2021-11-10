#pragma once

//#include "Controller.h"
#include "Location.h"

class Controller; // Forward declaration

class King
{
public:
	King();
	move(Location new_loc);
	Location getLocation() const;
	void setLocation(int row, int col);
	//TODO: check with controller which key user clicked and check if is valid to move
	bool move(Controller& c);
private:
	Location m_location;
	char whats_under_me;
};

