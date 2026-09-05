#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature(){
	
	age = 0;
	ALifeType = EMPTY;
}

Creature::~Creature(){}

Category
Creature::getType(){
	
	return ALifeType;
}

bool 
Creature::isGoat(){
	
	if(ALifeType == GOAT)
		return true;
	else return false;
}

bool 
Creature::isGrass(){
	if(ALifeType == GRASS)
		return true;
	else return false;
}

bool 
Creature::isEmpty(){
	if(ALifeType == EMPTY)
		return true;
	else return false;
}


void
Creature::setType(Category type){
	
	ALifeType = type;
}

int
Creature::getAge(){
	
	return age;
}

void
Creature::aging(){
	
	age++;
}
