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
// 2015-05-26	  Dror Moyal		Added operators overload and distance function

#ifndef __POINT_H
#define __POINT_H

#include <iostream>
#include <cmath>
#include <algorithm> 

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

	// +++++++++++++++++++++++++++++++++++++++++++++++++
	// "NEW CODE EX3, author=Dror Moyal, date=2015-05-26
	// +++++++++++++++++++++++++++++++++++++++++++++++++

	// overload operator =
	Point& operator=(const Point& p){
		if (this != &p){
			this->x = p.x;
			this->y = p.y;
		}
		return *this;
	}

	// overload operator ==
	bool operator==(const Point& p){
		return (this->x == p.x && this->y == p.y);
	}

	// overload operator !=
	bool operator!=(const Point& p){
		return (this->x != p.x || this->y != p.y);
	}
	
	// return distance between 2 points
	unsigned int pointDistance(const Point& p){
		unsigned int disX, disY;
		disX = min(abs(x - p.x), min(x, p.x) + 1 + (79 - max(x, p.x)));
		disY = min(abs(y - p.y), min(y, p.y) + 1 + (23 - max(y, p.y))-3);
		return disX + disY;
	}

	//+++++++++++++++++++++
	// END of NEW CODE EX3
	//+++++++++++++++++++++
};

#endif
