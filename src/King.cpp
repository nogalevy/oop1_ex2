#include "King.h"

//==================================================

King::King() : m_location(Location(0, 0)), object_on_tile(' ')
{}

//==================================================

bool King::isValidMove(char new_tile)
{
	if ((new_tile == '=') || (new_tile == '#') || (new_tile == '*') || (new_tile == '!'))
		return false;

	object_on_tile = new_tile;
	return true;
}

Location King::getLocation() const
{
	return m_location;
}

void King::setLocation(Location new_loc)
{
	m_location = new_loc;
}
char King::getSymbol()const
{
	return 'K';
}

char King::getObjectOnTile()const
{
	return object_on_tile;
}