#ifndef _WORLD_H_
#define _WORLD_H_

#include <iostream>
#include "RandomNum.h"
#include "Creature.h"

using namespace std;

#define mapX 20
#define mapY 35

enum direction {UP = 0 , DOWN = 1, LEFT = 2 , RIGHT = 3};

class World{
	
	public:

		World(int , int); //passnum , seed
		
		~World();

		void initialMap();

		void mainLoop(int);

		void display();

		bool legal(int , int , int , int);

		bool isThereGrass(int , int , int , int);

		void goatMove(int , int , int , int);

		void goatEat(int , int , int ,int);

		void goatGiveBirth(int , int , int ,int);

		void grassGiveBirth(int , int , int ,int);

		void creatureDie(int , int);

		int getDirX(direction);

		int getDirY(direction);

	private:

		Creature *alifeMap[mapX][mapY];
		int nowRound;
		int totalRound;
		int showInterval;
		RandomNum randNum;
		
};
#endif
