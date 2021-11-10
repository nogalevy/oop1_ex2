#include "Mage.h"

Mage::Mage() : m_location(Location(0, 0)), object_on_tile(' ')
{}

bool Mage::isValidMove(char new_tile)
{
	if ((new_tile == '=') || (new_tile == '#') || (new_tile == '!') || (new_tile == '@'))
		return false;

	if ((new_tile == '*'))
		object_on_tile = ' ';
	else
		object_on_tile = new_tile;

	return true;
}

Location Mage::getLocation() const
{
	return m_location;
}

void Mage::setLocation(Location new_loc)
{
	m_location = new_loc;
}
char Mage::getSymbol()const
{
	return 'M';
}

char Mage::getObjectOnTile()const
{
	return object_on_tile;
}