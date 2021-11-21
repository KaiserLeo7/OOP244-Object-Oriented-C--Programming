//
// Workshop 7
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 3/15/19
//

#include <iostream>
#include <string>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict {

	Hero::Hero() {
	
		heroName[0] = '\0';
		heroHealth = 0;
		heroAttack = 0;
	}


	Hero::Hero(const char* newHeroName, int newHeroHealth, int newHeroAttack) {
	
		bool isName = ((newHeroName != nullptr) && (newHeroName[0] != '\0'));
		bool isHealth = (newHeroHealth > 0);
		bool isStrength = (newHeroAttack > 0);

		if (isName && isHealth && isStrength) {

		    strcpy(heroName, newHeroName);
			heroHealth = newHeroHealth;
			heroAttack = newHeroAttack;
		}
		else {
		
			*this = Hero();
		}
	}


	void Hero::operator-=(int attack) {
	
		if (attack > 0 && heroHealth > 0) {
			this->heroHealth -= attack;
		
			if (heroHealth < 0)
			heroHealth = 0;
		}
	}


	bool Hero::isAlive() const {
	
		return (this->heroHealth > 0) ? true : false;
	}


	int Hero::attackStrength() const {
	
		if (this->heroAttack > 0) {
			return heroAttack;
		}
		else {
			return 0;
		}
	
	}

	const char* Hero::displayName() const {
	
		return heroName;
	}


	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.heroName[0] != '\0' && hero.heroHealth != 0 && hero.heroAttack != 0) {
			os << hero.heroName;
		}
		else {
			os << "No hero";
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second){
		//return unmodifiable reference to the winner after max rounds
			//display hero names
			//makes copies of heroes
			//determine damage each inflicts
			//increment round till 1 heroes heath < 0 or round >= max_rounds
			//each round deduct damage inflicted from one hero to the other
			//display name of winner
			//if draw left hero (first) wins

		Hero left = first;
		Hero right = second;
		Hero winner;

		int round = 0;

		for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); i++)
		{
			
			left -= right.attackStrength();
			right -= left.attackStrength();

	round = i;

		}
		round++;
		if (!right.isAlive()) {

			winner = left;

			cout << "Ancient Battle! " << left.displayName() << " vs " << right.displayName()
				<< " : Winner is " << winner.displayName() << " in " << round << " rounds." << endl;
			return first;

		}
		else if (!left.isAlive()) {

			winner = right;

			cout << "Ancient Battle! " << left.displayName() << " vs " << right.displayName()
				<< " : Winner is " << winner.displayName() << " in " << round << " rounds." << endl;
			return second;

		}else if (!right.isAlive() && !left.isAlive()) {

			winner = left;

			cout << "Ancient Battle! " << left.displayName() << " vs " << right.displayName()
				<< " : Winner is " << winner.displayName() << " in " << round << " rounds." << endl;
			return first;

		} else {
		
			return first;
		}

	}
}