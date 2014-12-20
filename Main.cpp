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
	dealer.Print();
	std::cout << std::endl << std::endl;
	player.Print();
}

void Gameplay()
{
	Player player( Player::OrdinaryPlayer );
	Player dealer( Player::Dealer, "Dealer" );
	Deck deck;

	// Game with player
	while ( true )
	{
		PrintGameStatus( player, dealer );
		if ( player.getStatus() == Player::Lose )
		{
			std::cout << "You lose.\n";
			system( "pause" );
			return;
		}
		std::cout << "Add new card? (y/n) \n";
		char answer;
		std::cin >> answer;
		if ( answer == 'n' )
		{
			break;
		}
		GiveCardToPlayer( deck, player );
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
		return;
	}
	if ( dealer.getScore() > player.getScore() ) 
	{
		std::cout << "You lose.\n";
		return;
	}
	if ( dealer.getScore() == player.getScore() )
	{
		std::cout << "Deuce.\n";
		return;
	}
}

const int CardHeigth = 12;
const int CardWidth = 13;

char** MakeHearts()
{
	char** heartsSuit = new char*[CardHeigth];
	for ( size_t i = 0; i <= CardHeigth; i++ )
	{
		heartsSuit[i] = new char[CardWidth + 1];
	}
	heartsSuit[0] = "-------------";
	heartsSuit[1] = "|           |";
	heartsSuit[2] = "|           |";
	heartsSuit[3] = "|  **   **  |";
	heartsSuit[4] = "| ********* |";
	heartsSuit[5] = "| ********* |";
	heartsSuit[6] = "| ********* |";
	heartsSuit[7] = "|  *******  |";
	heartsSuit[8] = "|   *****   |";
	heartsSuit[9] = "|    ***    |";
	heartsSuit[10] = "|     *     |";
	heartsSuit[11] = "-------------";
	return heartsSuit;
}

int main()
{
	char answer = 'y';
	do
	{
		Gameplay();
		std::cout << "\n\nNew game? (y/n)" << std::endl;
		std::cin >> answer;
	} while ( answer != 'n' );
	/*char** test = MakeHearts();
	for ( int i = 0; i < CardHeigth; i++ )
	{
		std::cout << test[i] << std::endl;
	}
	/
	std::cout << "-------------" << std::endl
			  << "| A   *     |" << std::endl
			  << "|    ***    |" << std::endl
			  << "|   *****   |" << std::endl
			  << "|  *******  |" << std::endl
			  << "| ********* |" << std::endl
			  << "| ********* |" << std::endl
			  << "| ********* |" << std::endl
			  << "|  ** * **  |" << std::endl
			  << "|    ***    |" << std::endl
			  << "|   *****   |" << std::endl
			  << "-------------" << std::endl << std::endl;
	
	std::cout << "-------------" << std::endl
			  << "| A  ***    |" << std::endl
			  << "|    ***    |" << std::endl
			  << "|    ***    |" << std::endl
			  << "|     *     |" << std::endl
			  << "|***  *  ***|" << std::endl
			  << "|***********|" << std::endl
			  << "|***  *  ***|" << std::endl
			  << "|     *     |" << std::endl
			  << "|     *     |" << std::endl
			  << "|    ***    |" << std::endl
			  << "-------------" << std::endl << std::endl;

	
	std::cout << "-------------" << std::endl
			  << "| A         |" << std::endl
			  << "|           |" << std::endl
			  << "|  **   **  |" << std::endl
			  << "| ********* |" << std::endl
			  << "| ********* |" << std::endl
			  << "| ********* |" << std::endl
			  << "|  *******  |" << std::endl
			  << "|   *****   |" << std::endl
			  << "|    ***    |" << std::endl
			  << "|     *     |" << std::endl
			  << "-------------" << std::endl << std::endl;

	
	std::cout << "-------------" << std::endl
			  << "| A         |" << std::endl
			  << "|     *     |" << std::endl
			  << "|    ***    |" << std::endl
			  << "|   *****   |" << std::endl
			  << "|  *******  |" << std::endl
			  << "| ********* |" << std::endl
			  << "|  *******  |" << std::endl
			  << "|   *****   |" << std::endl
			  << "|    ***    |" << std::endl
			  << "|     *     |" << std::endl
			  << "-------------" << std::endl << std::endl;
			  */
	system( "pause" );
	return 0;
}