#include "GameCoreExtras.h"
#include <iostream>
#include <Windows.h>

#define MAX_DEALER_SCORE 17



GameCoreExtras::GameCoreExtras()
{
}



GameCoreExtras::~GameCoreExtras()
{
}



void GameCoreExtras::GiveCardToPlayer( Deck& deck, Player& player )
{
	Card card( deck.GetCard() );
	player.AddCard( card );
}



void GameCoreExtras::PrintGameStatus( const Player& dealer, const Player& player )
{
	system( "cls" );
	dealer.Print();
	std::cout << std::endl << std::endl;
	player.Print();
}



bool GameCoreExtras::AddCardDecision( const Player& player )
{
	bool flagAddCard = false;
	if ( player.IsDealer() )
	{
		flagAddCard = ( player.Score() < MAX_DEALER_SCORE );
		Sleep( 1000 );
	}
	else
	{
		char answer;
		std::cout << "Add new card ? ( y / n )" << std::endl;
		std::cin >> answer;
		flagAddCard = ( ( answer == 'y' ) || ( answer == 'Y' ) );
	}
	return flagAddCard;
}