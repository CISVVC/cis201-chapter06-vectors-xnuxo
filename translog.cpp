/**
 * Name: translog.cpp
 * Developer: Jude McParland
 * Date: 11-13-18
 * Email: judem6968@student.vvc.edu
 * Description: Implementation of Translog Class to handle printing log and calculation of balances. 
 * This takes the passed construct Trans() from main.cpp in the add_trans().
**/

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "trans.h"
#include "translog.h"

void Translog::add_trans(const Trans &t)

{
	m_trans.push_back(t);
}

void Translog::add_to_log() //See header file for overview of this mem func
{
	for(int i=0;i<m_trans.size();i++)	
		{		
			if(m_trans[i].getday() < DAYS_OF_MON) 
				{
					int log = m_trans[i].getday();
					
		 			// Use a test to see if t_log has a no stored transaction. Else concatenate onto the already stored values.		
					
					if(t_log[log].empty())
						{ 
							t_log[log] = m_trans[i].to_string(); //Send passed Trans() to t_log
							dt_log[log] = m_trans[i].getam(); // Send passed Trans() Amount to dt_log
						}
					else
						{
							t_log[log] = t_log[log] + "\n" + m_trans[i].to_string();
							dt_log[log] = dt_log[log] + m_trans[i].getam();
			   			}	
				}
		}
}

//############# Totals Calculation Begin

//This func is "loaded" but it does calculate the "totals" required so I just stored it in one for calling simplicity. 
//Calculates DailyTotal and tests for lowest Daily Total (Daily Minimum) and assists in Avg Daily Total Calculation.

double Translog::run_total(int t) 
{
		if(!t_log[t].empty()) 
			dailyavg(t);
		
		if(dtotal < dt_log[t] && dtotal != 0) //Checks if the bal is the min. If so set it to Daily Min (dmin). 
			{	
				dmin = dt_log[t];
				dtotal += dt_log[t];
			}
		else
				dtotal += dt_log[t]; //Updates Daily Total (dtotal).

	return dtotal;
}

void Translog::dailyavg(int t) 
{
	int daysbetween;
	int lastbal;
	for(int i = t-1 ;i>0; i--) //Goes down days til it reaches last transaction day.
		{
			if(!t_log[i].empty())
				{	
					lastbal = i;
					break;
				}
		}
	daysbetween = t - lastbal;						
	dbal = dbal + (dtotal * daysbetween); // Bal x Days w/ same Bal = # / 30.
}

//############# Printing Begin 

void Translog::print_totals()
{
	// Formula (Days Of Mon - Last Transaction Day * Final Bal + sum of other avg balances) / Days of Month = DAB = Daily Average Bal.
	double avgdb = (dbal + ((DAYS_OF_MON - m_trans[m_trans.size()-1].getday()) * dtotal)) / DAYS_OF_MON;

	std::cout << std::setfill(' ') << std::setw(10) << "Average Balance is: " << avgdb; 
	std::cout << std::fixed << std::setprecision(2) << std::setfill(' ') << std::setw(10);
	std::cout << "          Interest: " << (.05 / 12) * avgdb << std::endl;
	
	std::cout << "Minimum Daily Balance was: " << dmin; 
	std::cout << std::fixed << std::setprecision(2) << std::setfill(' ') << std::setw(10)
		      << "   Interest: " << (.05 / 12) * dmin << std::endl << std::endl;
}

void Translog::print()
{
	add_to_log();

	for(int l=1;l<t_log.size();l++) // Runs through entire Translog (t_log) vector == #Days of Month
		{
			if(t_log[l].empty()) // If there is no stored transaction on that day print this:... (excuse formatting iomanip caused headaches).
				std::cout << "------------"<<"Day: " << l << " -----------" << std::endl 
						  << "No Activity" <<"     Total: "  << run_total(l) << std::endl
					      << "-------------------------------" << std::endl << std::endl;
			else
				{
					std::cout << "------------"<<" Day: " << l << " ----------" << std::endl 
						      << "Amount" << "    " << "Description" << std::endl << t_log[l] 
						      << std::endl << "-------------------------------" << std::endl
						      << "-----" << " New Total: " << run_total(l) << " ------" 
						      << std::endl << "-------------------------------" << std::endl << std::endl;
				}
		}	
	print_totals();	
}
