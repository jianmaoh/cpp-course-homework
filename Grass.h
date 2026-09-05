#ifndef _GRASS_H_
#define _GRASS_H_

#include <iostream>
#include "RandomNum.h"
#include "Creature.h"

using namespace std;

class Grass : public Creature{


	public:
		
		Grass();
	
		virtual void oneRunAction();

		virtual bool isGiveBirth();

		virtual bool isDead();

		virtual void addFoodPoint();

		virtual void alreadyMoved();

		virtual bool canIMove();
};

#endif
