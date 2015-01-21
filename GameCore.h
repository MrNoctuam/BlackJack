#ifndef GAMECORE_H
#define GAMECORE_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "GameCoreExtras.h"
#include "Stats.h"


// to singleton
class GameCore
{
	public:
		GameCore();
		~GameCore();
		void StartNew();
		void NewPlayer( const std::string& playerName );
		void Gameplay();
		void RefreshStats();
		bool PlayerHasMoney();
		
	private:
		bool isFinished;
		Player player;
		Dealer dealer;
		Deck deck;
		int bet;
		StatsCount statsCount;
		Stats stats;

		void GameWithPlayer( PlayerBase& currentPlayer );
		void RefreshGameStatus();
		void MakeBet();
		void GiveCardTo( PlayerBase& currentPlayer );
};



#endif