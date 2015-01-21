#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameCore.h"
#include <string>



class MainMenu {
	public:
		MainMenu();
		~MainMenu();
		void PrintItems() const;
		void Print();
		void GetAnswer( const std::string& question );

	private:
		char answer;
		GameCore game;
		Stats stats;
		const char PositiveAnswer = 'y';
		const char NegativeAnswer = 'n';
		const char QuitAnswer = 'q';

		void CheckMenuItem();
};



#endif