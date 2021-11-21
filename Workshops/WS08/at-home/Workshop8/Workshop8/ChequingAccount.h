//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/26/19
//

#ifndef _244_CHEQUINGACCOUNT_H
#define _244_CHEQUINGACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {

		double transactionFee;
		double Monthly;
	public:
	
		ChequingAccount(double balance, double transFee, double monthlyFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream& out) const;
	};
}
#endif