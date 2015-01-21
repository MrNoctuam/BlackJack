#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerBase.h"



class Player : public PlayerBase 
{
	public:
		Player();
		Player( std::string newName );
		Player( std::string newName, int newMoney );
		virtual ~Player();
		void Print() const;
		bool AddCardDecision() const;
		int Money() const;
		void Money( int value );
		void AddMoney( int value );
		void SubMoney( int value );

	private:
		int money;
};



#endif