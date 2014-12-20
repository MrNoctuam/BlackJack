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



Player::Player( Player::PlayerType newType, std::string newName ) : score( 0 ), status( Playing ), 																	type( newType ), name( newName )
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



int Player::getScore()
{
	return score;
}



void Player::AddCard( Card newCard )
{
	hand.push_back( newCard );
	refreshScore();
	if ( score > BlackJack )
	{
		status = Lose;
	}
}



Player::StatusType Player::getStatus()
{
	return status;
}


void Player::Print()
{	
	std::cout << "============ Player: " << name << " ============" << std::endl;
	CardVisualizerASCII visualizer( hand );
	visualizer.Print();
	std::cout << "id: ";
	for ( size_t i = 0; i < hand.size(); i++ )
	{
		std::cout << hand[i].getID() << "; ";
	}
	std::cout << "\nSuit: ";
	for ( size_t i = 0; i < hand.size(); i++ )
	{
		std::cout << hand[i].getSuit() << "; ";
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

void Player::refreshScore()
{
	score = 0;
	for ( size_t i = 0; i < hand.size(); i++ )
	{
		if ( hand[i].getID() == ACE )
		{
			score += ( score > ( BlackJack - ACE_MAX_SCORE ) ) ? ACE_MAX_SCORE : ACE_MIN_SCORE;
		}
		score += hand[i].getScore();
	}
}