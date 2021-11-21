//
// Milestone 3
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/23/19
//

#ifndef _244_UTILITIES_H
#define _244_UTILITIES_H

#include <iostream>
#include "Product.h"

using namespace std;
namespace ama {

	double& operator+=(double& total, const Product& prod);

	ostream& operator<<(ostream& out, const Product& prod);

	istream& operator>>(istream& in, Product& prod);
}
#endif