//
// Milestone 1
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/09/19
//

#include <iostream>
#include "Date.h"

namespace ama {

	Date::Date() {
		//set to safe empty state
		year = 0;
		month = 0;
		day = 0;

		errorStatus = 0;
	}

	void Date::status(int newStatus) {
		//set Status to the incoming status
		errorStatus = newStatus;
	}

	Date::Date(int newYear, int newMonth, int newDay)
	{
		//if each number is within range store them and set status to no_error
			//if not sets to safe empty state and sets status to the correct error

		//check year
		if (newYear < min_year || newYear > max_year) {

			*this = Date();

			status(error_year);
		}//check month
		else if (newMonth < 1 || newMonth > 12) {

			*this = Date();
			status(error_mon);
		}//check day
		else if (newDay > mdays(newYear, newMonth) || newDay < 1) {

			*this = Date();
			status(error_day);
		}
		else {//store date
			Valid = true;

			year = newYear;
			month = newMonth;
			day = newDay;

			status(no_error);
		}

	}

	int Date::status() {
	//return an int that represents the status of the object.
		return errorStatus;
	}

	void Date::clearError() {
	//resets the status of an object to no_error 
		status(no_error);
	}

	bool Date::isGood() {
	//returns true if the object stores a valid date and not in error mode.
		bool allGood = (errorStatus == no_error && Valid == true) ? true : false;
		return allGood;
	}

	bool Date::EmptyErrorMode() {
	
		if (status() != no_error || (year == 0 && month == 0 && day == 0)) {
		
			ErrorEmptyMode = true;
		}
	
		return ErrorEmptyMode;
	}

	Date& Date::operator+=(int newDays) {
		
		if (status() == no_error || (day == 0 && month == 0 && year == 0)) {
		
			if ((day + newDays) < mdays(year, month) && (day + newDays) > 0) {
			
				day += newDays;

			} else {

				status(error_invalid_operation);
			}
		
		} else {
		
			status(error_invalid_operation);
		}
			
		return *this;
	}

	Date &Date::operator++() {
	//use mdays to get days in month
		//if in error mode or safe empty state set to invalid operator
			//else increment day, return current object reference
		int daysInMonth = mdays(year, month);

		if (EmptyErrorMode() || (this->day + 1) > daysInMonth) {

			status(error_invalid_operation);

		} else {
			
			status(no_error);
			this->day += 1;
		}
		return *this;
	}

	Date Date::operator++(int) {
	//save current object 
		//increment object
			//return the original
		Date save = *this;
		++(*this);

		return save;
	}

	const Date Date::operator+(int newDays) const{
	//use mdays to get days in month
		//if in error mode or safe empty state set to invalid operator
			//return a copy of the current object
		int daysInMonth = mdays(year, month);

		Date copy = *this;
		//*this->year = copy.year;
		//*this->month = copy.month;
		//*this->day = copy.day;

		if (errorStatus != no_error || (year == 0 && month == 0 && day == 0) || (day + newDays) > daysInMonth) {
			
			copy.status(error_invalid_operation);

		} else {

			copy.day += newDays;
		}
		
		return copy;
	}

	bool Date::operator==(const Date& rhs) {
	//compare current object to rhs values
		//if MATCH set bools to true
			//if all bools are true return true else false
		bool sameDay = false;
		bool sameMonth = false;
		bool sameYear = false;
		bool sameDate;

		if (day == rhs.day)
			sameDay = true;
		if (month == rhs.month)
			sameMonth = true;
		if (year == rhs.year)
			sameYear = true;

		sameDate = (sameDay == true && sameMonth == true && sameYear == true) ? true : false;

		return sameDate;
	}

	bool Date::operator!=(const Date& rhs) {
	//return true if current object and rhs DONT match
		return !(*this == rhs);
	}

	bool Date::operator<(const Date& rhs)
	{
		//compare current object to rhs values
			//if LESS THEN set bool to true
		
		bool earlier = (this->year < rhs.year || this->month < rhs.month || this->day < rhs.day) ? true : false;
		return earlier;
	}

	bool Date::operator>(const Date& rhs) {
	//return true if current object is NOT less then rhs 
		bool later = (this->year > rhs.year || this->month > rhs.month || this->day > rhs.day) ? true : false;
		return later;
	}

	bool Date::operator<=(const Date& rhs) {
	//return true if current object is less then or equal to rhs
		return (*this < rhs || *this == rhs) ? true : false;
	}

	bool Date::operator>=(const Date& rhs) {
	//return true if the current object is greater then or equal to rhs
		return (*this > rhs || *this == rhs) ? true : false;
	}

	std::istream& Date::read(std::istream& is) {
	
		char single;
		int newYear;
		int newMonth;
		int newDay;

		is >> newYear >> single >> newMonth >> single >> newDay;

		if (is.fail()) {

			*this = Date();
			status(error_input);

		} else {

			*this = Date(newYear, newMonth, newDay);
		}

		return is;
	}

	std::ostream& Date::write(std::ostream& os) const {
	
		char single = '/';

		os.width(4);
		os.fill('0');
		os << year << single;

		if (month < 10 && month > 0)
		{
			os << 0;
		}
		else {
			os.width(2);
		}
		
		os.fill('0');
		os << month << single;

		if (day < 10 && day > 0)
		{
			os << 0;
		}
		else {
			os.width(2);
		}
		
		os.fill('0');

		os << day;
		os.fill(' ');
		return os;
	}

	std::istream& operator>>(std::istream& is, Date& s) {
		s.read(is);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Date& s) {
		s.write(os);
		return os;
	}

	int Date::mdays(int year, int mon) const {
		
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 }; 
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;  
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); 
	
	}
}

