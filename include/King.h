#pragma once

#include "Controller.h"

class Controller; // Forward declaration

class King
{
public:
	ocation getLocation() const;
	void setLocation();

	//TODO: check with controller which key user clicked and check if is valid to move
	bool move(Controller& c);
private:
	//location

};
