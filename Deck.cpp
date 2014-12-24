#include "Deck.h"
#include <cstdlib>
#include <ctime>



Deck::Deck() : deckNumber( 1 )
{
	FillDeck();
}



Deck::Deck( int newDeckNumber ) : deckNumber( newDeckNumber )
{
	FillDeck();
}



Deck::~Deck()
{
}



void Deck::Clear()
{
	if ( !deck.empty() )
		deck.clear();
}



bool Deck::Empty()
{
	return deck.empty();
}



void Deck::SetNew()
{
	Clear();
	FillDeck();
}



Card Deck::GetCard()
{
	int index = RandomCard();
	Card card = deck[index];
	deck.erase( deck.begin() + index );
	return card;
}



void Deck::FillDeck()
{
	for ( int i = Card::minID; i <= Card::maxID; i++ )
	{
		for ( int j = Card::minSuit; j < Card::maxSuit; j++ )
		{
			//Card card( i % ( Card::maxID + 1 ), j );
			int cardID = i % ( Card::maxID + 1 );
			// fix this:
			Card card( cardID, j, ( cardID < 10 ) ? cardID : ( ( cardID == Card::idAce ) ? 11 : 10 ) );
			for ( int k = 0; k < deckNumber; k++ )
			{
				deck.push_back( card );
			}
		}
	}
}



size_t Deck::RandomCard()
{
	srand( time( NULL ) );
	return rand() % deck.size();
}