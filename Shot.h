//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Shot.h
// -----------
// This file declares a class to manage the creation and movement of the game shots 
//
// Author: Maya Bugana
// First version: 2015-05-10
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-10    Maya Bugana     implemented the Shot class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX2, author=Maya Bugana, date=2015-04-10
// +++++++++++++++++++++++++++++++++++++++++++++++++



#ifndef _SHOT_H
#define _SHOT_H

#include <string>
#include "Point.h"
#include "Direction.h"
#include "io_utils.h"
#include <iostream>

//=====================================
// this class implements the use of a 
// Shot
//=====================================

class Shot
{
	unsigned char shotChar;
	Direction::VALUE shotDirection;
	Point shotPosition;
public:
	// Shot constructor
	Shot(Point shotPosition, Direction::VALUE shotDirection) :
		shotChar('*'), shotPosition(shotPosition), shotDirection(shotDirection){
	}
	// Shot default constructor
	Shot(){};
	// Shot destructor
	~Shot(){};

	// shots getters and setters functions
	Point getPosition()const;
	Direction::VALUE getShotDirection();
	Point setPosition(Point newPosition);
	Direction::VALUE setShotDirection(Direction::VALUE newDirection);
	void shotSetPos();

	// Draw a shot char on the screen
	void shotDraw()const;
	// Erase shots char from the screen
	void shotErase()const;
	//Calculate Shot next position according to its direction
	Point shotNextPos();
	//Manage th emovement of a shot
	void shotMove();
};
#endif // !_SHOT_H

//+++++++++++++++++++++
// END of NEW CODE EX2
//+++++++++++++++++++++
