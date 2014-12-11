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
		int getScore();
		int getID();
		CardSuit getSuit();
	private:
		// 2 - 2; 3 - 3; ... 11 - J; 12 - Q; 13 - K; 14 - A
		int id;
		CardSuit suit;
		int score;
};


#endif