//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/22/19
//

#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {

	Account::Account(double balance) {
	
		if (balance > 0) {
			balCurrent = balance;
		}
		else {
			balCurrent = 0;
		}
	}

	bool Account::credit(double amountAdded) {
		
		if (amountAdded > 0) {
			
			balCurrent += amountAdded;
			return true;
		}
		else { return false; }
	}

	bool Account::debit(double amountSubed)
	{
		if (amountSubed > 0 && amountSubed < balCurrent) {
		
			balCurrent -= amountSubed;
			return true;
		}
		else { return false; }
	}

	double Account::balance() const
	{
		return balCurrent;
	}

}
