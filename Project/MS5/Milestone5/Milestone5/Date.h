//
// Milestone 1
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/09/19
//
// TODO: header file guard

#ifndef _244_DATE_H
#define _244_DATE_H
#include <iostream>

namespace ama {

	const int min_year = 2019;
	const int max_year = 2028;

	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;

	const int error_invalid_operation = 4;
	const int error_input = 5;
	
	class Date {
		
		bool Valid = false;
		bool ErrorEmptyMode = false;

		int year;
		int month;
		int day;

		int errorStatus;

	private:

		void status(int newStatus);

		int mdays(int year, int month) const;

	public:
		bool EmptyErrorMode();

		Date();

		Date(int newYear, int newMonth, int newDay);

		int status();
	
		void clearError();

		bool isGood();
	
		Date& operator+=(int days);

		Date& operator++();

		Date operator++(int);

		const Date operator+(int days) const;

		bool operator==(const Date& rhs);

		bool operator!=(const Date& rhs);

		bool operator<(const Date& rhs);

		bool operator>(const Date& rhs);

		bool operator<=(const Date& rhs);

		bool operator>=(const Date& rhs);
		
		std::istream& read(std::istream& is);

		std::ostream& write(std::ostream& os) const;
	};

	std::istream& operator>>(std::istream& is, Date& s);

	std::ostream& operator<<(std::ostream& os, const Date& s);

}

#endif