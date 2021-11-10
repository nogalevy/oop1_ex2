#pragma once

#include "Location.h"

class Controller; // Forward declaration

class King
{
public:
	King();
	bool isValidMove(char new_tile);
	Location getLocation()const;
	void setLocation(Location new_loc);
	char getSymbol()const;
	char getObjectOnTile()const;
	
	//TODO: check with controller which key user clicked and check if is valid to move
private:
	Location m_location;
	char object_on_tile;
};

