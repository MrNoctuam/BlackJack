#include "CardVisualizerArrayASCII.h"
#include <iostream>



CardVisualizerArrayASCII::CardVisualizerArrayASCII() : body( 0 ), heigth( 0 ), width( 0 )
{
}



CardVisualizerArrayASCII::CardVisualizerArrayASCII( const std::vector<Card>& cards ) : body( 0 ), heigth( 0 ), width( 0 )
{
	CreateNew( cards );
}


CardVisualizerArrayASCII::~CardVisualizerArrayASCII()
{
	Clear();
}



bool CardVisualizerArrayASCII::Empty() const
{
	return ( ( width == 0 ) && ( heigth == 0 ) && ( body == 0 ) );
}




void CardVisualizerArrayASCII::Clear()
{
	if ( !Empty() )
	{
		delete[] body;
	}
	width = 0;
	heigth = 0;
}



void CardVisualizerArrayASCII::CreateNew( const std::vector<Card>& cards )
{
	MakeVisualization( cards );
}



void CardVisualizerArrayASCII::Print() const
{
	if ( !Empty() )
	{
		for ( unsigned int i = 0; i < heigth; i++ )
		{
			std::cout << body[i] << std::endl;
		}
	}
}



void CardVisualizerArrayASCII::AllocateNewBody( const unsigned int cardsNumber )
{
	if ( !Empty() )
	{
		Clear();
	}
	heigth = CardHeight;
	width = CardWidth * ( cardsNumber ) + 1;
	body = new std::string[heigth];
}



void CardVisualizerArrayASCII::AddCardToVisualization( const CardVisualizerASCII& cardVis, unsigned int cardIndex )
{
	for ( unsigned int i = 0; i < CardHeight; i++ )
	{
		if ( !body[i].empty() )
		{
			body[i].pop_back();
		}
		body[i] += cardVis[i];
		/*
		for ( unsigned int j = 0; j < CardWidth; j++ )
		{
			body[i][cardIndex * CardWidth + j] = cardVis.GetElement( i, j );
		}
		body[i][(cardIndex + 1)  *  CardWidth] = '\n';
		*/
	}
}



void CardVisualizerArrayASCII::MakeVisualization( const std::vector<Card>& cards )
{
	AllocateNewBody( cards.size() );
	CardVisualizerASCII cardVis;
	for ( unsigned int i = 0; i < cards.size(); i++ )
	{
		cardVis.SetNew( cards[i] );
		AddCardToVisualization( cardVis, i );
	}
}