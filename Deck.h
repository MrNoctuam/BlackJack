#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck
{
	public:
		Deck();
		Deck( int newDeckNumber );
		~Deck();
		void Clear();
		bool Empty();
		void SetNew();
		Card getCard();

	private:
		const int StandartSize = 52;
		int deckNumber;
		std::vector<Card> deck;
		void fillDeck();
		size_t randomCard();
};


#endif