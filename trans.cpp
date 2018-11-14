/**
 * Name: trans.cpp
 * Developer: Jude McParlans
 * Email: judem6968@student.vvc.edu
 * Date: 11-13-18
 * Description: Implementation for Trans class that stores individual transactions that are input into the program.
**/
#include <vector>
#include <iostream>
#include <string>
#include<iomanip>
#include <sstream>
#include "trans.h"

Trans::Trans()
{
	day = 0;
	amount = 0.0;
	desc = "";
}

Trans::Trans(int _day, double _amount, std::string _desc)
{
	day = _day;
	amount = _amount;
	desc = _desc; 
}

int Trans::getday()
{
	return day;
}

double Trans::getam()
{
	return amount;
}

std::string Trans::to_string()
{
	//#### A Little String Stream Precision Fix - The 6 "0's" pissed me off.
		std::ostringstream strObj1;
		strObj1 << std::fixed << std::setprecision(2) << std::left << std::setfill(' ') << std::setw(10) << amount 
				<< std::setfill(' ') << std::setw(5); 
		std::string amount2 = strObj1.str();
	//####

	return amount2 + desc;
}
