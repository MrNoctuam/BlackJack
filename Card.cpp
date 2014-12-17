#include "Card.h"
#include "Exception.h"
#include <iostream>

#define TEN 10


Card::Card() : id( 2 ), suit( Hearts ), score( 0 )
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


void Card::Print()
{
	std::string strName, strSuit;
	try
	{
		if ( ( id < minID ) || ( id > maxID ) )
			throw Exception( Exception::WRONG_ID, "void Card::Print()" );
	}
	catch ( Exception exc )
	{
		std::cout << exc.GetMainMessage() << std::endl
			<< exc.GetAdditionalMessage() << std::endl
			<< "CardID = " << id << std::endl
			<< "-------------------------" << std::endl << std::endl;
		system( "pause" );
		exit( exc.GetExceptionCode() );
	}
	switch ( suit )
	{
		case Hearts:
			strSuit = "Hearts";
			break;
		case Diamonds:
			strSuit = "Diamonds";
			break;
		case Clubs:
			strSuit = "Clubs";
			break;
		case Spades:
			strSuit = "Spades";
			break;
	}
	switch ( id )
	{
		case 11:
			strName = "Jack";
			break;
		case 12:
			strName = "Queen";
			break;
		case 13:
			strName = "King";
			break;
		case 14:
			strName = "Ace";
			break;
		default:
			strName.clear();
	}
	if ( strName.empty() )
	{
		std::cout << id;
	}
	else
	{
		std::cout << strName;
	}
	std::cout << "_of_" << strSuit << "; ";
}