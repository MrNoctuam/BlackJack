#ifndef GAMECORE_H
#define GAMECORE_H

#include "Deck.h"
#include "Player.h"
#include "GameCoreExtras.h"



class GameCore
{
	public:
		GameCore();
		~GameCore();
		void StartNew();
		void Gameplay();

		
	private:
		bool isFinished;
		Player player;
		Player dealer;
		Deck deck;
		void GameWithPlayer( Player& currentPlayer );
		void RefreshGameStatus();
};



#endif