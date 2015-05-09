//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AdvExercise.h
// -----------
// This file declares a class to manage an exercise. 
//
// Author: Dror Moyal
// First version: 2015-05-09
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-05-09     Dror Moyal      implemented the AdvExecise class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX2, author=Dror Moyal, date=2015-05-09
// +++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef __ADV_EXERCISE_H
#define __ADV_EXERCISE_H

#include <stdlib.h>
#include <string>
#include <algorithm>
#include "io_utils.h"

using namespace std;

//=====================================
// this class implements the use of an 
// adnaced exercise or "targil"
//=====================================
class AdvExercise{
	int arrNum[4];
	unsigned char oper1;
	unsigned char oper2;
	string strAdvExercise;

	void resetMinNubers();
	void createAdvExerciseString();
	bool solveExercise(int tryNum) const;

public:
	// exercise constructor
	AdvExercise(int currentLvl);

	// "targil" getter
	string getAdvExercise();
	// check if a number completes the exercise
	bool isAdvExerciseComplete(int tryNum);
};

#endif

//+++++++++++++++++++++
// END of NEW CODE EX2
//+++++++++++++++++++++
