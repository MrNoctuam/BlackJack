#include "GameCore.h"
#include <iostream>



int main()
{
	char answer = 'y';
	do
	{
		GameCore game;
		game.StartNew();
		game.Gameplay();
		std::cout << "\n\nNew game? (y/n)" << std::endl;
		std::cin >> answer;
	} while ( answer != 'n' );
	return 0;
}