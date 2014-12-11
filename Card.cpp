#include "Card.h"

#define TEN 10


Card::Card() : id( 0 ), suit( Hearts ), score( 0 )
{
}


Card::Card( int newID, CardSuit newSuit ) : id( newID ), suit( newSuit ), score( ( id < TEN ) ? id : TEN )
{
}


Card::Card( int newID, CardSuit newSuit, int newScore ) : id( newID ), suit( newSuit ), score( newScore )
{
}


Card::~Card()
{
	//nothing
}


void Card::setScore( int value )
{
	score = value;
}


int Card::getScore()
{
	return score;
}


int Card::getID()
{
	return id;
}


Card::CardSuit Card::getSuit()
{
	return suit;
}
