//
// Workshop 7
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/18/19
//

#include <iostream>
#include "SuperHero.h"


using namespace std;
using namespace sict;

namespace sict {

	SuperHero::SuperHero() : Hero() {

		superBonus = 0;
		superDefend = 0;

	}

	SuperHero::SuperHero(const char* name, int health, int strength, int bonus, int defend) : Hero(name, health, strength) {
	
		superBonus = bonus;
		superDefend = defend;
	
	}


	int SuperHero::attackStrength() const {
	
		if (superBonus == 0) {
			return 0;
		}
		else {
			return Hero::attackStrength() + superBonus;
		}
	}

	int SuperHero::defend() const {
	
		if (superDefend == 0) {
			return 0;
		}
		else {
			return superDefend;
		}
	
	}


	const  SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
	
	
		SuperHero left = first;
		SuperHero right = second;
		SuperHero winner;

		int round = 0;
	

		for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); i++)
		{

			left -= right.attackStrength() - left.defend();
			right -= left.attackStrength() - right.defend();

			round = i;

		}
		round++;
		if (!right.isAlive()) {

			winner = left;

			cout << "Super Fight! " << left.displayName() << " vs " << right.displayName()
				<< " : Winner is " << winner.displayName() << " in " << round << " rounds." << endl;
			return first;

		}
		else if (!left.isAlive()) {

			winner = right;

			cout << "Super Fight! " << left.displayName() << " vs " << right.displayName()
				<< " : Winner is " << winner.displayName() << " in " << round << " rounds." << endl;
			return second;

		}
		else if (!right.isAlive() && !left.isAlive()) {

			winner = left;

			cout << "Super Fight! " << left.displayName() << " vs " << right.displayName()
				<< " : Winner is " << winner.displayName() << " in " << round << " rounds." << endl;
			return first;

		}
		else {

			return first;
		}
	}
}