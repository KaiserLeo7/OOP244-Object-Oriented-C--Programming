//
// Milestone 2
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/14/19
//
// TODO: header file guard


#include <iostream>
#include "ErrorState.h"

namespace ama {

	explicit ErrorState::ErrorState(const char* errorMessage = nullptr){

		if (errorMessage != nullptr){

			msgAddrs = new char[strlen(errorMessage) + 1];
			
			strcpy(msgAddrs, errorMessage);
			
		} else {
			
			msgAddrs = nullptr;
		}
	}

	bool ErrorState::safeState() const {
	
		return (msgAddrs == nullptr) ? true : false;
	}
	
/*
	ErrorState::ErrorState(const ErrorState& other) {
	
	
	}
	
	ErrorState& ErrorState::operator=(const ErrorState& other) {
	
	
	}
*/
	ErrorState::~ErrorState() {
	
		delete[] msgAddrs;
		msgAddrs = nullptr;
	
	}

	ErrorState::operator bool() const {
		
		if (msgAddrs != nullptr)
		return true; 
	}

	ErrorState& ErrorState::operator=(const char* pText) {
	
		char copy = pText;
	
	}

	void ErrorState::message(const char* pText) {
	
		ErrorState(const char* pText);
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
