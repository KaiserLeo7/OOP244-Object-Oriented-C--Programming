//
// Workshop 6
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/08/19
//

#include "Contact.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

namespace sict {

	Contact::Contact()
	{
		//Sets the current object to a safe empty state
		name[0] = '\0';
		phoneNumbers = nullptr;
		numOfPhoneNumbers = 0;

	}

	Contact::Contact(const char* newName, const long long* newPhoneNumbers, int newNumOfPhoneNumbers)
	{
		//Receives the new name of contact, new array of phone numbers, an the new number of phones
		
			//if incoming name isnt safe empty
		if (newName != nullptr && newName[0] != '\0') {

			//use max name length to copy/set name
			for (int i = 0; i < max_name_size - 1; i++)
			{
				name[i] = newName[i];
			}

			//otherwise safe empty
		}
		else {
			name[0] = '\0';
		}

		//allocate new memory based on newNumOfPhoneNumbers
		//check if newPhoneNumbers are Valid
		//if Valid move to new allocated space
		//keep track of numbers added
		if (newPhoneNumbers != nullptr && newNumOfPhoneNumbers > 0) {

			phoneNumbers = new long long[newNumOfPhoneNumbers];

			for (int i = 0; i < newNumOfPhoneNumbers; i++) {

				if (isValid(newPhoneNumbers[i]) == true)
				{
					phoneNumbers[numOfPhoneNumbers] = newPhoneNumbers[i];
					numOfPhoneNumbers = numOfPhoneNumbers + 1;
				}

			}

			//otherwise safe empty
		}
		else {
			phoneNumbers = nullptr;
			numOfPhoneNumbers = 0;
		}

	}

	Contact::~Contact()
	{
		//destructor deallocates memory 
		delete[] phoneNumbers;
	}

	bool Contact::isEmpty() const
	{
		//if in same empty state then true else false
		return (name[0] == '\0' && phoneNumbers == nullptr && numOfPhoneNumbers == 0) ? true : false;
	
	}

	

	void Contact::display() const
	{
		string phoneNumString;
		int phoneNumStrLength;

		string codeCountry;
		string codeArea;
		string phoneNum3;
		string phoneNum4;


		if(isEmpty()){

			cout << "Empty contact!" << endl;
		
		} else {

			//output name
			cout << name << endl;

			//go through the phones
			for (int i = 0; i < numOfPhoneNumbers; i++) {

				//change number to a string
				phoneNumString = to_string(phoneNumbers[i]);

				//find out the length of the number
				phoneNumStrLength = phoneNumString.length();

				//country code = phone number starting at 0 and sub the 7 digit phone and area code
				codeCountry = phoneNumString.substr(0, (phoneNumStrLength - 10));

				//area code = phone number sub the same as before but copy the 3 digit area code
				codeArea = phoneNumString.substr(phoneNumStrLength - 10, 3);

				//first 3 numbers of the 7 digit sub 7 copy the 3
				phoneNum3 = phoneNumString.substr(phoneNumStrLength - 7, 3);

				//last 4 numbers of the 7 digit sub 4 copy the 4
				phoneNum4 = phoneNumString.substr(phoneNumStrLength - 4, 4);

				//piece the output together
				cout << "(+" + codeCountry + ")" + " " + codeArea + " " + phoneNum3 + "-" + phoneNum4 << endl;

			}

		}
	}

	//use a bool isValid function to check if the incoming phone number is Valid
	bool Contact::isValid(long long newPhoneNumber)
	{
		//change incoming number into a string
		string newPhoneNumString = to_string(newPhoneNumber);

		//Incoming number is not valid if
		//length is less then 11 or greater then 12
		//areacode first digit is 0
		//number starts with 0
		//the number is either 0 or less
		bool notValid = newPhoneNumString.length() < 11 || newPhoneNumString.length() > 12 
			|| newPhoneNumString[newPhoneNumString.length() - 7] == '0' 
			|| newPhoneNumString[newPhoneNumString.length() - 10] == '0'
			|| newPhoneNumber <= 0;
		
		return !notValid;
		
	}
}