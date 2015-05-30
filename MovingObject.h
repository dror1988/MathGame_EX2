//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// MovingObject.h
// -----------
// This file declares a base class that defines the basic functions and data members for moving objects
//
// Author: Dror Moyal
// First version: 2015-05-26 
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-05-26    Dror Moyal      implemented the MovingObject class

#ifndef _MOVING_OBJECT_H
#define _MOVING_OBJECT_H

#include <string>
#include "Direction.h"
#include "Point.h"
#include "io_utils.h"

using namespace std;

//=====================================
// this base class implements the use 
// of a moving object
//=====================================
class MovingObject{
	unsigned char objChar;
	bool objAlive;
	Direction::VALUE objDirection;
	Point objPosition;
	Color objColor;
public:
	// MovingObject default constructor
	MovingObject() :objChar(0), objAlive(true), objDirection(Direction::STAY), objPosition(Point(0, 0)), objColor(WHITE){
	}
	// MovingObject constructor
	MovingObject(unsigned char objChar, Direction::VALUE objDirection, Point objPosition, Color objColor) :objChar(objChar),
		objAlive(true), objDirection(objDirection), objPosition(objPosition), objColor(objColor){
	}
	// MovingObject destructor
	virtual ~MovingObject(){}
	// object init
	void initObject(unsigned char setChar, Direction::VALUE setDirection, Point setPosition, Color setColor){
		objChar = setChar;
		objDirection = setDirection;
		objPosition = setPosition;
		objAlive = true;
		objColor = setColor;
	}

	// position getter
	Point getPosition()const;
	// direction getter
	Direction::VALUE getDirection()const;
	// position setter
	Point setPosition(Point newPosition);
	// direction setter
	Direction::VALUE changeDirection(Direction::VALUE newDirection);
	// returns if object is alive
	bool getObjAlive();
	// reset the value of object alive
	void resetObjAlive();
	// print a player in his position on screen
	void objDraw()const;
	// erase a player from his position on screen
	void objErase()const;
	// computes the movement of an Object according to the Object direction
	void objMove();
	void objMovement();
	// return an object position after a move
	Point objNextPos();
};

#endif
