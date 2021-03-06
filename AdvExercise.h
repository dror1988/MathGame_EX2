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
	unsigned int arrNum[4];
	unsigned char oper1;
	unsigned char oper2;
	unsigned int missingVars;
	string strAdvExercise;

	void resetMinNubers();
	void createAdvExerciseString();
	bool checkIfPossible(unsigned int tryNum) const;
	bool checkIfComplete(unsigned int tryNum) const;
	// const variables
	const static unsigned int EMPTY_CELL = 10001;
	const static unsigned int MIN_NUM = 1;
	const static unsigned int MAX_NUM = 21;
public:
	// exercise constructor
	AdvExercise(unsigned int currentLvl);

	// "targil" getter
	string getAdvExercise();
	// check if a number is one of the possible solutions of the exercise
	bool isPossibleSolution(unsigned int tryNum);
	// check if a number completes the exercise
	bool isAdvExerciseComplete(unsigned int tryNum);
	// missing vars getter
	unsigned int getMissingVars();
};

#endif
