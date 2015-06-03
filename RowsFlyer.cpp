//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// RowsFlyer.cpp
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

#include "RowsFlyer.h"



//===================================
//handling a colusion with a Player
//===================================
void RowsFlyer::coliddedAPlayer(Player& p, int playerNum, StatusBar &stBar)
{
	if ((p.getPosition() == objNextPos()) || (p.playerNextPos() == objNextPos()) ||	(p.getPosition() == getPosition()))
	{
		p.setLives(p.getLives() - 1);

		if (playerNum == 1)
			stBar.updatePlayerLife(1);

		else if (playerNum == 2)
			stBar.updatePlayerLife(2);

		// if player is ran out of lives
		if (p.isPlayerAlive()){
			p.playerErase();
			if (playerNum == 1){
				p.setPosition(Point(10, 9));
				p.changeDirection(Direction::RIGHT);
			}
			else{
				p.setPosition(Point(70, 9));
				p.changeDirection(Direction::LEFT);
			}
		}
	}
}


//===================================
//check if a shot colusion with a Player
//===================================
bool RowsFlyer::coliddedAShot(Point shotPos, Point shotNextPos)
{
	if (shotNextPos == objNextPos() ||
		shotPos == getPosition() ||
		shotPos == objNextPos() ||
		shotNextPos == getPosition()
		)
		return true;
	else
		return false;
}

//+++++++++++++++++++++
// END of NEW CODE EX3
//+++++++++++++++++++++
