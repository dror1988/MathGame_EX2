//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// NumberEater.h
// -----------
// This file declares a class derived from MovingObjects that implements Number Eater
// cretures abilities and characters
//
// Author: Dror Moyal
// First version: 2015-06-02
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-06-02   Dror Moyal    implemented the NumberEater class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX3, author=Dror Moyal, date=2015-06-02 
// +++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef _NUMBER_EATER_H
#define _NUMBER_EATER_H

#include "MovingObject.h"
#include "Player.h"
#include "StatusBar.h"
#include <cmath>
#include <algorithm> 

//=====================================
// this class implements creature
// number eater
//=====================================
class NumberEater : public MovingObject{
	unsigned int disToX;
	unsigned int disToY;
	Point numToEatPosition;
public:
	// NumberEater constructor	
	NumberEater(Direction::VALUE eaterDirection, Point eaterPosition)
		: MovingObject('%', eaterDirection, eaterPosition, YELLOW), disToX(0), disToY(0), numToEatPosition(Point(0, 0)){
	}
	// Eater creature init
	void initObject(Direction::VALUE setDirection, Point setPosition)
	{
		MovingObject::initObject('%', setDirection, setPosition, YELLOW);
	}
	//handling a colusion with a Player
	void coliddedAPlayer(Player& p, int playerNum, StatusBar& stBar);
	//check if the oject colidded a bulet
	bool coliddedAShot(Point shotPos, Point shotNextPos);
	// update the eater direction
	void updateDirection();
	// disToX getter
	unsigned int getDisToX()const{
		return disToX;
	}
	// disToY getter
	unsigned int getDisToY()const{
		return disToY;
	}
	// numToEatPosition getter
	Point getNumToEatPosition()const{
		return numToEatPosition;
	}
	// disToX setter
	unsigned int setDisToX(unsigned int newDistance){
		disToX = newDistance;
		return disToX;
	}
	// disToY setter
	unsigned int setDisToY(unsigned int newDistance){
		disToY = newDistance;
		return disToY;
	}
	// update all relevt disatnce variables
	Point setNumToEatPosition(Point newPoint);

};

#endif

//+++++++++++++++++++++
// END of NEW CODE EX3
//+++++++++++++++++++++
