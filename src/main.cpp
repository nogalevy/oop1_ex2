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
/*
enum Keys
{
    KB_Escape = 27,
    SpecialKey = 224,
};

enum SpecialKeys
{
    KB_Up = 72,
    KB_Down = 80,
    KB_Left = 75,
    KB_Right = 77,
};

*/
//bool handleRegularKey(int c);
//void handleSpecialKey(std::vector<std::string> &v, int &k_col, int &k_row);
void print_b(std::vector<std::string> v);

int main()
{
	Controller c;

	for(int i = 1; i <= NUM_OF_LEVELS; i++)
	{
		std::string level = "level" + std::to_string(i) + ".txt";
		c.run(level);
	}
	//for(int i = 1; i <= NUM_OF_LEVELS; i++)
		//c.run(level);
    bool exit = false;
    std::vector<std::string> v = { "=======",
                                "=     =",
                                "=     =",
                                "=     =",
                                "=     =",
                                "=    K=",
                                "=======" };

   

    std::system("cls");
    Screen::resetLocation();

    //print v
    print_b(v);

    while (!exit)
    {
        //exit = c.readInput();
       /* Screen::resetLocation();

        auto c = _getch();
        switch (c)
        {
        case 0:
        case SpecialKey:
            handleSpecialKey(v, k_col, k_row);
            break;
        default:
            exit = handleRegularKey(c);
            break;
        }

        */
    }
}

void print_b(std::vector<std::string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "\n";
    }
}
//
//bool handleRegularKey(int c)
//{
//    switch (c)
//    {
//    case 'P':
//    case 'p':
//        std::cout << "A pressed\n";
//        break;
//    case KB_Escape:
//        std::cout << "Escape pressed. Exiting...\n";
//        return true;
//    default:
//        std::cout << "Unknown regular key pressed (code = " << c << ")\n";
//        break;
//    }
//    return false;
//}
//
//void handleSpecialKey(std::vector<std::string> &v, int &k_col, int &k_row)
//{
//    auto c = _getch();
//    switch (c)
//    {
//    case KB_Up:
//        if (k_row - 1 > 0) //check is valid
//        {
//            k_row = k_row - 1;
//            v[k_row + 1][k_col] = ' ';
//            v[k_row][k_col] = 'K';
//            //save tile
//            //++steps
//            print_b(v);
//        }
//
//
//        break;
//    case KB_Down:
//        std::cout << "Arrow Down pressed\n";
//        break;
//    case KB_Left:
//        std::cout << "Arrow Left pressed\n";
//        break;
//    case KB_Right:
//        std::cout << "Arrow Right pressed\n";
//        break;
//    default:
//        std::cout << "Unknown special key pressed (code = " << c << ")\n";
//        break;
//    }
//}
