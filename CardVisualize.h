#ifndef CARDVISUALIZE_H
#define CARDVISUALIZE_H

#include <string>
#include "Card.h"



class CardVisualize {
	public:
		CardVisualize();
		CardVisualize( CardVisualize& src );
		CardVisualize( const Card& card );
		~CardVisualize();
		CardVisualize& operator= ( const CardVisualize& src );
		std::string operator[] ( size_t index ) const;
		bool Empty() const;
		void Clear();
		void SetNew( const Card& card );
		char GetElement( const size_t x, const size_t y ) const;
		static size_t GetWidth();
		static size_t GetHeight();
	private:
		static const size_t width = 13;
		static const size_t height = 12;
		static const size_t CardIDPosX = 2;
		static const size_t CardIDPosY = 1;
		std::string* body;
		void CreateHearts();
		void CreateDiamonds();
		void CreateClubs();
		void CreateSpades();
		void AllocateNewBody();
		void InsertID( int id );
		static bool CopyMatrix( std::string* src, const size_t srcWidth, const size_t srcHeight,
								std::string* dst, const size_t dstWidth, const size_t dstHeight );

		void testPrint();
};



#endif