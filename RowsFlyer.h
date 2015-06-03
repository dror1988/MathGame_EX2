//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// RowsFlyer.h
// -----------
// This file declares a base class that defines a class derived from MovingObjects that implements Rows Flyer
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
// 2015-05-30    Maya Bugana    implemented the RowsFlyer class
// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX3, author=Maya Bugana, date=2015-05-30
// +++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef _ROWS_FLYER_H
#define _ROWS_FLYER_H
#include "MovingObject.h"
#include "Player.h"
#include "StatusBar.h"

class RowsFlyer : public MovingObject{
public:
	// RowsFlayer constructor	
	RowsFlyer(Direction::VALUE flyerDirection, Point flyerPosition)
		: MovingObject('!', flyerDirection, flyerPosition, LIGHTBLUE){
	}
	// Flyer creature init
	void initObject(Direction::VALUE setDirection, Point setPosition)
	{
		MovingObject::initObject('!', setDirection, setPosition, LIGHTBLUE);
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
