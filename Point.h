//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Point.h
// -----------
// This file declares a Point class to manage a location of objects in the code.
//
// Author: Dror Moyal
// First version: 2015-04-08
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-08     Dror Moyal      implemented the Point class

#ifndef __POINT_H
#define __POINT_H

#include <iostream>

using namespace std;

//=====================================
// this class implements the use of a 
// Point
//=====================================

class Point{
public:
	enum {
		minX = 0,
		maxX = 79,
		minY = 3,
		maxY = 23
	};

	int x;
	int y;
	Point(int x, int y) :x(x), y(y){
	}
	Point(){ //Construct point with random x, y values
		x = (rand() % 80);
		y = (rand() % 21 + 3);
	}
	
	//Compare point x and y values
	bool comparePoints(Point const &otherPoint){
		return (x == otherPoint.x && y == otherPoint.y);
	}
};

#endif
