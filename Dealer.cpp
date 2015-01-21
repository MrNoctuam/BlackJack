#include "Dealer.h"
#include "Display.h"

#define DELAY_VALUE 500


Dealer::Dealer() : PlayerBase( "Dealer" )
{
}



Dealer::Dealer( std::string newName ) : PlayerBase( newName )
{
}



Dealer::~Dealer()
{
}



bool Dealer::AddCardDecision() const
{
	Display::Delay( DELAY_VALUE );
	return ( Score() < MaxDealerScore );
}