//
// Milestone 5
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 4/1/19

#include <iostream>
#include "Date.h"
#include "Product.h"
#include "Perishable.h"

using namespace std;
namespace ama {

	Perishable::Perishable() : Product('P') {


	}

	std::ostream& Perishable::write(std::ostream& out, int writeMode) const {

		Product::write(out, writeMode);

		if (!isClear() || isEmpty()) {
		
			return out;
		}
		else { 
			
			if (writeMode == write_condensed) {
			
				out << ',' << expiry;
				
				return out;
			}
			else if (writeMode == write_table) {
				
				cout << " ";
				out << expiry;
				out << " |";

				return out;
			}
			else {
			
				out.setf(ios::right);
				out.width(max_length_label);
				out << "Expiry Date: ";
				out << expiry << endl;
			
				return out;
			}
		
		}


	}

	std::istream& Perishable::read(std::istream& in, bool interractive) {

		Date tempExpiry = Date();
		Product::read(in, interractive);

		if (interractive == true) {

			cout.setf(ios::right);
			cout.width(max_length_label);
			cout << "Expiry date (YYYY/MM/DD): ";
			in >> tempExpiry;


			if (tempExpiry.status() == error_input) {

				in.setstate(ios::failbit);
				message("Invalid Date Entry");
			}
			else if (tempExpiry.status() == error_year) {

				in.setstate(ios::failbit);
				message("Invalid Year in Date Entry");
			}
			else if (tempExpiry.status() == error_mon) {

				in.setstate(ios::failbit);
				message("Invalid Month in Date Entry");
			}
			else if (tempExpiry.status() == error_day) {

				in.setstate(ios::failbit);
				message("Invalid Day in Date Entry");
			}

			if (!in.fail()) {

				expiry = tempExpiry;
			}
		
		} else if (interractive == false){
			
			in.ignore();
			expiry.read(in);
		}
		return in;
	}
}