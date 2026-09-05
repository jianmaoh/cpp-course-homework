#include <iostream>
#include "Grass.h"


using namespace std;

Grass::Grass() :Creature(){
	setType(GRASS);
}

void
Grass::oneRunAction(){

	aging();
}

bool
Grass::isGiveBirth(){

	if(getAge() > 2 && getAge() <= 6)
		return true;
	else return false;
}

bool 
Grass::isDead(){

	if(getAge() > 6)
		return true;
	else return false;		
}
void 
Grass::addFoodPoint(){
}

void 
Grass::alreadyMoved(){	
}

bool 
Grass::canIMove(){
	return false;
}
