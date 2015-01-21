#ifndef CARDVISUALIZERARRAYASCII_H
#define CARDVISUALIZERARRAYASCII_H

#include <vector>
#include <string>
#include "Card.h"
#include "CardVisualizerASCII.h"


class CardVisualizerArrayASCII {
	public :
		CardVisualizerArrayASCII();
		CardVisualizerArrayASCII( const std::vector<Card>& cards );
		~CardVisualizerArrayASCII();

		bool Empty() const;
		void Clear();
		void CreateNew( const std::vector<Card>& cards );
		void Print() const;
		static const unsigned int CardWidth = 13;
		static const unsigned int CardHeight = 12;

	private :
		std::string* body;
		unsigned int width;
		unsigned int heigth;
		
		void AllocateNewBody( const unsigned int cardsNumber );
		void AddCardToVisualization( const CardVisualizerASCII& cardVis, unsigned int cardIndex );
		void MakeVisualization( const std::vector<Card>& cards );
};


#endif