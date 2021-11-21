//
// Workshop 8
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/26/19
//


#include <iostream>
#include "ChequingAccount.h"

using namespace std;
namespace sict {

	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account(balance) {
		
		if (transFee > 0) {
		
			transactionFee = transFee;
		} else {

			transactionFee = 0.0;
		}

		if (monthlyFee > 0) {
			
			Monthly = monthlyFee;
		} else {
			
			monthlyFee = 0.0;
		}
	}

	bool ChequingAccount::credit(double amount) {

		if (Account::credit(amount) == true) {

			Account::debit(transactionFee);

			return true;
		} else {
			
			return false;
		}
	}

	bool ChequingAccount::debit(double amount) {

		if (Account::debit(amount) == true) {

			Account::debit(transactionFee);

			return true;
		} else {

			return false;
		}
	}

	void ChequingAccount::monthEnd() {

		Account::debit(Monthly);
	}

	void ChequingAccount::display(std::ostream& out) const
	{
		out << "Account type: Chequing" << endl;
		out << "Balance: $";

		out.setf(ios::fixed);
		out.precision(2);
		out << balance() << endl;
		out.unsetf(ios::fixed);

		out << "Per Transaction Fee: ";

		out.setf(ios::fixed);
		out.precision(2);
		out << transactionFee << endl;
		out.unsetf(ios::fixed);

		out << "Monthly Fee: ";

		out.setf(ios::fixed);
		out.precision(2);
		out << Monthly << endl;
		out.unsetf(ios::fixed);
	}
}

