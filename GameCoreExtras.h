#ifndef GAMECOREEXTRAS_H
#define GAMECOREEXTRAS_H

#include "Deck.h"
#include "PlayerBase.h"



class GameCoreExtras {
	public:
		GameCoreExtras();
		~GameCoreExtras();
		static void GiveCardToPlayer( Deck& deck, PlayerBase& player );
		static void PrintGameStatus( const PlayerBase& dealer, const PlayerBase& player );
};



#endif