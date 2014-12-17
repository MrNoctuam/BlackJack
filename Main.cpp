//#include "GameCore.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <Windows.h>

#define MAX_DEALER_SCORE 17


void GiveCardToPlayer( Deck& deck, Player& playerName )
{
	Card card( deck.getCard() );
	playerName.AddCard( card );
}


void PrintGameStatus( Player player, Player dealer )
{
	system( "cls" );
	player.Print();
	std::cout << std::endl << std::endl;
	dealer.Print();
}

void Gameplay()
{
	Player player( Player::OrdinaryPlayer );
	Player dealer( Player::Dealer );
	Deck deck;

	// Game with player
	while ( true )
	{
		PrintGameStatus( player, dealer );
		std::cout << "Add new card? (y/n) \n";
		char answer;
		std::cin >> answer;
		if ( answer == 'n' )
		{
			break;
		}
		GiveCardToPlayer( deck, player );
		if ( player.getStatus() == Player::Lose )
		{
			std::cout << "You lose.\n";
			system( "pause" );
			exit( 0 );
		}		
		if ( player.getStatus() == Player::Waiting )
		{
			break;
		}
	}

	while ( true )
	{
		PrintGameStatus( player, dealer );
		if ( dealer.getScore() >= MAX_DEALER_SCORE )
			break;
		GiveCardToPlayer( deck, dealer );
		Sleep( 1000 );
	}

	if ( ( dealer.getScore() > Player::BlackJack ) || ( dealer.getScore() < player.getScore() ) )
	{
		std::cout << "You win.\n";
	}
	if ( dealer.getScore() > player.getScore() ) 
	{
		std::cout << "You lose.\n";
	}
	if ( dealer.getScore() == player.getScore() )
	{
		std::cout << "Deuce.\n";
	}
}


int main()
{
	Gameplay();
	system( "pause" );
	return 0;
}