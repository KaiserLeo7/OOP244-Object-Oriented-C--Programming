//
// Milestone 5
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 4/1/19

#ifndef _244_PERISHABLE_H_
#define _244_PERISHABLE_H_

#include <iostream>
#include "Product.h"
#include "Date.h"

namespace ama {

	class Perishable : public Product {

		Date expiry;


	public:

		Perishable();
		
		std::ostream& write(std::ostream& out, int writeMode) const;

		std::istream& read(std::istream& in, bool interractive);

	};
}
#endif