#include "Warrior.h"

//==================================================

Warrior::Warrior() : m_location(Location(0, 0)), object_on_tile(' ')
{}

//==================================================

bool Warrior::isValidMove(char new_tile)
{
	if ((new_tile == '=') || (new_tile == '#') || (new_tile == '*') || (new_tile == '@'))
		return false;
	if ((new_tile == '!'))
		object_on_tile = 'F';
	else
		object_on_tile = new_tile;

	return true;
}

Location Warrior::getLocation() const
{
	return m_location;
}

void Warrior::setLocation(Location new_loc)
{
	m_location = new_loc;
}
char Warrior::getSymbol()const
{
	return 'W';
}

char Warrior::getObjectOnTile()const
{
	return object_on_tile;
}