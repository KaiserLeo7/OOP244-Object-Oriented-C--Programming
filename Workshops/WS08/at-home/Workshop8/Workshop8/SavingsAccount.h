//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/22/19
//

#ifndef _244_SAVINGSACCOUNT_H
#define _244_SAVINGSACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {

	class SavingsAccount : public Account {

		double intCurrent;

	public:

		SavingsAccount(double balance, double interestRate);

		void monthEnd();

		void display(std::ostream& out) const;

	};
}
#endif