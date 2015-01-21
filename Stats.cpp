#include "Stats.h"
#include "Display.h"
#include <iostream>
#include <iomanip>
#include <fstream>



Stats::Stats()
{
}



Stats::~Stats()
{
}



unsigned int Stats::Size() const
{
	return size;
}



void Stats::Print() const
{
	Display::Clear();

	std::cout << "_____________________________________ " << "Statistics" << " _____________________________________" << std::endl << std::endl;
	
	std::cout << "|" << std::setw( 20 ) << "Name" << " |" << std::setw( 10 ) << "Wins" << " |" << std::setw( 10 ) << "Fails" << " |" 
			  << std::setw( 12 ) << "Total plays" << " |" << std::setw( 10 ) << "Money win" << " |" << std::setw( 11 ) 
			  << "Money lose" << " |" << std::endl;
	
	std::cout << "|" << std::setw( 20 ) << "" << " |" << std::setw( 10 ) << "" << " |" << std::setw( 10 ) << "" << " |"
			  << std::setw( 12 ) << "" <<  " |" << std::setw( 10 ) << "" << " |" << std::setw( 11 ) << "" << " |" << std::endl;
	
	for ( unsigned int i = 0; i < size; i++ )
	{
		std::cout << "|" << std::setw( 20 ) << names[i] << " |" << std::setw( 10 ) << wins[i] << " |" 
				  << std::setw( 10 ) << fails[i] << " |" << std::setw( 12 ) << totalPlays[i] << " |" 
				  << std::setw( 10 ) << moneyWin[i] << " |" << std::setw( 11 ) << moneyLose[i] << " |" << std::endl;
	}

	std::cout << "______________________________________________________________________________________" << std::endl << std::endl;
}



void Stats::Add( const std::string& name, const StatsCount& statsCount )
{
	int index = Search( name );
	if ( index == -1 )
	{
		names.push_back( name );
		wins.push_back( statsCount.CountWin() );
		fails.push_back( statsCount.CountLose() );
		totalPlays.push_back( statsCount.CountTotalPlays() );
		moneyWin.push_back( statsCount.CountMoneyWin() );
		moneyLose.push_back( statsCount.CountMoneyLose() );
		size++;
	}
	else
	{
		wins[index] = statsCount.CountWin();
		fails[index] = statsCount.CountLose();
		totalPlays[index] = statsCount.CountTotalPlays();
		moneyWin[index] = statsCount.CountMoneyWin();
		moneyLose[index] = statsCount.CountMoneyLose();
	}
}



void Stats::ReadFromFile()
{
	std::ifstream inputFile( filename );
	if ( inputFile.is_open() && !EmptyFile() )
	{
		inputFile >> size;
		names.resize( size );
		wins.resize( size );
		fails.resize( size );
		totalPlays.resize( size );
		moneyWin.resize( size );
		moneyLose.resize( size );
		for ( unsigned int i = 0; i < size; i++ )
		{
			inputFile >> names[i];
			inputFile >> wins[i];
			inputFile >> fails[i];
			inputFile >> totalPlays[i];
			inputFile >> moneyWin[i];
			inputFile >> moneyLose[i];
		}
	}
	else
	{
		size = 0;
	}
	inputFile.close();
}



void Stats::SaveToFile() const
{
	std::ofstream outputFile( filename );
	outputFile << size << std::endl;

	for ( unsigned int i = 0; i < size; i++ )
	{
		outputFile << names[i] << std::endl;
		outputFile << wins[i] << std::endl;
		outputFile << fails[i] << std::endl;
		outputFile << totalPlays[i] << std::endl;
		outputFile << moneyWin[i] << std::endl;
		outputFile << moneyLose[i] << std::endl;
	}

	outputFile.close();
}



bool Stats::EmptyFile() const
{
	long fileSize;
	std::fstream file( filename );
	file.seekg( 0, std::ios::end );
	fileSize = file.tellg();
	return ( fileSize == 0 ); 
}



int Stats::Search( const std::string& name )
{
	int index = -1;
	for ( unsigned int i = 0; i < size; i++ )
	{
		if ( name == names[i] )
		{
			index = i;
		}
	}
	return index;
}