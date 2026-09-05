#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <iostream>

using namespace std;

enum Category {EMPTY = 0 , GOAT = 1 , GRASS = 2 };


class Creature {

	public:

		Creature();

		virtual ~Creature() = 0;

		virtual void oneRunAction() = 0;

		virtual bool isGiveBirth() = 0;

		virtual bool isDead() = 0;

		virtual void addFoodPoint() = 0;

		virtual void alreadyMoved() = 0;

		virtual bool canIMove() = 0;

		void setType(Category);

		void aging();

		int getAge();

		Category getType();

		bool isGoat();

		bool isGrass();

		bool isEmpty();

	private:

		int age;
		Category ALifeType; 
};

#endif // _CREATURE_
