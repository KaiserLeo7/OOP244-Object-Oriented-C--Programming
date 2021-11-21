//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/22/19
//

#include "SavingsAccount.h"

namespace sict {

	const double interest = 0.05;

	iAccount* CreateAccount(const char* type, double balance) {

		iAccount *newAcc = nullptr;

		if (type[0] == 'S') {
			newAcc = new SavingsAccount(balance, interest);
		}
		return newAcc;
	}
}