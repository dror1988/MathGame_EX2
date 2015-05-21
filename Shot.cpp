//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Shot.cpp
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

#include "Shot.h"


//===================================
// Position getter
//===================================
Point Shot::getPosition()const
{
	return shotPosition;
}

//===================================
// direction getter
//===================================
Direction::VALUE Shot::getShotDirection()
{
	return shotDirection;
}

//===================================
// Position setter
//===================================
Point Shot::setPosition(Point newPosition)
{
	shotPosition.x = newPosition.x;
	shotPosition.y = newPosition.y;
	return shotPosition;
}

//===================================
// Direction setter
//===================================
Direction::VALUE Shot::setShotDirection(Direction::VALUE newDirection)
{
	shotDirection = newDirection;
	return shotDirection;
}

//===================================
// Draws shot char on the screen
//===================================
void Shot::shotDraw()const
{
	setTextColor(RED);
	gotoxy(shotPosition.x, shotPosition.y);
	cout << shotChar;
	setTextColor(WHITE);
}

//===================================
// Erase shot char from the screen
//===================================
void Shot::shotErase()const
{
		gotoxy(shotPosition.x, shotPosition.y);
		cout << ' ';	
}

//===================================
// Sets the next position of the Shot 
// according to its direction
//===================================
void Shot::shotSetPos()
{
	switch (shotDirection){
	case Direction::UP:
		if (shotPosition.y > Point::minY)
			shotPosition.y--;
		else
			shotPosition.y = Point::maxY;
		break;
	case Direction::DOWN:
		if (shotPosition.y < Point::maxY)
			shotPosition.y++;
		else
			shotPosition.y = Point::minY;
		break;
	case Direction::LEFT:
		if (shotPosition.x > Point::minX)
			shotPosition.x--;
		else
			shotPosition.x = Point::maxX;
		break;
	case Direction::RIGHT:
		if (shotPosition.x < Point::maxX)
			shotPosition.x++;
		else
			shotPosition.x = Point::minX;
		break;
	case Direction::STAY:
		break;
	}
}

//===================================
// Calculate Shot next position 
// according to its direction
//===================================
Point Shot::shotNextPos()
{
	Shot tmp(this->shotPosition, this->shotDirection);
	tmp.shotSetPos();
	return tmp.getPosition();
}

//===================================
// Manage hsot movement
//===================================
void Shot::shotMove()
{
	shotErase();
	shotSetPos();
	shotDraw();
}
