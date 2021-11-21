//
// Workshop 7
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/18/19
//
// TODO: header file guard

#ifndef _244_SUPERHERO_H
#define _244_SUPERHERO_H

#include "Hero.h"
// TODO: create namespace


namespace sict {


	class SuperHero : public Hero {

		int superBonus;
		int superDefend;

	public:

		SuperHero();
		SuperHero(const char* name, int health, int attack, int bonus, int defend);
		
		int attackStrength() const;
		int defend() const;
		
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif