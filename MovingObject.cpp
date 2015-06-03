//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// MovingObject.cpp
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
// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX3, author=Dror Moyal, date=2015-05-26 
// +++++++++++++++++++++++++++++++++++++++++++++++++

#include "MovingObject.h"

//===================================
// position getter
//===================================
Point MovingObject::getPosition()const{
	return objPosition;
}

//===================================
// direction getter
//===================================
Direction::VALUE MovingObject::getDirection()const{
	return objDirection;
}

//===================================
// position setter
//===================================
Point MovingObject::setPosition(Point newPosition){
	objPosition = newPosition;
	return objPosition;
}

//===================================
// direction setter
//===================================
Direction::VALUE MovingObject::changeDirection(Direction::VALUE newDirection){
	objDirection = newDirection;
	return objDirection;
}

//===================================
// verify if object is alive 
//===================================
bool MovingObject::getObjAlive(){
	return objAlive;
}

//===================================
// reset the object alive
//===================================
void MovingObject::resetObjAlive(){
	objAlive = true;
}

//===================================
// print a object in his 
// position on screen
//===================================
void MovingObject::objDraw() const{
	setTextColor(objColor);
	gotoxy(objPosition.x, objPosition.y);
	cout << objChar;
	setTextColor(WHITE);
}

//===================================
// erase a object from his position 
// on screen
//===================================
void MovingObject::objErase()const{
	gotoxy(objPosition.x, objPosition.y);
	cout << ' ';
}

//===================================
// computes the movement of an object 
// according to the object direction
//===================================
void MovingObject::objMove(){
	// use direction as a case
	// make sure player will no go out
	// of screen borders
	switch (objDirection){
	case Direction::UP:
		if (objPosition.y > Point::minY)
			objPosition.y--;
		else
			objPosition.y = Point::maxY;
		break;
	case Direction::DOWN:
		if (objPosition.y < Point::maxY)
			objPosition.y++;
		else
			objPosition.y = Point::minY;
		break;
	case Direction::LEFT:
		if (objPosition.x > Point::minX)
			objPosition.x--;
		else
			objPosition.x = Point::maxX;
		break;
	case Direction::RIGHT:
		if (objPosition.x < Point::maxX)
			objPosition.x++;
		else
			objPosition.x = Point::minX;
		break;
	case Direction::STAY:
		break;
	}
}

//===================================
// Aggregates all movement functions
// according to the object direction
//===================================
void MovingObject::objMovement()
{
	objErase();
	objMove();
	objDraw();
}

//===================================
// Calculate object next position
// according to the object direction
//===================================
Point MovingObject::objNextPos(){
	MovingObject tmp;
	tmp.setPosition(this->objPosition);
	tmp.changeDirection(this->objDirection);
	tmp.objMove();
	return tmp.getPosition();
}

//+++++++++++++++++++++
// END of NEW CODE EX3
//+++++++++++++++++++++
