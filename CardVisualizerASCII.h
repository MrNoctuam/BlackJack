#ifndef CARDVISUALIZERASCII_H
#define CARDVISUALIZERASCII_H

#include <string>
#include "Card.h"



class CardVisualizerASCII {
	public:
		CardVisualizerASCII();
		CardVisualizerASCII( CardVisualizerASCII& src );
		CardVisualizerASCII( const Card& card );
		~CardVisualizerASCII();
		CardVisualizerASCII& operator= ( const CardVisualizerASCII& src );
		std::string operator[] ( unsigned int index ) const;
		bool Empty() const;
		void Clear();
		void SetNew( const Card& card );
		char GetElement( const unsigned int x, const unsigned int y ) const;
		static unsigned int GetWidth();
		static unsigned int GetHeight();

	private:
		static const unsigned int width = 13;
		static const unsigned int height = 12;
		static const unsigned int CardIDPosX = 2;
		static const unsigned int CardIDPosY = 1;
		std::string* body;
		void CreateHearts();
		void CreateDiamonds();
		void CreateClubs();
		void CreateSpades();
		void CreateBack();
		void AllocateNewBody();
		void InsertID( int id );
		static bool CopyMatrix( std::string* src, const unsigned int srcWidth, const unsigned int srcHeight,
								std::string* dst, const unsigned int dstWidth, const unsigned int dstHeight );
		void testPrint();
};



#endif