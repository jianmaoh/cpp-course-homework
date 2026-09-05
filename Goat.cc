#include <iostream>
#include "Goat.h"

Goat::Goat():Creature(){
	
	foodPoint = 20;
	isMoved = true;
	setType(GOAT);
}

void
Goat::oneRunAction(){
	
	isMoved = false;
	foodPoint -= 1;
	aging();
}


bool
Goat::isGiveBirth(){
	
	if(getAge() >= 50 && getAge() <= 55)
		return true;
	else return false;
}

bool
Goat::isDead(){
	
	if(getAge() == 70|| foodPoint == 0)
		return true;
	else return false;
}

void 
Goat::addFoodPoint(){
	
	foodPoint+=5;
}

void 
Goat::alreadyMoved(){
	
	isMoved = true;
}

bool
Goat::canIMove(){
	
	if(isMoved == true)
		return false;
	else return true;
}

