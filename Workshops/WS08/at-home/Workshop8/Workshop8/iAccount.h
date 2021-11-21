//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/22/19
//

#ifndef _244_IACCOUNT_H
#define _244_IACCOUNT_H

#include <iostream>

namespace sict {

	class iAccount {

	public:

		virtual ~iAccount() {};

		virtual bool credit(double amount) = 0;

		virtual bool debit(double amount) = 0;
		
		virtual void monthEnd() = 0;

		virtual void display(std::ostream& out) const = 0;
	};

	iAccount* CreateAccount(const char* type, double interest);
}
#endif