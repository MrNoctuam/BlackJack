#include "Card.h"
#include "Exception.h"
#include <iostream>

#define TEN 10
#define ELEVEN 11



Card::Card() : id( 2 ), suit( Hearts ), score( 0 ), faceStatus( FaceUp )
{
}



Card::Card( int newID, int newSuit ) : id( newID ), suit( newSuit ), score( ( id < TEN ) ? id : ( ( id == idAce ) ? 11 : TEN ) ), faceStatus( FaceUp )
{
}



Card::Card( int newID, int newSuit, int newScore ) : id( newID ), suit( newSuit ), score( newScore ), faceStatus( FaceUp )
{
}



Card::~Card()
{
	//nothing
}



Card& Card::operator= ( const Card& right )
{
	if ( this != &right )
	{
		id = right.id;
		suit = right.suit;
		score = right.score;
	}
	return *this;
}



void Card::Score( int value )
{
	score = value;
}



int Card::Score() const
{
	return score;
}



int Card::ID() const
{
	return id;
}



int Card::Suit() const
{
	return suit;
}



Card::FaceType Card::FaceStatus() const
{
	return faceStatus;
}



void Card::FaceStatus( Card::FaceType value )
{
	faceStatus = value;
}