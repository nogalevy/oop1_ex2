#pragma once

#include "Controller.h"
#include "Location.h"

class Controller; // Forward declaration

class King
{
public:
	void move(Location new_loc);
	Location getLocation() const;

	//TODO: check with controller which key user clicked and check if is valid to move
	//bool move(Controller& c);
private:
	Location m_location;

};

void King::move(Location new_loc)
{
	if (valid_move)
		location = new_loc;
}


Location King::getLocation() const
{
	return m_location;
}