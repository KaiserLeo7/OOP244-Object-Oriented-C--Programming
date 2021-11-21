//
// Milestone 2
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/14/19
//
// TODO: header file guard

#include <iostream>
#include <string.h>
#include "ErrorState.h"

namespace ama {

	ErrorState::ErrorState(const char* errorMessage){

		if (errorMessage == nullptr || errorMessage[0] == '\0') {
			msgAddrs = nullptr;
		}
		else {
		
			msgAddrs = new char[strlen(errorMessage) + 1];

			strcpy(msgAddrs, errorMessage);
		}
	}
	
	bool ErrorState::safeState() const {
	
		return (msgAddrs == nullptr) ? true : false;
	}
	
	ErrorState::~ErrorState() {
	
		delete[] msgAddrs;
	}

	ErrorState::operator bool() const {

		 bool valid = (msgAddrs != nullptr || msgAddrs != '\0') ? true : false;
		 return valid;
	}

	ErrorState& ErrorState::operator=(const char* pText) {
	
		const char* copy = pText;

		if (copy == nullptr || copy[0] == '\0') {
			msgAddrs = nullptr;
		}
		else {

			msgAddrs = new char[strlen(copy) + 1];

			strcpy(msgAddrs, copy);
		}

		return *this;
	}

	void ErrorState::message(const char* pText) {
	
		const char* copy = pText;

		delete[] msgAddrs;

		if (copy == nullptr || copy[0] == '\0') {
			msgAddrs = nullptr;
		}
		else {

			msgAddrs = new char[strlen(copy) + 1];

			strcpy(msgAddrs, copy);
		}
	}

	const char* ErrorState::message() const {
		
		return msgAddrs;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& s) {
		
		if (s.safeState() == false) {
		
			os << s.message();
		}
		
		return os;
	}
}
