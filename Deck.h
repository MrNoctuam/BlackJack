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
		bool Empty() const;
		void SetNew();
		Card GetCard();

	private:
		static const int StandartSize = 52;
		int deckNumber;
		std::vector<Card> deck;
		void FillDeck();
		unsigned int RandomCard();
};



#endif