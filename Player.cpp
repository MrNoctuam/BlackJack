#include "Player.h"
#include "CardVisualizerASCII.h"
#include <iostream>

#define ACE 14
#define ACE_MAX_SCORE 11
#define ACE_MIN_SCORE 1


Player::Player() : score( 0 ), status( Playing ), type( OrdinaryPlayer ), name( "Player" )
{
}



Player::Player( Player::PlayerType newType ) : score( 0 ), status( Playing ), type( newType ), name( "Player" )
{
}



Player::Player( Player::PlayerType newType, std::string newName ) : score( 0 ), status( Playing ), type( newType ), name( newName )
{
}



Player::~Player()
{
}



void Player::ClearHand()
{
	if ( !hand.empty() )
		hand.clear();
	score = 0;
	status = Playing;
}



int Player::Score() const
{
	return score;
}



void Player::AddCard( Card newCard )
{
	hand.push_back( newCard );
	RefreshScore();
	if ( score > BlackJack )
	{
		status = Lose;
	}
}



Player::StatusType Player::Status() const
{
	return status;
}



void Player::Status( const StatusType newStatus )
{
	status = newStatus;
}




void Player::Print() const
{	
	std::cout << "============ Player: " << name << " ============" << std::endl;
	CardVisualizerASCII visualizer( hand );
	visualizer.Print();
	std::cout << "id: ";
	for ( size_t i = 0; i < hand.size(); i++ )
	{
		std::cout << hand[i].ID() << "; ";
	}
	std::cout << "\nSuit: ";
	for ( size_t i = 0; i < hand.size(); i++ )
	{
		std::cout << hand[i].Suit() << "; ";
	}
	std::cout << "\nScore: " << score << std::endl;
	/*
	for ( size_t i = 0; i < hand.size(); i++ )
	{
		hand[i].Print();
	}
	*/
	std::cout << "\n========================\n";
}



bool Player::IsDealer() const
{
	return type == Dealer;
}



void Player::RefreshScore()
{
	score = 0;
	int countAce = 0;
	for ( size_t i = 0; i < hand.size(); i++ )
	{
		if ( hand[i].ID() == Card::idAce )
		{
			countAce++;
		}
		score += hand[i].Score();
	}
	if ( score > BlackJack )
	{
		while ( ( score > BlackJack ) && ( countAce > 0 ) )
		{
			score += AceMinScore - AceMaxScore;
			countAce--;
		}
	}
}