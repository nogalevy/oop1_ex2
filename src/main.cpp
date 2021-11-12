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
	Controller c;
    bool exit = false;

		std::system("cls");
	for(int i = 1; i <= NUM_OF_LEVELS; i++)
	{
		std::string level = "level" + std::to_string(i) + ".txt";

		Screen::resetLocation();


		c.run(level);

		//auto ch = getch();

		while (!exit)
		{
			exit = c.readInput();
			//Screen::setLocation(Location(3, 4));
		}
		
	}
		return EXIT_SUCCESS;

}