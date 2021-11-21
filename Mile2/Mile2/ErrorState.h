//
// Milestone 2
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/14/19
//
// TODO: header file guard


#ifndef _244_ERRORSTATE_H
#define _244_ERRORSTATE_H
#include <iostream>


namespace ama {


	class ErrorState {
		
		char* msgAddrs;

	public:

		explicit ErrorState(const char* errorMessage = nullptr);

		bool safeState() const;

		ErrorState(const ErrorState& other) = delete;

		ErrorState& operator=(const ErrorState& other) = delete;

		~ErrorState();

		operator bool() const;

		ErrorState& operator=(const char* pText);

		void message(const char* pText);

		const char* message() const;

	};

	std::ostream& operator<<(std::ostream& os, const ErrorState& s);

}

#endif