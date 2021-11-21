//
// Milestone 5
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 4/1/19

#include "Utilities.h"
#include "AmaApp.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;
namespace ama {
	
	//Default Constructor
	//Copy filename to m_filename
	//set ALL m_products to 0
	//LOAD the records from the file  ////// <-----
	AmaApp::AmaApp(const char* fileName) {

		strcpy(m_filename, fileName);

		m_products[0] = nullptr;

		m_noOfProducts = 0;

		loadProductRecords();
	}

	//Deallocate all dynamic instances in m_products array
	AmaApp::~AmaApp() {

		//loop through array
		//delete all instances
		for (int i = 0; i < m_noOfProducts; i++)
		{
			delete m_products[i];

			m_products[i] = nullptr;
		}
		
	}

	//Print
	//wait for "Enter"
	//ignore all alse
	void AmaApp::pause() const {

		cout << "Press Enter to continue..." << endl;
		std::cin.ignore(1000000, '\n');
		getchar();
	}

	int AmaApp::menu() const {

		int input;

		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1- List products" << endl;
		cout << "2- Search product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to product quantity" << endl;
		cout << "6- Delete product" << endl;
		cout << "7- Sort products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";

		cin >> input;

		//if not within selection return -1
		if (input >= 0 && input <= 7) {
		
			return input;
		}
		else {
			
			return -1;
		}
	}

	void AmaApp::loadProductRecords() {
		//set read index to 0
		int index = 0;
		char tag;
		
		//delete all products from array
		if (m_noOfProducts) {

			for (int i = 0; i < m_noOfProducts; i++) {

				delete  m_products[i];
				m_products[i] = nullptr;
			}
		}

		//open file for reading
		ifstream inFile(m_filename);

		while (inFile) {
			
			if (inFile.is_open()) {
		
				//read one char to get tag
				tag = inFile.get();
			
				//read until NULL
				if (createInstance(tag) != NULL) {
			
					//call createInstance(tag) to create an instance
					m_products[index] = createInstance(tag);
					
					//skip the comma from the file
					inFile.ignore();

					//store the product in the array at the read index
					m_products[index]->read(inFile, false);

					//increment loop
					index++;
				}
			}

			//set number of products to index
			m_noOfProducts = index;
		}

		//close file
		inFile.close();
	}

	void AmaApp::saveProductRecords() const {

		//open file
		ofstream inFileSave;

		inFileSave.open(m_filename);

		//loop through the m-products array up to m_noOfProducts
		for (int i = 0; i < m_noOfProducts; i++) {
		
			//store each of them in a file
			m_products[i]->write(inFileSave, write_condensed);
		
			//each record has end line
			inFileSave << endl;
		}
		//close file
		inFileSave.close();
	}

	void AmaApp::listProducts() const {
		
		double total = 0;

		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

		//loops through the m_products array up to m_noOfProducts
		for (int i = 0; i < m_noOfProducts; i++) {

			cout.setf(ios::right);
			cout << '|';
			cout.width(4);
			cout << i + 1;
			cout << " |";
			cout.unsetf(ios::right);

			// insert the content of the current product using write_table
			m_products[i]->write(cout, write_table);

			total += *m_products[i];
			cout << '\n';
		}

		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                      Total cost of support ($): | ";
		cout.width(10);
		cout.precision(2);
		cout.setf(ios::right);
		cout.setf(ios::fixed);
		cout << total;
		cout << " |" << endl;
		cout.unsetf(ios::right);
		cout.unsetf(ios::fixed);
		cout << "------------------------------------------------------------------------------------------------\n" << endl;
	}


	iProduct* AmaApp::find(const char* sku) const {

		//loops through m_products array up to m_noOfProducts
		for (int i = 0; i < m_noOfProducts; i++) {

			//if index matches sku return it
			if (*m_products[i] == sku) {
			
				return m_products[i];
			}
		}

		//else return null
		return nullptr;
	}

	void AmaApp::addQty(iProduct* product) {

		int number;
		int required;
		int extra;

		//display in human readable form
		product->write(cout, write_human);
		cout << endl;
		cout << endl;
		cout << "Please enter the number of purchased items: ";
		
		//read integer
		cin >> number;
		if (cin.fail()) {
		
			//if fail reading
			cout << "Invalid quantity value!" << endl;
			cin.clear();
		}
		else {
		
			//if read successful get amount required
			required = (product->qtyNeeded() - product->qtyAvailable());
			
			if (number <= required) {
			
				product->operator+=(number);

				//save all records
				saveProductRecords();
				cout << endl;
				cout << "Updated!" << endl;
			}
			else {
			
				//get extra by subtracting what you need from what you got
				extra = number - required;

				cout << "Too many items; only ";
				cout << required;
				cout << " is needed. Please return the extra ";
				cout << extra;
				cout << " items." << endl;

				//what you got - extra = what you will keep
				product->operator+=(number - extra);

				//save all records
				saveProductRecords();
				cout << endl;
				cout << "Updated!" << endl;
				cin.clear();
			}
		
		}

	}

	void AmaApp::addProduct(char tag) {

		//make temp instance
		iProduct* tempProd = nullptr;
		tempProd = createInstance(tag);

		//if successfully created
		if (tempProd != nullptr) {
		
			// initialize the product’s attributes
			cin >> *tempProd;

			if (cin.fail()) {

				cout << endl;
				cout << *tempProd << endl;
				cout << endl;

				//if fail clear error
				cin.clear();
			}
			else {
			
				// add the product at the end of the array
				m_products[m_noOfProducts] = tempProd;
				m_noOfProducts++;

				//call saveProductRecords
				saveProductRecords();
				cout << endl;
				cout << "Success!" << endl;
				cout << endl;
			}
		}
	}

	int AmaApp::run() {

		int selection = 0;
		
		do {
			//run menu assign it to selector
			selection = menu();
			
			switch (selection) {

				//list the products
			case 1:

				listProducts();
				pause();
				break;

				//Display product by sku
			case 2:

				char sku[max_length_sku];

				cout << "Please enter the product SKU: ";

				cin >> sku;
				cout << endl;

				if (find(sku) != nullptr) {

					//display the product in human readable form
					find(sku)->write(cout, write_human);
					cout << endl;
				}
				else {
						
					cout << "No such product!" << endl;
				}
					
				pause();
				break;

				//Add non-perishable product
			case 3:

				addProduct('N');
				loadProductRecords();

				//ignore so that program doesnt return 0 and close
				std::cin.ignore(1000000, '\n');
				break;

				//Add perishable product
			case 4:

				addProduct('P');
				loadProductRecords();

				//ignore so that program doesnt return 0 and close
				std::cin.ignore(1000000, '\n');
				break;

				//Add to quantity of purchased products
			case 5:
				cout << "Please enter the product SKU: ";
				cin >> sku;
				cout << '\n';

				//search for the product
				if (find(sku) != nullptr) {

					//call addQty() to add quantity
					addQty(find(sku));
				}
				else {

					cout << "No such product!" << endl;
				}
				cout << '\n';

				//ignore so that program doesnt return 0 and close
				std::cin.ignore(1000000, '\n');
				break;

			case 6: cout << "Coming in V1.2" << endl;

				pause();
				break;

			case 7: cout << "Coming in V1.2" << endl;

				pause();
				break;

			case 0: 
				cout << "Goodbye!" << endl;
				break;

			default:	
				
				//invalid menu selection				
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();
				break;

			}
			
		} while (selection);

		return 0;
	}
}