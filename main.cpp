/**
 * Name: main.cpp
 * Developer: Jude McParland
 * Date: 11-13-18
 * Email: judem6968@student.vvc.edu
 * Description: A simple program that prints the transaction log for input transactions. This main file handles passing the transactions.
**/

#include <vector>
#include <iostream>
#include <string>
#include "trans.h"
#include "translog.h"

int main()
{
	Translog tlog;

	tlog.add_trans(Trans(1,1143.23,"Inital Balance"));	
	tlog.add_trans(Trans(10,234.56,"Check 2245"));
	tlog.add_trans(Trans(12,1023.56,"Black Market Money"));
	tlog.add_trans(Trans(14,-56.3,"Red Dead Redemption 2 - Xbox Live"));
	tlog.add_trans(Trans(17,-23.56,"Lotion & Klenex"));
	tlog.add_trans(Trans(19,-134.56,"Electric Bill"));
	tlog.add_trans(Trans(19,34.56,"Test"));
	tlog.add_trans(Trans(20,-500.00,"Rent"));
	tlog.add_trans(Trans(25,123.54,"Gift Received"));

	tlog.print();

	return 0;
}
