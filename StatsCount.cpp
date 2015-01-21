#include "StatsCount.h"



StatsCount::StatsCount() : countWin( 0 ), countLose( 0 ), totalPlays( 0 ), countMoneyWin( 0 ), countMoneyLose( 0 )
{
}



StatsCount::~StatsCount()
{
}




void StatsCount::Reset()
{
	countWin = 0;
	countLose = 0;
	totalPlays = 0;
	countMoneyWin = 0;
	countMoneyLose = 0;
}



void StatsCount::CountTotalPlaysIncrease()
{
	totalPlays++;
}



void StatsCount::CountWinIncrease( int money )
{
	countWin++;
	countMoneyWin += money;
}



void StatsCount::CountLoseIncrease( int money )
{
	countLose++;
	countMoneyLose += money;
}



int StatsCount::CountTotalPlays() const
{
	return totalPlays;
}



int StatsCount::CountWin() const
{
	return countWin;
}



int StatsCount::CountLose() const
{
	return countLose;
}



int StatsCount::CountMoneyWin() const
{
	return countMoneyWin;
}



int StatsCount::CountMoneyLose() const
{
	return countMoneyLose;
}