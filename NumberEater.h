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

#ifndef _NUMBER_EATER_H
#define _NUMBER_EATER_H
#include "MovingObject.h"
#include "Player.h"
#include "StatusBar.h"
#include <cmath>
#include <algorithm> 

class NumberEater : public MovingObject{
	unsigned int disToX;
	unsigned int disToY;
	Point numToEatPosition;
public:
	// NumberEater constructor	
	NumberEater(Direction::VALUE eaterDirection, Point eaterPosition)
		: MovingObject('%', eaterDirection, eaterPosition, WHITE), disToX(0), disToY(0), numToEatPosition(Point(0, 0)){
	}
	// Eater creature init
	void initObject(Direction::VALUE setDirection, Point setPosition)
	{
		MovingObject::initObject('%', setDirection, setPosition, WHITE);
	}
	//handling a colusion with a Player
	void coliddedAPlayer(Player& p, int playerNum, StatusBar& stBar);
	//check if the oject colidded a bulet
	bool coliddedAShot(Point shotPos, Point shotNextPos);

	void updateDirection(){
		if (numToEatPosition == Point(0, 0))
			changeDirection(Direction::STAY);
		else{
			if (disToX > 0){
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
			else if (disToY > 0){
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
			}else
				changeDirection(Direction::STAY);
		}
	}

	unsigned int getDisToX()const{
		return disToX;
	}

	unsigned int getDisToY()const{
		return disToY;
	}

	Point getNumToEatPosition()const{
		return numToEatPosition;
	}

	unsigned int setDisToX(unsigned int newDistance){
		disToX = newDistance;
		return disToX;
	}

	unsigned int setDisToY(unsigned int newDistance){
		disToY = newDistance;
		return disToY;
	}

	Point setNumToEatPosition(Point newPoint){
		numToEatPosition = newPoint;
		disToX = min(abs(getPosition().x - newPoint.x), min(getPosition().x, newPoint.x) + (80 - max(getPosition().x, newPoint.x)));
		disToY = min(abs(getPosition().y - newPoint.y), min(getPosition().y, newPoint.y) + (21 - max(getPosition().x, newPoint.x)));
		return numToEatPosition;
	}

};

#endif