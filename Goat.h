#ifndef _GOAT_H_
#define _GOAT_H_

#include <iostream>
#include "Creature.h"

using namespace std;

class Goat : public Creature {
	
	public:

		Goat();

		virtual void oneRunAction();

		virtual bool isGiveBirth();

		virtual bool isDead();

		virtual void addFoodPoint();

		virtual void alreadyMoved();

		virtual bool canIMove();
	
	private:
		
		int foodPoint;
		bool isMoved;

}; 

#endif
