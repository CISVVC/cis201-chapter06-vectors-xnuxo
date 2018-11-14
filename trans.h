/**
 * Name: trans.h
 * Developer: Jude McParland
 * Email: judem6968@student.vvc.edu
 * Date: 11-12-18
 * Description: Class thats allows the input of individual transactions with Day, Ammount, and Description of Transaction.
**/
#ifndef TRANS_H
#define TRANS_H

#include <vector>
#include <iostream>
#include <string>

const int DAYS_OF_MON = 30;

class Trans
{
	public:
		Trans();

		Trans(int _day, double _amount, std::string _desc);
		
		std::string to_string();
		int getday();
		double getam();

	private:
	int day;
	double amount;
	std::string desc;
};

#endif

