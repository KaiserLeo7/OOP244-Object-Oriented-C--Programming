//
// Workshop 7
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/15/19
//
// TODO: header file guard
#ifndef _244_HERO_H
#define _244_HERO_H
#include <iostream>
// TODO: create namespace

namespace sict {

	int const max_rounds = 100;

	class Hero {

		char heroName[41];
		int heroHealth;
		int heroAttack;

	public:

		Hero();
		Hero(const char* heroName, int heroHealth, int heroAttack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		const char* displayName() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
		
	const Hero& operator*(const Hero& first, const Hero& second);

}
#endif