#include "CardVisualizerASCII.h"
#include <iostream>



CardVisualizerASCII::CardVisualizerASCII() : body( 0 ), heigth( 0 ), width( 0 )
{
}



CardVisualizerASCII::CardVisualizerASCII( const std::vector<Card>& cards )
{
	CreateNew( cards );
}


CardVisualizerASCII::~CardVisualizerASCII()
{
	Clear();
}



bool CardVisualizerASCII::Empty() const
{
	return ( ( width == 0 ) && ( heigth == 0 ) && ( body == 0 ) );
}




void CardVisualizerASCII::Clear()
{
	if ( !Empty() )
	{
		delete[] body;
	}
	width = 0;
	heigth = 0;
}



void CardVisualizerASCII::CreateNew( const std::vector<Card>& cards )
{
	MakeVisualization( cards );
}



void CardVisualizerASCII::Print() const
{
	if ( !Empty() )
	{
		for ( size_t i = 0; i < heigth; i++ )
		{
			std::cout << body[i] << std::endl;
		}
	}
}



void CardVisualizerASCII::AllocateNewBody( const size_t cardsNumber )
{
	if ( !Empty() )
	{
		Clear();
	}
	heigth = CardHeight;
	width = CardWidth * ( cardsNumber ) + 1;
	body = new std::string[heigth];
}



void CardVisualizerASCII::AddCardToVisualization( const CardVisualize& cardVis, size_t cardIndex )
{
	for ( size_t i = 0; i < CardHeight; i++ )
	{
		if ( !body[i].empty() )
		{
			body[i].pop_back();
		}
		body[i] += cardVis[i];
		/*
		for ( size_t j = 0; j < CardWidth; j++ )
		{
			body[i][cardIndex * CardWidth + j] = cardVis.GetElement( i, j );
		}
		body[i][(cardIndex + 1)  *  CardWidth] = '\n';
		*/
	}
}



void CardVisualizerASCII::MakeVisualization( const std::vector<Card>& cards )
{
	AllocateNewBody( cards.size() );
	CardVisualize cardVis;
	for ( size_t i = 0; i < cards.size(); i++ )
	{
		cardVis.SetNew( cards[i] );
		AddCardToVisualization( cardVis, i );
	}
}