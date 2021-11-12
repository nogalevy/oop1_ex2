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


int main()
{
	
    bool exit = false;

	for(int i = 1; i <= NUM_OF_LEVELS; i++)
	{
		Controller c;

		Screen::resetLocation();
		std::system("cls");

		std::string level = "level" + std::to_string(i) + ".txt";


		c.run(level);

		//auto ch = getch();

		while (!exit)
		{
			exit = c.readInput();
			//Screen::setLocation(Location(3, 4));
		}

		if (!c.endLevelMsg())
			return EXIT_SUCCESS;


		exit = false;
		
	}
	return EXIT_SUCCESS;

}