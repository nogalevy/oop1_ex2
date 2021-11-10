#pragma once
#include "Location.h"

struct Teleport{
	Location _cellA;
	Location _cellB;
};

/*
note to noga: when checking if move is valid and if teleport, check that NOT mage, 
mage can move onto it but not use it
*/