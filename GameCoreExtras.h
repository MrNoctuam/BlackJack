#ifndef GAMECOREEXTRAS_H
#define GAMECOREEXTRAS_H

#include "Deck.h"
#include "Player.h"



class GameCoreExtras {
	public:
		GameCoreExtras();
		~GameCoreExtras();
		static void GiveCardToPlayer( Deck& deck, Player& player );
		static void PrintGameStatus( const Player& dealer, const Player& player );
		static bool AddCardDecision( const Player& player );
};



#endif