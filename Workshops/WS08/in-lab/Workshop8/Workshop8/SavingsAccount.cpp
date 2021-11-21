//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/22/19
//

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account( balance ) {

		if (interestRate > 0) {
			
			intCurrent = interestRate;
		}
		else {

			intCurrent = 0.0;
		} 
	}

	void SavingsAccount::monthEnd()	{

		double intEarned = (balance() * intCurrent);

		credit(intEarned);
	}

	void SavingsAccount::display(std::ostream& out) const {

		out << "Account type: Savings" << endl;
		out.precision(2);
		out.setf(ios::fixed,ios::floatfield);
		out << "Balance: $" << balance() << endl;
		out << "Interest Rate (%): " << intCurrent * 100 << endl;
	}
}