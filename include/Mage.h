#pragma once

#include "Location.h"

class Mage
{
public:
	Mage();
	bool isValidMove(char new_tile);
	Location getLocation()const;
	void setLocation(Location new_loc);
	char getSymbol()const;
	char getObjectOnTile()const;
private:
	Location m_location;
	char object_on_tile;
};

