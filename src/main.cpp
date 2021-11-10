//open Board and Controller variables
//open level from file ( loop of levels ? )
//read level and insert to Board
//in loop:
//  - print Board
//  - get user key - check it on io
//  - handle all the movement in controller and character class
//  - get another key from user
//  - end loop when king on throne or when click 'ESC'
//
// end level - prints 'GOOD FOR YOU YALLA NEXT ->' (need to type enter or something ?)
// open next file ....

#include "io.h"
#include "Controller.h"

#include <iostream>

#include <conio.h>
#include <vector>
#include <string>
#include <cstdlib> // for std::system()



const int NUM_OF_LEVELS = 1;


int main()
{
	Controller c;
    bool exit = false;

	for(int i = 1; i <= NUM_OF_LEVELS; i++)
	{
		std::string level = "level" + std::to_string(i) + ".txt";
		c.run(level);

		// start level
		std::system("cls");
		Screen::resetLocation();

		c.print_b();

		while (!exit)
		{
			exit = c.readInput();
		}
	}

}
