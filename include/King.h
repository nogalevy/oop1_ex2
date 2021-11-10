#pragma once

#include "Controller.h"
#include "Location.h"

class Controller; // Forward declaration

class King
{
public:
	King(Location start_loc);
	void move(Location new_loc);
	Location getLocation() const;
	void setLocation(int row, int col);
	//TODO: check with controller which key user clicked and check if is valid to move
	//bool move(Controller& c);
private:
	Location m_location;
	char whats_under_me;
};

King::King(Location start_loc) :m_location(start_loc)
{

}

void King::move(Location new_loc)
{
	if (valid_move)
		location = new_loc;
}


Location King::getLocation() const
{
	return m_location;
}

void King::setLocation(Location loc) : m_location(loc)) {}