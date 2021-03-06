//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// NumberEater.cpp
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

#include "NumberEater.h"


//===================================
//handling a colusion with a Player
//===================================
void NumberEater::coliddedAPlayer(Player& p, int playerNum, StatusBar &stBar)
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
bool NumberEater::coliddedAShot(Point shotPos, Point shotNextPos)
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

//===================================
// Update the direction of the eater
// according to the number that needs to 
// be eaten
//===================================
void NumberEater::updateDirection(){
	// handles direction of the number eater
	if (numToEatPosition == Point(0, 0)) //case there is no number to eat
		changeDirection(Direction::STAY);
	else{
		if (disToX > 0){ //while need to move on X axle
			if ((getPosition().x + disToX) == numToEatPosition.x){ 
				changeDirection(Direction::RIGHT);
				setDisToX(--disToX);
			}
			else if ((getPosition().x - disToX) == numToEatPosition.x){
				changeDirection(Direction::LEFT);
				setDisToX(--disToX);
			}
			else{
				if (getPosition().x >= 40){
					changeDirection(Direction::RIGHT);
					setDisToX(--disToX);
				}
				else{
					changeDirection(Direction::LEFT);
					setDisToX(--disToX);
				}
			}
		}
		else if (disToY > 0){ //while need to move on Y axle
			if ((getPosition().y + disToY) == numToEatPosition.y){
				changeDirection(Direction::DOWN);
				setDisToY(--disToY);
			}
			else if ((getPosition().y - disToY) == numToEatPosition.y){
				changeDirection(Direction::UP);
				setDisToY(--disToY);
			}
			else{
				if (getPosition().y >= 14){
					changeDirection(Direction::DOWN);
					setDisToY(--disToY);
				}
				else{
					changeDirection(Direction::UP);
					setDisToY(--disToY);
				}
			}
		}
		else //any other case
			changeDirection(Direction::STAY);
	}
}

//===================================
// Update all releventdistance  variables
// according to the new number to eat
//===================================
Point NumberEater::setNumToEatPosition(Point newPoint){
	numToEatPosition = newPoint;
	disToX = min(abs(getPosition().x - newPoint.x), min(getPosition().x, newPoint.x) + 1 + (79 - max(getPosition().x, newPoint.x)));
	disToY = min(abs(getPosition().y - newPoint.y), min(getPosition().y, newPoint.y) + 1 + (23 - max(getPosition().y, newPoint.y)) - 3);
	return numToEatPosition;
}

//+++++++++++++++++++++
// END of NEW CODE EX3
//+++++++++++++++++++++
