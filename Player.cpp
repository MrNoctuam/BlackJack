#include "Player.h"
#include "CardVisualizerArrayASCII.h"
#include <iostream>



Player::Player() : PlayerBase("Player"), money( 0 )
{
}



Player::Player( std::string newName ) : PlayerBase( newName ), money( 0 )
{
}



Player::Player( std::string newName, int newMoney ) : PlayerBase( newName ), money( newMoney )
{
}



Player::~Player()
{
}



void Player::Print() const
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
	std::cout << "Money: $" << money << std::endl;
	std::cout << "______________________________________________________________________________________\n";
}



bool Player::AddCardDecision() const
{
	bool flagAddCard = false;
	char answer;
	std::cout << "\n\nAdd new card ? ( y / n )" << std::endl;
	std::cin >> answer;
	flagAddCard = ( ( answer == 'y' ) || ( answer == 'Y' ) );
	return flagAddCard;
}



int Player::Money() const
{
	return money;
}



void Player::Money( int value )
{
	money = value;
}



void Player::AddMoney( int value )
{
	money += value;
}



void Player::SubMoney( int value )
{
	money -= value;
}