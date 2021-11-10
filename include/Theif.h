#pragma once

#include "Location.h"

class Theif
{
public:
	Theif()
	Location getLocation() const;
	void setLocation();
	
private:
	bool m_hasKey; //here or in Board?
	Location m_location;
};

Theif::Theif()
{

}
