#include <iostream>
#include "RandomNum.h"
#include "World.h"
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"

using namespace std;

int dirX[4] = {-1 , 1 , 0 ,0};
int dirY[4] = {0, 0 , -1 , 1};

World::World(int numPasses , int seed):randNum(seed){

	nowRound = 0;
	totalRound = numPasses;
	for(int i = 0 ; i < 20 ; i++){
		for(int j = 0 ; j < 35 ; j++){
			alifeMap[i][j] = nullptr;
		}
	}
}

World::~World(){}

void
World::initialMap(){

	//5 goat 10 grass
	for(int i = 0 ; i < 5 ;){
		int goatRandX = randNum.getRandomNum(0,19);
		int goatRandY = randNum.getRandomNum(0,34);
		//cout << goatRandX << " " << goatRandY << endl; 
		if(alifeMap[goatRandX][goatRandY] == nullptr){
			alifeMap[goatRandX][goatRandY] = new Goat;
			i++;
			//cout << goatRandX << " " << goatRandY << endl; 
		}
	}

	for(int i = 0 ; i < 10 ;){
		int grassRandX = randNum.getRandomNum(0,19);
		int grassRandY = randNum.getRandomNum(0,34);
		if(alifeMap[grassRandX][grassRandY] == nullptr){
			alifeMap[grassRandX][grassRandY] = new Grass;
			i++;
			//cout << grassRandX << " " << grassRandY << endl;
		}
	}
}
void
World::display(){

	for(int i = -1 ; i < 20 ; i++){
		for(int j = -1 ; j < 35 ; j++){
			if(i == -1 && j == -1)
				cout << "  ";
			else if(j == -1)
				cout << i % 10;
			else if(i == -1) 
				cout << j % 10 << " ";
			else if(alifeMap[i][j] != nullptr){
				if(alifeMap[i][j] -> getType() == GRASS)
					cout << " I";
				if(alifeMap[i][j] -> getType() == GOAT)
					cout << " X";
			}else cout << "  ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------------------------------" << endl;
}

// isGiveBirth 寫在外面
void
World::mainLoop(int interval){

	initialMap();
	//display();
	for(int p = 0 ; p < totalRound ; p++){
		int time = 0;
		for(int i = 0 ; i < 20 ; i++){
			for(int j = 0 ; j < 35 ; j++){
				if(alifeMap[i][j] != nullptr){
					//alifeMap[i][j] -> oneRunAction();
					if(alifeMap[i][j] -> isDead()){
						creatureDie(i,j);
					}else if(alifeMap[i][j] -> isGoat() && alifeMap[i][j] -> canIMove()){
						int legalX = 0; 
						int legalY = 0;
						for(int k = 0 ; k < 4 ; k++){
							int dirNum = randNum.getRandomNum(0,3);
							//cout << dirNum << endl;
							//if(isThereGrass(i,j,dirX[dirNum],dirY[dirNum])||legal(i,j,dirX[dirNum],dirY[dirNum])){
								legalX = dirX[dirNum];
								legalY = dirY[dirNum];
								//	cout <<"tes"<<endl;
							//	break;
						//	}
						}
						//cout << i <<" "<< j << " " <<  legalX << " " << legalY << endl;
						if(!(legalX == 0 && legalY == 0)){
							if(isThereGrass(i,j,legalX,legalY)){
								goatEat(i,j,legalX,legalY);
								if(alifeMap[i][j] -> isGiveBirth()){
									goatGiveBirth(i,j,legalX,legalY);
								}
								else{ 
									goatMove(i,j,legalX,legalY);
								}
							}else if (legal(i,j,legalX,legalY)){
								if(alifeMap[i][j] -> isGiveBirth()){
									goatGiveBirth(i,j,legalX,legalY);
								}	
								else{ 
									goatMove(i,j,legalX,legalY);
								}
							}
						}
						//alifeMap[i+legalX][j+legalY] -> oneRunAction();
					}else if (alifeMap[i][j] -> isGrass()){
							int legalX = 0; 
							int legalY = 0;
							for(int k = 0 ; k < 4 ; k++){
								int dirNum = randNum.getRandomNum(0,3);
								//cout << dirNum << endl;
									legalX = dirX[dirNum];
									legalY = dirY[dirNum];
									//	cout <<"tes"<<endl;
							}
							if(alifeMap[i][j] -> isGiveBirth() && legal(i,j,legalX,legalY))
								grassGiveBirth(i,j,legalX,legalY);
					}
					//alifeMap[i][j] -> oneRunAction();
					//cout << "in" << endl;
				}
			}
		}
		for(int i = 0 ; i < 20 ; i++){
			for(int j = 0 ; j < 35 ; j++){
				if(alifeMap[i][j] != nullptr)
					alifeMap[i][j] -> oneRunAction();
			}
		}
		//cout << time << endl;
		//display();
		nowRound++;
		if(nowRound % interval == 0)
			display();
	}
	//	alifeMap[0][1] -> oneRunAction();
	//	goatMove(0,1,0,1);
	/*if(alifeMap[0][1] -> canIMove())
	  cout << "yes" << endl;
	  else cout << "no" << endl;*/
}

bool
World::legal(int originalX ,int originalY , int dx , int dy){

	int nowX = originalX + dx;
	int nowY = originalY + dy;
	if(nowX >= 0 && nowX < 20 && nowY >= 0 && nowY < 35 && alifeMap[nowX][nowY] == nullptr)
		return true;
	else return false;
}

bool
World::isThereGrass(int originalX , int originalY , int dx , int dy){

	int nowX = originalX + dx;
	int nowY = originalY + dy;
	if(alifeMap[nowX][nowY] != nullptr){
		if(nowX >= 0 && nowX < 20 && nowY >= 0 && nowY < 35 && alifeMap[nowX][nowY] -> getType() == GRASS)
			return true;
		else return false;
	}else return false;


}

void
World::goatMove(int originalX , int originalY , int dx , int dy){

	int forwordX = originalX + dx;
	int	forwordY = originalY + dy;
	if(alifeMap[forwordX][forwordY] == nullptr){
		alifeMap[forwordX][forwordY] = alifeMap[originalX][originalY];
		alifeMap[forwordX][forwordY] -> alreadyMoved();
		//delete alifeMap[originalX][originalY];
		alifeMap[originalX][originalY] = nullptr;
	}
}
// if(isThereGrass) -> goatEat
void
World::goatEat(int originalX , int originalY , int dx , int dy){

	delete alifeMap[originalX + dx][originalY + dy];
	alifeMap[originalX +dx][originalY + dy] = nullptr;
//	alifeMap[originalX][originalY] -> alreadyMoved();
	alifeMap[originalX][originalY] -> addFoodPoint();
}

void 
World::goatGiveBirth(int originalX , int originalY , int dx ,int dy){

	int nowX = originalX + dx;
	int nowY = originalY + dy;
	alifeMap[originalX][originalY] -> alreadyMoved();
	if(legal(originalX , originalY , dx , dy)){
		alifeMap[nowX][nowY] = new Goat;
	}
}

void 
World::grassGiveBirth(int originalX , int originalY , int dx ,int dy){

	int nowX = originalX + dx;
	int nowY = originalY + dy;
	if(legal(originalX , originalY , dx , dy)){
		alifeMap[nowX][nowY] = new Grass;
	}
}

void
World::creatureDie(int nowX , int nowY){

	delete alifeMap[nowX][nowY];
	alifeMap[nowX][nowY] = nullptr;

}

int 
World::getDirX(direction dir){

	if(dir == UP)
		return -1;
	if(dir == DOWN)
		return 1;
	if(dir == LEFT)
		return 0;
	if(dir == RIGHT)
		return 0;
}

int 
World::getDirY(direction dir){

	if(dir == UP)
		return 0;
	if(dir == DOWN)
		return 0;
	if(dir == LEFT)
		return -1;
	if(dir == RIGHT)
		return 1;

}
