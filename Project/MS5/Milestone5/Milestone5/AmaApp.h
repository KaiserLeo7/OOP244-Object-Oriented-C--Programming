//
// Milestone 5
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 4/1/19


#ifndef _244_AMAAPP_H_
#define _244_AMAAPP_H_

#include <iostream>
#include "iProduct.h"
#include "Date.h"

namespace ama {

	class AmaApp {

		char m_filename[256];

		iProduct* m_products[100];

		int m_noOfProducts;

	public:

		AmaApp(const char* fileName);

		virtual ~AmaApp();

		int run();

	private:

		void pause() const;

		int menu() const;

		void loadProductRecords();

		void saveProductRecords() const;

		void listProducts() const;

		iProduct* find(const char* sku) const;

		void addQty(iProduct* product);

		void addProduct(char tag);

	};
}
#endif