//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// shotArray.h
// -----------
// This file declares a class to manage the creation, addition to and deletion of shots array
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
// 2015-04-10    Maya Bugana     implemented the shotArray class
// 2015-04-13	 Dror Mpyal      Adding functions

#ifndef _SHOTS_ARRAY_H
#define _SHOTS_ARRAY_H

#include "Shot.h"
#include <stdio.h>
#include <iostream>

class shotsArray{
	unsigned int size;
	Shot* Arr[30];
public:
	// shotsArray constructor
	shotsArray();
	// shotsArray cdestructor
	~shotsArray();
	// shotsArray copy constructor
	shotsArray(const shotsArray& a) : size(a.size)
	{
		*Arr = new Shot;
		**Arr = **(a.Arr);
	}
	
	// size getter
	unsigned int getSize();
	// Returns a shot in array index
	Shot* getShotInArr(int i);
	// size setter
	unsigned int setSize(unsigned int newSize);
	// inits the array 
	void initArr();
	// print the shots array
	void printShots() const;
	// control the movement of all shots in array
	void move();
	// add shot to the array
	int addShot(Point shotPosition, Direction::VALUE shotDirection);
	// delete shot in index i
	void delShot(int i);
	// swap between 2 shots
	void swap(Shot* &a, Shot* &b);
};

#endif
