#ifndef GAMECORE_H
#define GAMECORE_H

#include "Deck.h"
#include "Player.h"


class GameCore
{
	public:
		GameCore();
		~GameCore();
		void StartNew();
		void GiveCardToPlayer( Deck deck, Player playerName );


		/*
	private:
		Player player;
		Player dealer;
		Deck deck;*/
};


#endif