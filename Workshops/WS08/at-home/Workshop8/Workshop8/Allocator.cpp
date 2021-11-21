//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/22/19
//

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

	const double interest = 0.05;
	double transFee = 0.50;
	double monthlyFee = 2.00;

	iAccount* CreateAccount(const char* type, double balance) {

		iAccount *newAcc = nullptr;

		if (type[0] == 'S') {

			newAcc = new SavingsAccount(balance, interest);

		}
		else if (type[0] == 'C') {

			newAcc = new ChequingAccount(balance, transFee, monthlyFee);
		}
		else {
		
			return newAcc;
		}

		return newAcc;
	}
}