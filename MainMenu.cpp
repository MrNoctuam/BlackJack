#include "MainMenu.h"
#include "Display.h"
#include <iostream>



MainMenu::MainMenu() : answer( '-' )
{
}



MainMenu::~MainMenu()
{
}



void MainMenu::PrintItems() const
{
	std::cout << "1. New game." << std::endl;
	std::cout << "2. HighScore." << std::endl;
	std::cout << "Q. Quit." << std::endl;
}



void MainMenu::Print()
{
	do
	{
		Display::Clear();
		PrintItems();
		GetAnswer( "" );
		CheckMenuItem();
	} while ( tolower(answer) != QuitAnswer );
}



void MainMenu::GetAnswer( const std::string& question = "" )
{
	std::cout << question << std::endl;
	std::cin >> answer;
}



void MainMenu::CheckMenuItem()
{
	std::string playerName;
	switch ( answer )
	{
		case '1':
			Display::Clear();
			std::cout << "Enter player name: ";
			std::cin >> playerName;
			game.NewPlayer( playerName );
			do
			{
				
				game.StartNew();
				game.Gameplay();
				if ( game.PlayerHasMoney() )
				{
					GetAnswer( "\nContinue? ( y / n )" );
				}
				else
				{
					Display::ReadKey();
					answer = 'n';
				}
			} while ( tolower( answer ) != 'n' );
			game.RefreshStats();
			break;
		case '2':
			stats.ReadFromFile();
			stats.Print();
			Display::ReadKey();
			break;
		case 'q':
			exit( 0 );
		case 'Q':
			exit( 0 );
	}
}