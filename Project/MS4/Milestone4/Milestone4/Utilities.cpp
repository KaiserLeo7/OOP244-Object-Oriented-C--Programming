//
// Milestone 3
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/23/19
//

#include <iostream>
#include "Product.h"
#include "Utilities.h"

using namespace std;
namespace ama {

	double& operator+=(double& total, const iProduct& prod) {
		
		total += prod.total_cost();
		return total;
	}

	ostream& operator<<(ostream& out, const iProduct& prod) {
	
		prod.write(out, 2);
		return out;
	}

	istream& operator>>(istream& in, iProduct& prod) {
	
		prod.read(in, true);
		return in;
	}

	iProduct* createInstance(char tag) {

		if (tag == 'n' || tag == 'N') {

			iProduct* product = new Product;

			return product;

		} else
		
		{ 
			return nullptr;
		}

		
	}
}