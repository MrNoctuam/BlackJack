#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include <vector>
#include <string>
#include "Card.h"



class PlayerBase
{
	public:
		static const int BlackJack = 21;
		enum StatusType { Playing, Waiting, Win, Lose };

		PlayerBase();
		PlayerBase( const std::string& newName );
		~PlayerBase();

		void ClearHand();
		int Score() const;
		std::string Name() const;
		void Name( const std::string& newName );
		void AddCard( const Card& newCard );
		StatusType Status() const;
		void Status( const StatusType newStatus );
		virtual void Print() const;
		void TurnCardsFaceUp();
		virtual bool AddCardDecision() const = 0;


	protected:
		std::vector<Card> hand;
		int score;
		StatusType status;
		std::string name;
		static const int AceMinScore = 1;
		static const int AceMaxScore = 11;

		void RefreshScore();
};



#endif