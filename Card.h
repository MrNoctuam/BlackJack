#ifndef CARD_H
#define CARD_H 



class Card
{
	public:
		enum FaceType { FaceUp, FaceDown };

		Card();
		Card( int newID, int newSuit, int newScore );
		Card( const Card& src );
		~Card();

		Card& operator= ( const Card& right );
		void Score( int value );
		int Score() const;
		int ID() const;
		int Suit() const;
		FaceType FaceStatus() const;
		void FaceStatus( const FaceType value );

		static const int idAce = 14;
		static const int minID = 2;   // '2'.
		static const int maxID = 14;  // Ace.

		static const int Hearts = 0;
		static const int Diamonds = 1;
		static const int Clubs = 2;
		static const int Spades = 3;
		static const int minSuit = Hearts;
		static const int maxSuit = Spades;

	private:
		/* 
			id list:
			2 = '2'; 3 = '3'; 4 = '4'; 5 = '5'; 6 = '6'; 7 = '7'; 8 = '8'; 9 = '9'; 
			10 = '10'; 11 = 'Jack'; 12 = 'Queen'; 13 = 'King'; 14 = 'Ace'; 
		*/
		int id;
		int suit;
		int score;
		FaceType faceStatus;
};



#endif