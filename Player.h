#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Card.h"


class Player
{
	public:
		static const int BlackJack = 21;
		enum StatusType { Playing, Waiting, Win, Lose };
		enum PlayerType { OrdinaryPlayer, Dealer };

		Player();
		Player( PlayerType newType );
		Player( PlayerType newType, std::string newName );
		~Player();

		void ClearHand();
		int getScore();
		void AddCard( const Card newCard );
		StatusType getStatus();
		void Print();

	private:
		std::vector<Card> hand;
		int score;
		PlayerType type;
		StatusType status;
		std::string name;
		void refreshScore();
};


#endif