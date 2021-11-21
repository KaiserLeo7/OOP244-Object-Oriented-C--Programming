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

	double& operator+=(double& total, const Product& prod) {
		
		total += prod.total_cost();
		return total;
	}

	ostream& operator<<(ostream& out, const Product& prod) {
	
		prod.write(out, 2);
		return out;
	}

	istream& operator>>(istream& in, Product& prod) {
	
		prod.read(in, true);
		return in;
	}

}