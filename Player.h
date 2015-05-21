//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Player.h
// -----------
// This file declares a class to manage a player includeing its score, number of lives, position, direction etc.
//
// Author: Dror Moyal
// First version: 2015-04-08
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-08     Dror Moyal      implemented the Player class

#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include "Direction.h"
#include "Exercise.h"
#include "AdvExercise.h"
#include "Point.h"
#include "io_utils.h"


using namespace std;

//=====================================
// this class implements the use of a 
// player
//=====================================
class Player{
	unsigned char playerChar;
	unsigned int playerScore;
	unsigned int playerLives;
	unsigned int shotsCounter;
	bool playerAlive;
	bool playerDone;
	Direction::VALUE playerDirection;
	Exercise* playerExercise;
	AdvExercise* playerAdvExercise;
	Point playerPosition;
public:
	// player default constructor
	Player()
		:playerChar(0), playerScore(0), playerLives(3), playerAlive(true), playerDone(false), playerDirection(Direction::STAY),
		playerPosition(Point(0, 0)), playerExercise(NULL), playerAdvExercise(NULL){
	}
	// player constructor
	Player(unsigned char playerChar, Direction::VALUE playerDirection, Point playerPosition)
		:playerChar(playerChar), playerScore(0), playerLives(3), playerAlive(true), playerDone(false), playerDirection(playerDirection),
		playerPosition(playerPosition), playerExercise(NULL), playerAdvExercise(NULL){
	}
	// player destructor
	~Player();

	// score getter
	unsigned int getScore()const;
	// lives getter
	unsigned int getLives()const;
	//shptsCounter getter
	unsigned int getShotsCounter()const;
	// position getter
	Point getPosition()const;
	// direction getter
	Direction::VALUE getDirection()const;
	// exercise getter
	string getExercise()const;
	// return how many missing values in exercise
	int numMissinValues(int currentLevel)const;
	// advance exercise getter
	string getAdvExercise()const;
	// exercise creator
	AdvExercise* createAdvExercise(int currentLevel);
	// check if a sulotion is possible
	bool isPossibleSulotion(unsigned int eatenNumber);
	// reset advance exercise
	inline void resetAdvExercise();
	// score setter
	unsigned int setScore(unsigned int newScore);
	// lives setter
	unsigned int setLives(unsigned int newLives);
	//shptsCounter setter
	unsigned int setShotsCounter(unsigned int newShotsCounter);
	// position setter
	Point setPosition(Point newPosition);
	// direction setter
	Direction::VALUE changeDirection(Direction::VALUE newDirection);
	// exercise creator
	Exercise* createExercise(int currentLevel);
	// reset exercise
	inline void resetExercise();
	// verify if player is alive according to the number
	// of lives he has left
	bool isPlayerAlive();
	// reset the value of player alive
	inline void resetPlayerAlive();
	// verify if a player is done according to the
	// number he ate
	bool isPlayerDone(unsigned int eatenNumber);
	// player done getter
	bool getPlayerDone();
	// reset the value of player done
	inline void resetPlayerDone();
	// print a player in his position on screen
	void playerDraw()const;
	// erase a player from his position on screen
	void playerErase()const;
	// computes the movement of a player according to the players direction
	void playerMove();
	// verify if a move is legal according to the other players position
	bool isMoveLegal(Point otherPlayerPos);
	// return the players position after a move
	Point playerNextPos();
};

#endif

//===========================
// player destructor
//===========================
Player::~Player{
	// if player has an exercise, release it
	if (playerExercise != NULL)
	delete playerExercise;
	// if player has an advance exercise, release it
	if (playerAdvExercise != NULL)
		delete playerAdvExercise;
}

//===========================
// delete old exercise and
// create a new one
//===========================
void Player::resetAdvExercise(){
	// if there is an exercise 
	if (playerAdvExercise != NULL){
		delete playerAdvExercise;
		playerAdvExercise = NULL;
	}
}


//===========================
// delete old exercise and
// create a new one
//===========================
void Player::resetExercise(){
	// if there is an exercise 
	if (playerExercise != NULL){
		delete playerExercise;
		playerExercise = NULL;
	}
}

//==========================
// reset the player alive
//==========================
void Player::resetPlayerAlive(){
	playerAlive = true;
}

//==========================
// reset the player done
//==========================
void Player::resetPlayerDone(){
	playerDone = false;
}
