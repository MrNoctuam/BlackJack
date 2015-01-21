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



bool Deck::Empty() const
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
			int cardID = i % ( Card::maxID + 1 );
			int cardScore = ( ( cardID < 10 ) ? cardID : 10 );
			if ( cardID == Card::idAce )
			{
				cardScore = 11;
			}
			Card card( cardID, j, cardScore );
			for ( int k = 0; k < deckNumber; k++ )
			{
				deck.push_back( card );
			}
		}
	}
}



unsigned int Deck::RandomCard()
{
	srand( time( NULL ) );
	return rand() % deck.size();
}