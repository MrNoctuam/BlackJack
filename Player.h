#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"


class Player
{
	public:
		Player();
		~Player();
		void ClearHand();
		int getScore();
		void AddCard( const Card newCard );
		const int BlackJack = 21;
	private:
		std::vector<Card> hand;
		int score;
		bool active;
		void refreshScore();
};


#endif