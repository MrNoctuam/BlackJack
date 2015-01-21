#include "CardVisualizerASCII.h"
#include <iostream>



CardVisualizerASCII::CardVisualizerASCII() : body( 0 )
{
}



CardVisualizerASCII::CardVisualizerASCII( CardVisualizerASCII& src )
{
	AllocateNewBody();
	// REFACTORING
	CopyMatrix( src.body, src.width, src.height, body, width, height );
}



CardVisualizerASCII::~CardVisualizerASCII()
{
	Clear();
}



CardVisualizerASCII& CardVisualizerASCII::operator= ( const CardVisualizerASCII& src )
{
	if ( this != &src )
	{
		Clear();
		CopyMatrix( src.body, src.width, src.height, body, width, height );
	}
	return *this;
}



std::string CardVisualizerASCII::operator[] ( unsigned int index ) const
{
	return body[index];
}



bool CardVisualizerASCII::Empty() const
{
	return body == 0;
}



void CardVisualizerASCII::Clear()
{
	if ( !Empty() )
	{
		delete[] body;
	}
}



void CardVisualizerASCII::SetNew( const Card& card )
{
	if ( Empty() )
	{
		AllocateNewBody();
	}
	if ( card.FaceStatus() == Card::FaceDown )
	{
		CreateBack();
	}
	else
	{
		switch ( card.Suit() )
		{
			case Card::Spades:
				CreateSpades();
				break;
			case Card::Clubs:
				CreateClubs();
				break;
			case Card::Diamonds:
				CreateDiamonds();
				break;
			case Card::Hearts:
				CreateHearts();
				break;
		}
		InsertID( card.ID() );
	}
}



char CardVisualizerASCII::GetElement( const unsigned int x, const unsigned int y ) const
{
	return ( ( x < width ) && ( y < height ) ) ? body[x][y] : 0;
}


unsigned int CardVisualizerASCII::GetWidth()
{
	return width;
}



unsigned int CardVisualizerASCII::GetHeight()
{
	return height;
}



void CardVisualizerASCII::CreateHearts()
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



void CardVisualizerASCII::CreateDiamonds()
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



void CardVisualizerASCII::CreateClubs()
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



void CardVisualizerASCII::CreateSpades()
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



void CardVisualizerASCII::CreateBack()
{
	if ( Empty() )
	{
		AllocateNewBody();
	}
	body[0] =  " ----------- ";
	body[1] =  "|****   ****|";
	body[2] =  "|*  *****  *|";
	body[3] =  "|*  *****  *|";
	body[4] =  "|*  *****  *|";
	body[5] =  "| ********* |";
	body[6] =  "| ********* |";
	body[7] =  "|*  *****  *|";
	body[8] =  "|*  *****  *|";
	body[9] =  "|*  *****  *|";
	body[10] = "|****   ****|";
	body[11] = " ----------- ";
}



void CardVisualizerASCII::AllocateNewBody()
{
	body = new std::string[height];
}



void CardVisualizerASCII::InsertID( int id )
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


bool CardVisualizerASCII::CopyMatrix( std::string* src, const unsigned int srcWidth, const unsigned int srcHeight,
								std::string* dst, const unsigned int dstWidth, const unsigned int dstHeight )
{
	// FIX with memcpy()!
	bool resFlag = ( ( srcWidth == dstWidth ) && ( srcHeight == dstHeight ) );
	if ( resFlag )
	{
		for ( unsigned int i = 0; i < srcHeight; i++ )
		{
			dst[i].resize( dstWidth );
			for ( unsigned int j = 0; j < srcWidth; j++ )
			{
				dst[i][j] = src[i][j];
			}
		}
	}
	return resFlag;
}



void CardVisualizerASCII::testPrint()
{
	for ( unsigned int i = 0; i < height; i++ )
	{
		for ( unsigned int j = 0; j < width; j++ )
		{
			std::cout << body[i][j];
		}
		std::cout << std::endl;
	}
}