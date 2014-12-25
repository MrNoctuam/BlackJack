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
		int Score() const;
		void AddCard( const Card newCard );
		StatusType Status() const;
		void Status( const StatusType newStatus );
		void Print() const;
		void TurnCardsFaceUp();
		bool IsDealer() const;


	private:
		std::vector<Card> hand;
		int score;
		PlayerType type;
		StatusType status;
		std::string name;
		static const int AceMinScore = 1;
		static const int AceMaxScore = 11;

		void RefreshScore();
};



#endif