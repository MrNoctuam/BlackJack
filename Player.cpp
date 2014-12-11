#include "Player.h"

#define ACE 14
#define ACE_MAX_SCORE 11
#define ACE_MIN_SCORE 1


Player::Player() : score( 0 ), active( true )
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
	active = true;
}


int Player::getScore()
{
	return score;
}


void Player::AddCard( Card newCard )
{
	hand.push_back( newCard );
	refreshScore();
}


void Player::refreshScore()
{
	score = 0;
	for ( int i = 0; i < hand.size(); i++ )
	{
		if ( hand[i].getID() == ACE )
		{
			score += ( score > ( BlackJack - ACE_MAX_SCORE ) ) ? ACE_MAX_SCORE : ACE_MIN_SCORE;
		}
		score += hand[i].getScore();
	}
}