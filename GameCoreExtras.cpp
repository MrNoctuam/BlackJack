#include "GameCoreExtras.h"
#include "Display.h"
#include <iostream>



GameCoreExtras::GameCoreExtras()
{
}



GameCoreExtras::~GameCoreExtras()
{
}



void GameCoreExtras::GiveCardToPlayer( Deck& deck, PlayerBase& player )
{
	Card card( deck.GetCard() );
	player.AddCard( card );
}



void GameCoreExtras::PrintGameStatus( const PlayerBase& dealer, const PlayerBase& player )
{
	Display::Clear();
	dealer.Print();
	std::cout << std::endl << std::endl;
	player.Print();
}