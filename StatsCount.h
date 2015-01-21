#ifndef STATSCOUNT_H
#define STATSCOUNT_H



class StatsCount {
	public:
		StatsCount();
		~StatsCount();

		void Reset();
		void CountTotalPlaysIncrease();
		void CountWinIncrease( int money );
		void CountLoseIncrease( int money );
		int CountTotalPlays() const;
		int CountWin() const;
		int CountLose() const;
		int CountMoneyWin() const;
		int CountMoneyLose() const;

	private:
		int totalPlays;
		int countWin;
		int countLose;
		int countMoneyWin;
		int countMoneyLose;
};



#endif