/**
 * Name: translog.h
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Date: 11-13-18
 * Description: A Class thats takes input Trans() statements and prints a log of them and calculates the Daily Average Bal and Min Dail Bal.
**/
#ifndef TRANSLOG_H
#define TRANSLOG_H

#include <vector>
#include <iostream>
#include <string>
#include "trans.h"

class Translog
{
		std::vector<Trans> m_trans;
		std::vector<std::string>t_log = std::vector<std::string>(DAYS_OF_MON + 1); // This prints out a report of 30 day TransLog. 1 is added so it prints 30 on the log and doesnt segfault.
		std::vector<double>dt_log = std::vector<double>(30); //This assigns totals to days for calculation. DailyTotallog
	public:
		
		void add_trans(const Trans &t); // Passes the entire info in Construct to m_trans
		void add_to_log(); //Assigns m_trans to t_log and dt_log respectivley.
		
		double run_total(int t);
		void dailyavg(int t);
		
		void print_totals();
		void print();

	private:
		double dtotal; 
		double dmin;
		double dbal = 0.0;
};

#endif
