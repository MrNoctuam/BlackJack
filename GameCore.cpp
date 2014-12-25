#include "GameCore.h"
#include <iostream>




GameCore::GameCore() : deck( 1 ), player( Player::OrdinaryPlayer ), dealer( Player::Dealer, "Dealer" )
{
}



GameCore::~GameCore()
{
}



void GameCore::StartNew()
{
	player.ClearHand();
	dealer.ClearHand();
	deck.SetNew(); 

	GameCoreExtras::GiveCardToPlayer( deck, player );
	GameCoreExtras::GiveCardToPlayer( deck, player );
	GameCoreExtras::GiveCardToPlayer( deck, dealer );
	Card card( deck.GetCard() );
	card.FaceStatus( Card::FaceDown );
	dealer.AddCard( card );
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
			std::cout << "\nDeuce.\n";
		}
	}

	if ( player.Status() == Player::Lose )
	{
		dealer.Status( Player::Win );
	}
	
	if ( dealer.Status() == Player::Lose )
	{
		player.Status( Player::Win );
	}

	switch ( player.Status() )
	{
		case Player::Win :
			std::cout << "You win." << std::endl;
			break;
		case Player::Lose :
			std::cout << "You lose." << std::endl;
	}
}



void GameCore::GameWithPlayer( Player& currentPlayer )
{
	// fix it (double print status):
	GameCoreExtras::PrintGameStatus( dealer, player );
	while ( currentPlayer.Status() == Player::Playing )
	{
		if ( GameCoreExtras::AddCardDecision( currentPlayer ) )
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