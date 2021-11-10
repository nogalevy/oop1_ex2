#include "Theif.h"


Theif::Theif() : m_location(Location(0, 0)), object_on_tile(' '), m_hasKey(false)
{}

bool Theif::isValidMove(char new_tile)
{
	if ((new_tile == '=') || (new_tile == '*') || (new_tile == '@') || (new_tile != '!') || 
		(new_tile == '#' && !m_hasKey))
		return false;

	if (new_tile == '#' && m_hasKey)
	{
		object_on_tile = '#';
		m_hasKey = false;
		return true;
	}
	if (new_tile == 'F')
		m_hasKey = true;
	
	object_on_tile = ' ';

	return true;
}

Location Theif::getLocation() const
{
	return m_location;
}

void Theif::setLocation(Location new_loc)
{
	m_location = new_loc;
}
char Theif::getSymbol()const
{
	return 'T';
}

char Theif::getObjectOnTile()const
{
	return object_on_tile;
}

bool Theif::getHasKey()const
{
	return m_hasKey;
}