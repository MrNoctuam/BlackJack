#ifndef STATS_H
#define STATS_H

#include "StatsCount.h"
#include <string>
#include <vector>
#include <fstream>



class Stats {
	public:
		Stats();
		virtual ~Stats();
		unsigned int Size() const;
		std::string Names( unsigned int index ) const;
		int MoneyWin( unsigned int index ) const;
		int MoneyLose( unsigned int index ) const;
		int Wins( unsigned int index ) const;
		int Fails( unsigned int index ) const;

		void Print() const;
		void Add( const std::string& name, const StatsCount& statsCount );
		void ReadFromFile();
		void SaveToFile() const;
		
	public:
		const std::string filename = "stats";
		unsigned int size;
		std::vector<std::string> names;
		std::vector<int> moneyWin;
		std::vector<int> moneyLose;
		std::vector<int> wins;
		std::vector<int> fails;
		std::vector<int> totalPlays;

		bool EmptyFile() const;
		// returns index or -1 if not found
		int Search( const std::string& name );
};



#endif