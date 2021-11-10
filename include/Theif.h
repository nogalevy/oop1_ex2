#pragma once

#include "Location.h"

class Controller;

class Theif
{
public:
	Theif();
	Location getLocation() const;
	void setLocation();
	
private:
	bool m_hasKey;
	Location m_location;
};

