#include "CardVisualize.h"
#include <iostream>



CardVisualize::CardVisualize() : body( 0 )
{
}



CardVisualize::CardVisualize( CardVisualize& src )
{
	AllocateNewBody();
	// REFACTORING
	CopyMatrix( src.body, src.width, src.height, body, width, height );
}



CardVisualize::~CardVisualize()
{
	Clear();
}



CardVisualize& CardVisualize::operator= ( const CardVisualize& src )
{
	if ( this != &src )
	{
		Clear();
		CopyMatrix( src.body, src.width, src.height, body, width, height );
	}
	return *this;
}



std::string CardVisualize::operator[] ( size_t index ) const
{
	return body[index];
}



bool CardVisualize::Empty() const
{
	return body == 0;
}



void CardVisualize::Clear()
{
	if ( !Empty() )
	{
		delete[] body;
	}
}



void CardVisualize::SetNew( const Card& card )
{
	if ( Empty() )
	{
		AllocateNewBody();
	}
	switch ( card.getSuit() )
	{
		case Card::Spades :
			CreateSpades();
			break;
		case Card::Clubs : 
			CreateClubs();
			break;
		case Card::Diamonds :
			CreateDiamonds();
			break;
		case Card::Hearts :
			CreateHearts();
			break;
	}
	/*
	//testPrint();
	for ( size_t i = 0; i < height; i++ )
	{
		std::cout << testStr[i] << std::endl;
	}
	std::cout << "body[" << CardIDPosY << "][" << CardIDPosX << "] = +" << body[CardIDPosY][CardIDPosX] << "+;\n";
	*/
	InsertID( card.getID() );
}



char CardVisualize::GetElement( const size_t x, const size_t y ) const
{
	return ( ( x < width ) && ( y < height ) ) ? body[x][y] : '\0';
}


size_t CardVisualize::GetWidth()
{
	return width;
}



size_t CardVisualize::GetHeight()
{
	return height;
}



void CardVisualize::CreateHearts()
{
	if ( Empty() )
	{
		AllocateNewBody();
	}
	body[0] =  " ----------- ";
	body[1] =  "|           |";
	body[2] =  "|           |";
	body[3] =  "|  **   **  |";
	body[4] =  "| ********* |";
	body[5] =  "| ********* |";
	body[6] =  "| ********* |";
	body[7] =  "|  *******  |";
	body[8] =  "|   *****   |";
	body[9] =  "|    ***    |";
	body[10] = "|     *     |";
	body[11] = " ----------- ";
}



void CardVisualize::CreateDiamonds()
{
	if ( Empty() )
	{
		AllocateNewBody();
	}
	body[0] =  " ----------- ";
	body[1] =  "|           |";
	body[2] =  "|     *     |";
	body[3] =  "|    ***    |";
	body[4] =  "|   *****   |";
	body[5] =  "|  *******  |";
	body[6] =  "| ********* |";
	body[7] =  "|  *******  |";
	body[8] =  "|   *****   |";
	body[9] =  "|    ***    |";
	body[10] = "|     *     |";
	body[11] = " ----------- ";
}



void CardVisualize::CreateClubs()
{
	if ( Empty() )
	{
		AllocateNewBody();
	}
	body[0] =  " ----------- ";
	body[1] =  "|    ***    |";
	body[2] =  "|    ***    |";
	body[3] =  "|    ***    |";
	body[4] =  "|     *     |";
	body[5] =  "|***  *  ***|";
	body[6] =  "|***********|";
	body[7] =  "|***  *  ***|";
	body[8] =  "|     *     |";
	body[9] =  "|     *     |";
	body[10] = "|    ***    |";
	body[11] = " ----------- ";
}



void CardVisualize::CreateSpades()
{
	if ( Empty() )
	{
		AllocateNewBody();
	}
	body[0] =  " ----------- ";
	body[1] =  "|     *     |";
	body[2] =  "|    ***    |";
	body[3] =  "|   *****   |";
	body[4] =  "|  *******  |";
	body[5] =  "| ********* |";
	body[6] =  "| ********* |";
	body[7] =  "| ********* |";
	body[8] =  "|  ** * **  |";
	body[9] =  "|    ***    |";
	body[10] = "|   *****   |";
	body[11] = " ----------- ";
}



void CardVisualize::AllocateNewBody()
{
	body = new std::string[height];
}



void CardVisualize::InsertID( int id )
{
	switch ( id )
	{
		case 10:
			body[CardIDPosY][CardIDPosX] = '1';
			body[CardIDPosY][CardIDPosX + 1] = '0';
			break;
		case 11:
			body[CardIDPosY][CardIDPosX] = 'J';
			break;
		case 12:
			body[CardIDPosY][CardIDPosX] = 'Q';
			break;
		case 13:
			body[CardIDPosY][CardIDPosX] = 'K';
			break;
		case 14:
			body[CardIDPosY][CardIDPosX] = 'A';
			break;
		default:
			body[CardIDPosY][CardIDPosX] = '0' + static_cast<char> ( id );
	}
}


bool CardVisualize::CopyMatrix( std::string* src, const size_t srcWidth, const size_t srcHeight,
								std::string* dst, const size_t dstWidth, const size_t dstHeight )
{
	// FIX with memcpy()!
	bool resFlag = ( ( srcWidth == dstWidth ) && ( srcHeight == dstHeight ) );
	if ( resFlag )
	{
		for ( size_t i = 0; i < srcHeight; i++ )
		{
			dst[i].resize( dstWidth );
			for ( size_t j = 0; j < srcWidth; j++ )
			{
				dst[i][j] = src[i][j];
			}
		}
	}
	return resFlag;
}



void CardVisualize::testPrint()
{
	for ( size_t i = 0; i < height; i++ )
	{
		for ( size_t j = 0; j < width; j++ )
		{
			std::cout << body[i][j];
		}
		std::cout << std::endl;
	}
}