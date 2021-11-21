//
// Milestone 3
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/23/19
//

#include <iostream>
#include <string>
#include <cstring>
#include "Product.h"
#include "ErrorState.h"

using namespace std;
using namespace ama;

namespace ama {

	void Product::message(const char* pText) {
	
		erroStatus.message(pText);
	}

	bool Product::isClear() const {
		
		bool temp = false;
		if (erroStatus.message() == nullptr || strcmp(erroStatus.message(), "no_error") == 0) {
			
			temp = true;
		}

		return temp;
	}

	Product::Product(const char type):prodType(type) {
		
		prodNameAddrs = nullptr;
		prodSKU[0] = '\0';
		prodUnit[0] = '\0';
		prodPreTax = 0.0;
		canTaxMaybe = false;
		prodAvailable = 0;
		prodNeeded = 0;
		
	}

	Product::Product(const char* sku, const char* name, const char* unit,
		double preTaxPrice, int prodNeed, int prodHave, bool taxStatus):prodType('N') {
	
		if (name != nullptr && strlen(name) <= max_length_name) {

			if (name != nullptr) {
						
				int length = strlen(name) + 1;

				prodNameAddrs = new char[length];
				strcpy(prodNameAddrs, name);

				prodNameAddrs[length] = '\0';
			}

			strncpy(prodSKU, sku, max_length_sku);
			strncpy(prodUnit, unit, max_length_unit);
			
			prodAvailable = prodHave;
			prodNeeded = prodNeed;
			prodPreTax = preTaxPrice;
			canTaxMaybe = taxStatus;
		}
		else {
		
			*this = Product();
		}
	}

	Product::Product(const Product& other):prodType('N') {
	
		if (other.prodNameAddrs != nullptr) {

			prodNameAddrs = nullptr;

			*this = other;
		}
	}

	Product::~Product() {

		prodNameAddrs = nullptr;
		delete[] prodNameAddrs;
	}
	
	Product& Product::operator=(const Product& other) {
	
		if (this != &other) {

			if (other.prodNameAddrs != nullptr) {

				int length = strlen(other.prodNameAddrs);

				prodNameAddrs = nullptr;
				prodNameAddrs = new char[length + 1];

				strcpy(prodNameAddrs, other.prodNameAddrs);
			}
			else {

				prodNameAddrs = nullptr;
			}

			strncpy(prodSKU, other.prodSKU, max_length_sku);
			strncpy(prodUnit, other.prodUnit, max_length_unit);

			prodAvailable = other.prodAvailable;
			prodNeeded = other.prodNeeded;
			prodPreTax = other.prodPreTax;
			canTaxMaybe = other.canTaxMaybe;

		}

		return *this;
	}

	int Product::operator+=(int cnt) {
	
		if (cnt > 0) {
		
			prodAvailable += cnt;
		}
		return prodAvailable;
	}

	bool Product::operator==(const char* sku) const {
	
		return strcmp(prodSKU, sku) == 0;
	}

	bool Product::operator> (const char* sku) const {
	
		return (strcmp(prodSKU, sku) > 0) ? true : false;
	}

	bool Product::operator> (const iProduct& s) const {
	
		return (strcmp(prodNameAddrs, s.name()) > 0) ? true : false;
	}

	int Product::qtyAvailable() const {
	
		return prodAvailable;
	}

	int Product::qtyNeeded() const {
	
		return prodNeeded;
	}

	const char* Product::name() const {
	
		return prodNameAddrs;
	}

	double Product::total_cost() const {
	
		double taxOnProd = 0;
		double total = 0;
		
		if (canTaxMaybe == true) {

			taxOnProd = (prodPreTax * tax_rate);
		}

		total = taxOnProd + prodPreTax;
		 
		return  (prodAvailable * total);
	}

	bool Product::isEmpty() const {
	
		return (prodNameAddrs == nullptr) ? true : false;
	}

	std::istream& Product::read(std::istream& in, bool interractive) {
	

		if (interractive == false) {
		
			in.getline(prodSKU, max_length_sku, ',');

			prodNameAddrs = new char[max_length_name];
			in.getline(prodNameAddrs, max_length_name, ',');
		
			in.getline(prodUnit, max_length_unit, ',');

			in >> prodPreTax;
			in.ignore();
			in >> canTaxMaybe;
			in.ignore();
			in >> prodAvailable;
			in.ignore();
			in >> prodNeeded;
			return in;

		}
		
			cout.setf(ios::right);
			cout.width(max_length_label);
			cout << "Sku: ";
			in >> prodSKU;

			cout.width(max_length_label);
			cout << "Name (no spaces): ";
			prodNameAddrs = new char[max_length_name];
			in >> prodNameAddrs;

			cout.width(max_length_label);
			cout << "Unit: ";
			in >> prodUnit;

			cout.width(max_length_label);
			cout << "Taxed? (y/n): ";
			in >> taxYorN;

			if (taxYorN == 'Y' || taxYorN == 'y') {

				canTaxMaybe = true;
			}
			else if (taxYorN == 'N' || taxYorN == 'n') {

				canTaxMaybe = false;
			}
			else {

				in.setstate(ios::failbit);
				erroStatus.message("Only (Y)es or (N)o are acceptable!");
				return in;
			

			if (!in.fail()) {
				cout.width(max_length_label);
				cout << "Quantity on hand: ";
				in >> prodAvailable;

				if (in.fail()) {

					in.setstate(ios::failbit);
					erroStatus.message("Invalid Quantity Available Entry!");
				}
			}

			if (!in.fail()) {

				cout.width(max_length_label);
				cout << "Quantity needed: ";
				in >> prodNeeded;}
			
			if (!in.fail()) {
				cout.width(max_length_label);
				cout << "Price: ";
				in >> prodPreTax;

				if (in.fail()) {

					in.setstate(ios::failbit);
					erroStatus.message("Invalid Price Entry!");
				}
			}

				if (in.fail()) {

					in.setstate(ios::failbit);
					erroStatus.message("Invalid Quantity Needed Entry!");
				}
			}
			
		return in;
	}

	std::ostream& Product::write(std::ostream& out, int writeMode) const {
	
		if (erroStatus.message() != nullptr) {

			out << erroStatus.message();
			return out;
		}
		else if (isEmpty() == true) {
		
			return out;
		}
	
		if (writeMode == write_condensed) {
		
			out << prodType << ',' << prodSKU << ',' << prodNameAddrs << ',' << prodUnit << ',' << prodPreTax
				<< ',' << canTaxMaybe << ',' << prodAvailable << ',' << prodNeeded;
			
			return out;
		}
		else if (writeMode == write_table) {
		
			cout << " ";
			out.width(max_length_sku);
			out.setf(ios::right);
			out << prodSKU;
			out.unsetf(ios::right);
			///////////////////////////
			out << " | ";
			out.setf(ios::left);
			
			if (strlen(prodNameAddrs) > 16) {

				for (int i = 0; i < 13; i++) {

					out << prodNameAddrs[i];
				}
				cout << "...";

			} else {
				out.width(16);
				out << prodNameAddrs;
			}
			///////////////////////////////////
			out << " | ";
			out.width(10);
			out.setf(ios::left);
			out << prodUnit;
			out.unsetf(ios::left);
			//////////////////////////////////
			out << " | ";
			out.width(7);
			out.setf(ios::right);
			out.setf(ios::fixed);
			out.precision(2);
			out << prodPreTax;
			////////////////////////////////
			out << " | ";
			out.width(3);
			out.setf(ios::right);
			if (canTaxMaybe == true) {
			
				out << "yes" << " | ";
			}
			else {
			
				out << "no" << " | ";
			}
			out.unsetf(ios::right);

			////////////////////////////////
			out.width(6);
			out.setf(ios::right);
			out << prodAvailable;
			out << " | ";

			/////////////////////////////
			out.width(6);
			out << prodNeeded;
			out << " |";
			out.unsetf(ios::right);
		}
		else {
		
			out.setf(ios::right);
			out.setf(ios::fixed);
			out.precision(2);
			out.width(max_length_label);
			out << "Sku: ";
			out << prodSKU << endl;

			//////////////////////////
			out.width(max_length_label);
			out << "Name: ";
			out << prodNameAddrs << endl;

			///////////////////////////
			out.width(max_length_label);
			out << "Price: ";
			out << prodPreTax << endl;

			///////////////////////////
			if (canTaxMaybe == true) {

				out.width(max_length_label);
				out << "Price after Tax: ";
				out << (prodPreTax + (prodPreTax * tax_rate)) << endl;
			}
			else if (canTaxMaybe == false) {
			
				out.width(max_length_label);
				out << "Price after Tax: ";
				out << prodPreTax << endl;
			}
			
			//////////////////////////
			out.width(max_length_label);
			out << "Quantity Available: ";
			out << prodAvailable;
			out << " ";
			out << prodUnit << endl;

			///////////////////////////
			out.width(max_length_label);
			out << "Quantity Needed: ";
			out << prodNeeded;
			out << " ";
			out << prodUnit << endl;
			out.unsetf(ios::right);

		}
		return out;
	}
}