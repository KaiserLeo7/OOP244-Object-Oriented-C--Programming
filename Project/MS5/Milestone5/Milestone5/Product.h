//
// Milestone 3
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/23/19
//

#ifndef _244_PRODUCT_H
#define _244_PRODUCT_H

#include "ErrorState.h"
#include "iProduct.h"

using namespace std;
namespace ama {

	class Product : public iProduct {
		
		const char prodType;
		char prodSKU[max_length_sku + 1];
		char prodUnit[max_length_unit + 1];
		char* prodNameAddrs;
		int prodAvailable;
		int prodNeeded;
		double prodPreTax;
		bool canTaxMaybe;
		ErrorState erroStatus;

		char taxYorN;
		
	protected:

		void message(const char* pText);

		bool isClear() const;

	public: 

		Product(const char type = 'N');

		Product(const char* sku, const char* name, const char* unit, double preTaxPrice = 0,
				int prodNeed = 0, int prodHave = 0, bool taxStatus = true);

		Product(const Product& other);

		~Product();

		Product& operator=(const Product & other);

		int operator+=(int cnt);

		bool operator==(const char* sku) const;

		bool operator> (const char* sku) const;

		bool operator> (const iProduct&) const;

		int qtyAvailable() const;

		int qtyNeeded() const;

		const char* name() const;

		double total_cost() const;

		bool isEmpty() const;

		std::istream& read(std::istream& in, bool interractive);

		std::ostream& write(std::ostream& out, int writeMode) const;
	};



}

#endif