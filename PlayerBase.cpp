#include "PlayerBase.h"
#include "CardVisualizerArrayASCII.h"
#include <iostream>
#include <iomanip>



PlayerBase::PlayerBase() : score( 0 ), status( Playing ), name( "Default Name" )
{
}



PlayerBase::PlayerBase( const std::string& newName ) : score( 0 ), status( Playing ), name( newName )
{
}



PlayerBase::~PlayerBase()
{
}



void PlayerBase::ClearHand()
{
	if ( !hand.empty() )
	{
		hand.clear();
	}
	score = 0;
	status = Playing;
}



int PlayerBase::Score() const
{
	return score;
}



std::string PlayerBase::Name() const
{
	return name;
}



void PlayerBase::Name( const std::string& newName )
{
	name = newName;
}



void PlayerBase::AddCard( const Card& newCard )
{
	hand.push_back( newCard );
	RefreshScore();
	if ( score > BlackJack )
	{
		status = Lose;
	}
}



PlayerBase::StatusType PlayerBase::Status() const
{
	return status;
}



void PlayerBase::Status( const StatusType newStatus )
{
	status = newStatus;
}




void PlayerBase::Print() const
{	
	std::cout << "______________________________________________________________________________________" << std::endl << std::endl;
	std::cout << name << std::endl << std::endl;
	CardVisualizerArrayASCII visualizer( hand );
	visualizer.Print();
	/*
	std::cout << "id: ";
	for ( unsigned int i = 0; i < hand.size(); i++ )
	{
		std::cout << hand[i].ID() << "; ";
	}
	std::cout << "\nSuit: ";
	for ( unsigned int i = 0; i < hand.size(); i++ )
	{
		std::cout << hand[i].Suit() << "; ";
	}
	*/
	std::cout << "\nScore: " << score << std::endl;
	std::cout << "______________________________________________________________________________________\n";
}



void PlayerBase::TurnCardsFaceUp()
{
	for ( unsigned int i = 0; i < hand.size(); i++ )
	{
		if ( hand[i].FaceStatus() == Card::FaceDown )
		{
			hand[i].FaceStatus( Card::FaceUp );
		}
	}
	RefreshScore();
}




void PlayerBase::RefreshScore()
{
	score = 0;
	int countAce = 0;
	for ( unsigned int i = 0; i < hand.size(); i++ )
	{
		if ( hand[i].FaceStatus() == Card::FaceUp )
		{
			if ( hand[i].ID() == Card::idAce )
			{
				countAce++;
			}
			score += hand[i].Score();
		}
	}
	if ( score > BlackJack )
	{
		while ( ( score > BlackJack ) && ( countAce > 0 ) )
		{
			score += AceMinScore - AceMaxScore;
			countAce--;
		}
	}
}