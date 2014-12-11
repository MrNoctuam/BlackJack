#include "Deck.h"
#include <cstdlib>
#include <ctime>

#define ID_NUMBER 13
#define SUIT_NUMBER 4


Deck::Deck() : deckNumber( 1 )
{
	fillDeck();
}


Deck::Deck( int newDeckNumber ) : deckNumber( newDeckNumber )
{
	fillDeck();
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
	fillDeck();
}


Card Deck::getCard()
{
	int index = randomCard();
	Card card = deck[index];
	deck.erase( deck.begin() + index );
	return card;
}


void Deck::fillDeck()
{
	for ( int i = 0; i < StandartSize; i++ )
	{
		for ( int j = 0; j < SUIT_NUMBER; j++ )
		{
			Card card ( i % ID_NUMBER, static_cast<Card::CardSuit>( j ) );
			for ( int k = 0; k < deckNumber; k++ )
			{
				deck.push_back( card );
			}
		}
	}
}


size_t Deck::randomCard()
{
	srand( time( NULL ) );
	return rand() % deck.size();
}