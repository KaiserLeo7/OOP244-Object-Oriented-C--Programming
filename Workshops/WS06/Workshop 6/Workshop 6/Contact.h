//
// Workshop 6
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/08/19
//
// TODO: header file guard
#ifndef _244_CONTACT_H
#define _244_CONTACT_H

// TODO: create namespace

namespace sict {

	const int max_name_size = 16;

	class Contact {

		char name[max_name_size];

		long long *phoneNumbers;

		int numOfPhoneNumbers;

	public:

		Contact();

		Contact(const char*, const long long *, int);

		~Contact();

		bool isEmpty() const;

		void display() const;

	private:

		bool isValid(long long);
	};

}

#endif