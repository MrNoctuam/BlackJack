#include "Display.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

#if defined _WIN32
#include <Windows.h>
#elif defined _WIN64
#include <Windows.h>
#endif


void Display::Clear()
{
#if defined __linux__
	system( "clear" );
#elif defined _WIN32
	system( "cls" );
#elif defined _WIN64
	system( "cls" );
#endif
}



void Display::ReadKey()
{
#if defined __linux__
	std::cout << "Press ENTER to continue...";
	std::cin.ignore();
	std::cin.get();	
#elif defined _WIN32
	system( "pause" );
#elif defined _WIN64
	system( "pause" );
#endif
}



void Display::Delay( unsigned int value )
{
	//Sleep( value );
	clock_t delay = value * CLOCKS_PER_SEC / 1000;
	clock_t start = clock();
	while ( ( clock() - start ) < delay )
	{
		;
	}
}
