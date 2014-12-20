#ifndef CARDVISUALIZERASCII_H
#define CARDVISUALIZERASCII_H

#include <vector>
#include <string>
#include "Card.h"
#include "CardVisualize.h"


class CardVisualizerASCII {
	public :
		CardVisualizerASCII();
		CardVisualizerASCII( const std::vector<Card>& cards );
		~CardVisualizerASCII();
		bool Empty() const;
		void Clear();
		void CreateNew( const std::vector<Card>& cards );
		void Print() const;
		static const size_t CardWidth = 13;
		static const size_t CardHeight = 12;
	private :
		std::string* body;
		size_t width;
		size_t heigth;
		
		void AllocateNewBody( const size_t cardsNumber );
		void AddCardToVisualization( const CardVisualize& cardVis, size_t cardIndex );
		void MakeVisualization( const std::vector<Card>& cards );
};


#endif