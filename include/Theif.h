#pragma once

#include "Location.h"

class Controller;

class Theif
{
public:
	Theif();
	bool isValidMove(char new_tile);
	Location getLocation()const;
	void setLocation(Location new_loc);
	char getSymbol()const;
	char getObjectOnTile()const;
	bool getHasKey()const;
private:
	Location m_location;
	char object_on_tile;
	bool m_hasKey;
};

