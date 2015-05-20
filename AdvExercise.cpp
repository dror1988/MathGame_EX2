//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AdvExercise.cpp
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
// 2015-05-09    Dror Moyal      implemented the AdvExecise class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX2, author=Dror Moyal, date=2015-05-09
// +++++++++++++++++++++++++++++++++++++++++++++++++

#include "AdvExercise.h"

//===================================
// Function that set the to lowest 
// numbers to EMPTY_CELL
//===================================
void AdvExercise::resetMinNubers() {
	unsigned int minNum = 0;

	minNum=min(min(arrNum[0],arrNum[1]),min(arrNum[2],arrNum[3]));

	for (int i=0;i<4; ++i)
		if (arrNum[i]==minNum){
			arrNum[i]=EMPTY_CELL;
			i=4;
		}

	minNum=min(min(arrNum[0],arrNum[1]),min(arrNum[2],arrNum[3]));

	for (int i=0;i<4; ++i)
		if (arrNum[i]==minNum){
			arrNum[i]=EMPTY_CELL;
			i=4;
		}

}

//===================================
// Function that creates the advanced 
// exercise string
//===================================
void AdvExercise::createAdvExerciseString(){
	// place to store itoa_s result
	char strNumber[5]="";
	
	strAdvExercise = "";

	// create the exercise string
	for (int i=0; i<4; ++i){
		if (arrNum[i]==EMPTY_CELL)
			strAdvExercise+="_";
		else{
			_itoa_s(arrNum[i], strNumber, sizeof(strNumber), 10);
			strAdvExercise+=strNumber;
		}

		switch(i){
		case 0:
			strAdvExercise+=oper1;
			break;
		case 1:
			strAdvExercise+=oper2;
			break;
		case 2:
			strAdvExercise+='=';
		default:
			break;
		}
	}
}

//===================================
// Function that verifies if a given
// number is a possible solution
//===================================
bool AdvExercise::checkIfPossible(unsigned int tryNum) const {
	double tmpArr[4];
	int varIndex=0;
	double result;

	// copy to temp arr
	for (int i=0; i<4; ++i)
		tmpArr[i]=(double)arrNum[i];
	
	// set tryNum in the correct place
	for (int i=0; i<4; ++i)
		if (tmpArr[i]==EMPTY_CELL){
			tmpArr[i]=(double)tryNum;
			i=4;
		}

	// find the index of the missing variable
	for (int i=0; i<4; ++i)
		if (tmpArr[i]==(double)EMPTY_CELL){
			varIndex=i;
			i=4;
		}

	switch(oper1){
	case '+':
		switch(oper2){
		case '+':
			if (varIndex==3)
				result=tmpArr[0]+tmpArr[1]+tmpArr[2];
			else if (varIndex==2)
				result=tmpArr[3]-tmpArr[0]-tmpArr[1];
			else
				result=tmpArr[3]-tmpArr[0]-tmpArr[2];
			break;
		case '*':
			if (varIndex==3)
				result=tmpArr[0]+(tmpArr[1]*tmpArr[2]);
			else if (varIndex==2)
				result=(tmpArr[3]-tmpArr[0])/tmpArr[1];
			else
				result=(tmpArr[3]-tmpArr[0])/tmpArr[2];
			break;
		case '-':
			if (varIndex==3)
				result=tmpArr[0]+tmpArr[1]-tmpArr[2];
			else if (varIndex==2)
				result=tmpArr[0]+tmpArr[1]-tmpArr[3];
			else
				result=tmpArr[3]-tmpArr[0]+tmpArr[2];
			break;
		case '/':
			if (varIndex==3)
				result=tmpArr[0]+(tmpArr[1]/tmpArr[2]);
			else if (varIndex==2)
				result=tmpArr[1]/(tmpArr[3]-tmpArr[0]);
			else
				result=(tmpArr[3]-tmpArr[0])*tmpArr[2];
			break;
		}
		break;
	case '*':
		switch(oper2){
		case '+':
			if (varIndex==3)
				result=(tmpArr[0]*tmpArr[1])+tmpArr[2];
			else if (varIndex==2)
				result=tmpArr[3]-(tmpArr[0]*tmpArr[1]);
			else
				result=(tmpArr[3]-tmpArr[2])/tmpArr[0];
			break;
		case '*':
			if (varIndex==3)
				result=tmpArr[0]*(tmpArr[1]*tmpArr[2]);
			else if (varIndex==2)
				result=tmpArr[3]/(tmpArr[0]*tmpArr[1]);
			else
				result=tmpArr[3]/(tmpArr[0]*tmpArr[2]);
			break;
		case '-':
			if (varIndex==3)
				result=(tmpArr[0]*tmpArr[1])-tmpArr[2];
			else if (varIndex==2)
				result=(tmpArr[0]*tmpArr[1])-tmpArr[3];
			else
				result=(tmpArr[3]+tmpArr[2])/tmpArr[0];
			break;
		case '/':
			if (varIndex==3)
				result=(tmpArr[0]*tmpArr[1])/tmpArr[2];
			else if (varIndex==2)
				result=(tmpArr[0]*tmpArr[1])/tmpArr[3];
			else
				result=(tmpArr[3]*tmpArr[2])/tmpArr[0];
			break;
		}
		break;
	case '-':
		switch(oper2){
		case '+':
			if (varIndex==3)
				result=tmpArr[0]-tmpArr[1]+tmpArr[2];
			else if (varIndex==2)
				result=tmpArr[3]-tmpArr[0]+tmpArr[1];
			else
				result=tmpArr[0]+tmpArr[2]-tmpArr[0];
			break;
		case '*':
			if (varIndex==3)
				result=tmpArr[0]-(tmpArr[1]*tmpArr[2]);
			else if (varIndex==2)
				result=(tmpArr[0]-tmpArr[3])/tmpArr[1];
			else
				result=(tmpArr[0]-tmpArr[3])/tmpArr[2];
			break;
		case '-':
			if (varIndex==3)
				result=tmpArr[0]-tmpArr[1]-tmpArr[2];
			else if (varIndex==2)
				result=tmpArr[0]-tmpArr[1]-tmpArr[3];
			else
				result=tmpArr[0]-tmpArr[2]-tmpArr[3];
			break;
		case '/':
			if (varIndex==3)
				result=tmpArr[0]-(tmpArr[1]/tmpArr[2]);
			else if (varIndex==2)
				result=(tmpArr[0]-tmpArr[3])/tmpArr[1];
			else
				result=(tmpArr[0]-tmpArr[3])/tmpArr[2];
			break;
		}
		break;
	case '/':
		switch(oper2){
		case '+':
			if (varIndex==3)
				result=(tmpArr[0]/tmpArr[1])+tmpArr[2];
			else if (varIndex==2)
				result=tmpArr[3]-(tmpArr[0]/tmpArr[1]);
			else
				result=tmpArr[0]-(tmpArr[3]-tmpArr[2]);
			break;
		case '*':
			if (varIndex==3)
				result=(tmpArr[0]/tmpArr[1])*tmpArr[2];
			else if (varIndex==2)
				result=tmpArr[3]*(tmpArr[0]/tmpArr[1]);
			else
				result=(tmpArr[0]*tmpArr[2])/tmpArr[3];
			break;
		case '-':
			if (varIndex==3)
				result=(tmpArr[0]/tmpArr[1])-tmpArr[2];
			else if (varIndex==2)
				result=(tmpArr[0]/tmpArr[1])-tmpArr[3];
			else
				result=tmpArr[0]/(tmpArr[2]-tmpArr[3]);
			break;
		case '/':
			if (varIndex==3)
				result=(tmpArr[0]/tmpArr[1])/tmpArr[2];
			else if (varIndex==2)
				result=(tmpArr[0]/tmpArr[1])/tmpArr[3];
			else
				result=tmpArr[0]/(tmpArr[3]*tmpArr[2]);
			break;
		}
		break;
	}

	if (result <= MAX_NUM && result >= MIN_NUM && result == (int)result)
				return true;
			else
				return false;
}

//===================================
// Function that verifies if a given
// number completes the exercise
//===================================
bool AdvExercise::checkIfComplete(unsigned int tryNum) const{
	int varIndex = 0;
	//double result;

	// find the index of the missing variable
	for (int i = 0; i<4; ++i)
	if (arrNum[i] == EMPTY_CELL){
		varIndex = i;
		i = 4;
	}

	switch (oper1){
	case '+':
		switch (oper2){
		case '+':
			if (varIndex == 3)
				return (tryNum == arrNum[0] + arrNum[1] + arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == arrNum[3] - arrNum[0] - arrNum[1]);
			else
				return (tryNum == arrNum[3] - arrNum[0] - arrNum[2]);
			break;
		case '*':
			if (varIndex == 3)
				return (tryNum == arrNum[0] + (arrNum[1] * arrNum[2]));
			else if (varIndex == 2)
				return (tryNum == (arrNum[3] - arrNum[0]) / arrNum[1]);
			else
				return (tryNum == (arrNum[3] - arrNum[0]) / arrNum[2]);
			break;
		case '-':
			if (varIndex == 3)
				return (tryNum == arrNum[0] + arrNum[1] - arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == arrNum[0] + arrNum[1] + arrNum[3]);
			else
				return (tryNum == arrNum[3] - arrNum[0] + arrNum[2]);
			break;
		case '/':
			if (varIndex == 3)
				return (tryNum == arrNum[0] + (arrNum[1] / arrNum[2]));
			else if (varIndex == 2)
				return (tryNum == arrNum[1] / (arrNum[3] - arrNum[0]));
			else
				return (tryNum == (arrNum[3] - arrNum[0])*arrNum[2]);
			break;
		}
		break;
	case '*':
		switch (oper2){
		case '+':
			if (varIndex == 3)
				return (tryNum == (arrNum[0] * arrNum[1]) + arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == arrNum[3] - (arrNum[0] * arrNum[1]));
			else
				return (tryNum == (arrNum[3] - arrNum[2]) / arrNum[0]);
			break;
		case '*':
			if (varIndex == 3)
				return (tryNum == arrNum[0] * (arrNum[1] * arrNum[2]));
			else if (varIndex == 2)
				return (tryNum == arrNum[3] / (arrNum[0] * arrNum[1]));
			else
				return (tryNum == arrNum[3] / (arrNum[0] * arrNum[2]));
			break;
		case '-':
			if (varIndex == 3)
				return (tryNum == (arrNum[0] * arrNum[1]) - arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == (arrNum[0] * arrNum[1]) - arrNum[3]);
			else
				return (tryNum == (arrNum[3] + arrNum[2]) / arrNum[0]);
			break;
		case '/':
			if (varIndex == 3)
				return (tryNum == (arrNum[0] * arrNum[1]) / arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == (arrNum[0] * arrNum[1]) / arrNum[3]);
			else
				return (tryNum == (arrNum[3] * arrNum[2]) / arrNum[0]);
			break;
		}
		break;
	case '-':
		switch (oper2){
		case '+':
			if (varIndex == 3)
				return (tryNum == arrNum[0] - arrNum[1] + arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == arrNum[3] - arrNum[0] + arrNum[1]);
			else
				return (tryNum == arrNum[0] + arrNum[2] - arrNum[0]);
			break;
		case '*':
			if (varIndex == 3)
				return (tryNum == arrNum[0] - (arrNum[1] * arrNum[2]));
			else if (varIndex == 2)
				return (tryNum == (arrNum[0] - arrNum[3]) / arrNum[1]);
			else
				return (tryNum == (arrNum[0] - arrNum[3]) / arrNum[2]);
			break;
		case '-':
			if (varIndex == 3)
				return (tryNum == arrNum[0] - arrNum[1] - arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == arrNum[0] - arrNum[1] - arrNum[3]);
			else
				return (tryNum == arrNum[0] - arrNum[2] - arrNum[3]);
			break;
		case '/':
			if (varIndex == 3)
				return (tryNum == arrNum[0] - (arrNum[1] / arrNum[2]));
			else if (varIndex == 2)
				return (tryNum == (arrNum[0] - arrNum[3]) / arrNum[1]);
			else
				return (tryNum == (arrNum[0] - arrNum[3]) / arrNum[2]);
			break;
		}
		break;
	case '/':
		switch (oper2){
		case '+':
			if (varIndex == 3)
				return (tryNum == (arrNum[0] / arrNum[1]) + arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == arrNum[3] - (arrNum[0] / arrNum[1]));
			else
				return (tryNum == arrNum[0] - (arrNum[3] - arrNum[2]));
			break;
		case '*':
			if (varIndex == 3)
				return (tryNum == (arrNum[0] / arrNum[1])*arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == arrNum[3] * (arrNum[0] / arrNum[1]));
			else
				return (tryNum == (arrNum[0] * arrNum[2]) / arrNum[3]);
			break;
		case '-':
			if (varIndex == 3)
				return (tryNum == (arrNum[0] / arrNum[1]) - arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == (arrNum[0] / arrNum[1]) - arrNum[3]);
			else
				return (tryNum == arrNum[0] / (arrNum[2] - arrNum[3]));
			break;
		case '/':
			if (varIndex == 3)
				return (tryNum == (arrNum[0] / arrNum[1]) / arrNum[2]);
			else if (varIndex == 2)
				return (tryNum == (arrNum[0] / arrNum[1]) / arrNum[3]);
			else
				return (tryNum == arrNum[0] / (arrNum[3] * arrNum[2]));
			break;
		}
		break;
	default:
		return false;
	}

	return false;
}

//==========================================================
// in the constructor we create an exercise that will be the 
// player goal to finish. we do it by randomly choose 3
// numbers and an 2 arithmetic operators. using the data we get
// we build the exercise according to the expected logic in 
// EX2 instructions and create a string that will be used to 
// present the exercise to the players
//==========================================================
AdvExercise::AdvExercise(unsigned int currentLvl){
	//temp variable to help and choose the "+,-,/,*" according to rand function
	int chooseOper1 = rand() % 4;
	int chooseOper2 = rand() % 4;

	// randomly choose 3 numbers in the range of 1-21
	for (int i=0; i<3; ++i)	
		arrNum[i] = rand() % (21) + 1;
	arrNum[3]=EMPTY_CELL;

	missingVars = 2;

	// create an exercise according to the operator
	switch (chooseOper1){

	// case the first operator should be +
	case 0:
		oper1 = '+';
		switch (chooseOper2){
		// case the second operator should be +
		case 0:
			oper2 = '+';
			arrNum[3]=arrNum[0]+arrNum[1]+arrNum[2];
			break;
		// case the operator operator should be -
		case 1:
			oper2 = '-';
			arrNum[3]=arrNum[2];
			arrNum[2]=arrNum[1];
			arrNum[1]=arrNum[3]+arrNum[2]-arrNum[0];
			break;
		// case the operator operator should be *
		case 2:
			oper2 = '*';
			arrNum[3]=arrNum[0]+(arrNum[1]*arrNum[2]);
			break;
		// case the operator operator should be /
		case 3:
			oper2 = '/';
			// arrNum[1]=(res/arrNum[2])
			arrNum[1]=arrNum[1]*arrNum[2];
			arrNum[3]=arrNum[0]+(arrNum[1]/arrNum[2]);
			break;
		default:
			break;
		}
		break;
	// case the first operator should be -
	case 1:
		oper1 = '-'; // ==========================================> Continue here!!!!

		switch (chooseOper2){
		// case the second operator should be +
		case 0:
			oper2 = '+';
			arrNum[0] = arrNum[0] + arrNum[1];
			arrNum[3]=arrNum[0]-arrNum[1]+arrNum[2];
			break;
		// case the operator operator should be -
		case 1:
			oper2 = '-';
			arrNum[3] = arrNum[1];
			arrNum[1] = arrNum[0];
			arrNum[0] = arrNum[0] + arrNum[2] + arrNum[3];
			break;
		// case the operator operator should be *
		case 2:
			oper2 = '*';
			arrNum[3]=arrNum[0];
			arrNum[0]=arrNum[3]+(arrNum[1]*arrNum[2]);
			break;
		// case the operator operator should be /
		case 3:
			oper2 = '/';
			arrNum[3] = arrNum[0];
			// arrNum[1]=(res/arrNum[2])
			arrNum[1]=arrNum[1]*arrNum[2];
			arrNum[0]=arrNum[3]+(arrNum[1]/arrNum[2]);
			break;
		default:
			break;
		}
		break;
	// case the first operator should be *
	case 2:
		oper1 = '*';

		switch (chooseOper2){
		// case the second operator should be +
		case 0:
			oper2 = '+';
			arrNum[3]=(arrNum[0]*arrNum[1])+arrNum[2];
			break;
		// case the operator operator should be -
		case 1:
			oper2 = '-';
			arrNum[3] = arrNum[1];
			arrNum[1]=arrNum[2]+arrNum[3];
			arrNum[3] = (arrNum[0] * arrNum[1]) - arrNum[2];
			break;
		// case the operator operator should be *
		case 2:
			oper2 = '*';
			arrNum[3]=(arrNum[0]*arrNum[1])*arrNum[2];
			break;
		// case the operator operator should be /
		case 3:
			oper2 = '/';
			// arrNum[1]=(res/arrNum[2])
			arrNum[1]=arrNum[1]*arrNum[2];
			arrNum[3]=arrNum[0]*(arrNum[1]/arrNum[2]);
			break;
		default:
			break;
		}
		break;
	// case the first operator should be /
	case 3:
		oper1 = '/';

		switch (chooseOper2){
		// case the second operator should be +
		case 0:
			oper2 = '+';
			// arrNum[0]=(res/arrNum[1])
			arrNum[0]=arrNum[0]*arrNum[1];
			arrNum[3]=(arrNum[0]/arrNum[1])+arrNum[2];
			break;
		// case the operator operator should be -
		case 1:
			oper2 = '-';
			// arrNum[0]=(res/arrNum[1])
			arrNum[3]=arrNum[1];
			arrNum[1] = arrNum[2] + arrNum[3];
			arrNum[0] = arrNum[0] * arrNum[1];
			break;
		// case the operator operator should be *
		case 2:
			oper2 = '*';
			// arrNum[0]=(res/arrNum[1])
			arrNum[0]=arrNum[0]*arrNum[1];
			arrNum[3]=(arrNum[0]/arrNum[1])*arrNum[2];
			break;
		// case the operator operator should be /
		case 3:
			oper2 = '/';
			arrNum[3]=arrNum[2];
			arrNum[2]=arrNum[1];
			arrNum[1]=arrNum[0];
			// arrNum[2]=(arrNum[0]/res)
			arrNum[0]=arrNum[3]*arrNum[2];
			arrNum[0]=arrNum[0]*arrNum[1];
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	// hide lowest numbers
	resetMinNubers();
	// create the exercise string
	createAdvExerciseString();

}

//======================
// implementation of the
// exercise getter
//======================
string AdvExercise::getAdvExercise(){
	return strAdvExercise;
}

//====================================
// when user eats a number, check if 
// the number completes the exercise
//====================================
bool AdvExercise::isPossibleSolution(unsigned int tryNum){
	if (checkIfPossible(tryNum) == true){
		for (int i = 0; i<4; ++i)
		if (arrNum[i] == EMPTY_CELL){
			arrNum[i] = tryNum;
			createAdvExerciseString();
			missingVars = 1;
			i = 4;
		}
		return true;
	}

	return false;
}

bool AdvExercise::isAdvExerciseComplete(unsigned int tryNum){
	return checkIfComplete(tryNum);
}

unsigned int AdvExercise::getMissingVars(){
	return missingVars;
}

//+++++++++++++++++++++
// END of NEW CODE EX2
//+++++++++++++++++++++
