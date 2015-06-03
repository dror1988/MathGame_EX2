//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ColFlyer.h
// -----------
// This file declares a base class that defines a class derived from MovingObjects that implements Column Flyer
// cretures abilities and characters
//
// Author: Maya Bugana
// First version: 2015-05-30 
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-05-30    Maya Bugana    implemented the ColFlyer class
// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX3, author=Maya Bugana, date=2015-05-30
// +++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef _COL_FLYER_H
#define _COL_FLYER_H

#include "MovingObject.h"
#include "Player.h"
#include "StatusBar.h"

class ColFlyer : public MovingObject{
public:
	// ColFlyer constructor	
	ColFlyer(Direction::VALUE flyerDirection, Point flyerPosition)
		: MovingObject('$', flyerDirection, flyerPosition, MAGENTA){
	}
	// Flyer creature init
	void initObject(Direction::VALUE setDirection, Point setPosition)
	{
		MovingObject::initObject('$', setDirection, setPosition, MAGENTA);
	}
	//handling a colusion with a Player
	void coliddedAPlayer(Player& p, int playerNum, StatusBar& stBar);
	//check if the oject colidded a bulet
	bool coliddedAShot(Point shotPos, Point shotNextPos);
};

#endif

//+++++++++++++++++++++
// END of NEW CODE EX3
//+++++++++++++++++++++
