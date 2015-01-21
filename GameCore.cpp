#include "GameCore.h"
#include "Display.h"
#include <iostream>

#define DEFAULT_MONEY 100
#define DELAY_VALUE 500



GameCore::GameCore() : deck( 1 ), player( "Player", DEFAULT_MONEY )
{
}



GameCore::~GameCore()
{
}



void GameCore::StartNew()
{
	isFinished = false;
	MakeBet();
	player.ClearHand();
	dealer.ClearHand();
	deck.SetNew(); 

	GameCoreExtras::PrintGameStatus( dealer, player );
	Display::Delay( DELAY_VALUE );

	GiveCardTo( player );
	GiveCardTo( player );
	GiveCardTo( dealer );

	Card card( deck.GetCard() );
	card.FaceStatus( Card::FaceDown );
	dealer.AddCard( card );
	GameCoreExtras::PrintGameStatus( dealer, player );
}



void GameCore::NewPlayer( const std::string& playerName )
{
	statsCount.Reset();

	player.Name( playerName );
	player.ClearHand();
	player.Money( DEFAULT_MONEY );
}



void GameCore::Gameplay()
{
	GameWithPlayer( player );
	
	if ( !isFinished )
	{
		dealer.TurnCardsFaceUp();
		GameWithPlayer( dealer );
	}

	if ( ( player.Status() != Player::Lose ) && ( dealer.Status() != Player::Lose ) )
	{
		if ( player.Score() < dealer.Score() )
		{
			player.Status( Player::Lose );
		}
		if ( player.Score() > dealer.Score() )
		{
			dealer.Status( Player::Lose );
		}
		if ( player.Score() == dealer.Score() )
		{
			player.AddMoney( bet );
			std::cout << "\nDeuce.\n";
		}
	}

	if ( player.Status() == Player::Lose )
	{
		dealer.Status( Player::Win );
		statsCount.CountLoseIncrease( bet );
	}
	
	if ( dealer.Status() == Player::Lose )
	{
		player.Status( Player::Win );
		statsCount.CountWinIncrease( bet );
	}

	switch ( player.Status() )
	{
		case Player::Win :
			player.AddMoney( bet * 2 );
			std::cout << "\nYou win." << std::endl;
			break;
		case Player::Lose :
			std::cout << "\nYou lose." << std::endl;
	}

	if ( player.Money() == 0 )
	{
		std::cout << "\nNo money." << std::endl;
	}
}



void GameCore::GameWithPlayer( PlayerBase& currentPlayer )
{
	// fix it (double print status):
	GameCoreExtras::PrintGameStatus( dealer, player );
	while ( currentPlayer.Status() == Player::Playing )
	{
		if ( currentPlayer.AddCardDecision() )
		{
			GameCoreExtras::GiveCardToPlayer( deck, currentPlayer );
			RefreshGameStatus();
		}
		else
		{
			currentPlayer.Status( Player::Waiting );
		}
		GameCoreExtras::PrintGameStatus( dealer, player );
	}
}



void GameCore::RefreshGameStatus()
{
	isFinished = ( ( player.Status() == Player::Win ) || ( player.Status() == Player::Lose ) );
}



void GameCore::RefreshStats()
{
	stats.ReadFromFile();
	stats.Add( player.Name(), statsCount );
	stats.SaveToFile();
}



bool GameCore::PlayerHasMoney()
{
	return ( player.Money() > 0 );
}



void GameCore::MakeBet()
{
	bool isCorrectValue = false;
	do
	{
		Display::Clear();
		std::cout << "Money: $ " << player.Money() << std::endl;
		std::cout << "Your bet: $ ";
		std::cin >> bet;
		if ( ( bet <= 0 ) || ( bet > player.Money() ) )
		{
			std::cout << "Error. Value must be between 0 and " << player.Money() << std::endl;
			Display::ReadKey();
		}
		else
		{
			isCorrectValue = true;
		}
	} while ( !isCorrectValue );
	player.SubMoney( bet );
}



void GameCore::GiveCardTo( PlayerBase& currentPlayer )
{
	GameCoreExtras::GiveCardToPlayer( deck, currentPlayer );
	GameCoreExtras::PrintGameStatus( dealer, player );
	Display::Delay( DELAY_VALUE );
}