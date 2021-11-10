#include "King.h"


King::King() //:m_location(Location(0, 0))
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
