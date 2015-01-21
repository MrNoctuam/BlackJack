#ifndef DEALER_H
#define DEALER_H

#include "PlayerBase.h"



class Dealer : public PlayerBase 
{
	public:
		Dealer();
		Dealer( std::string newName );
		virtual ~Dealer();
		bool AddCardDecision() const;
	
	private:
		static const int MaxDealerScore = 17;
};



#endif