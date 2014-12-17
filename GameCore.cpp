#include "GameCore.h"

#define MAX_DEALER_SCORE 17


GameCore::GameCore()
{
}


GameCore::~GameCore()
{
}


void GameCore::StartNew()
{/*
	player.ClearHand();
	dealer.ClearHand();
	deck.SetNew(); */
}


void GameCore::GiveCardToPlayer( Deck deck, Player playerName )
{
	Card card( deck.getCard() );
	playerName.AddCard( card );
}