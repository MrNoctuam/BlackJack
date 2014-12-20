#ifndef CARD_H
#define CARD_H 


class Card
{
	public:
		Card();
		enum CardSuit { Hearts, Diamonds, Clubs, Spades };
		Card( int newID, CardSuit newSuit );
		Card( int newID, CardSuit newSuit, int newScore );
		~Card();
		void setScore( int value );
		int getScore() const;
		int getID() const;
		CardSuit getSuit() const;
		void Print() const;
		Card& operator= ( const Card& right )
		{
			if ( this == &right )
				return *this;
			id = right.id;
			suit = right.suit;
			score = right.score;
			return *this;
		}
	private:
		// 2 - 2; 3 - 3; ... 11 - J; 12 - Q; 13 - K; 14 - A
		int id;
		CardSuit suit;
		int score;
		const int minID = 2;
		const int maxID = 14;
};


#endif