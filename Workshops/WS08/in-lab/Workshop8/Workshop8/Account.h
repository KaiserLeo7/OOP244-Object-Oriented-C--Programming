//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/22/19
//

#ifndef _244_ACCOUNT_H
#define _244_ACCOUNT_H

#include "iAccount.h"

namespace sict {

	class Account : public iAccount {

		double balCurrent;

	public:

		Account(double balance);

		bool credit(double amountAdded);

		bool debit(double amountSubed);

	protected: 
		
		double balance() const;
	};
}
#endif