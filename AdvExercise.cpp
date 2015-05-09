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

void AdvExercise::resetMinNubers() {
	int minNum=0;

	minNum=min(min(arrNum[0],arrNum[1]),min(arrNum[2],arrNum[3]));

	for (int i=0;i<4; ++i)
		if (arrNum[i]==minNum){
			arrNum[i]=10001;
			i=4;
		}

	minNum=min(min(arrNum[0],arrNum[1]),min(arrNum[2],arrNum[3]));

	for (int i=0;i<4; ++i)
		if (arrNum[i]==minNum){
			arrNum[i]=10001;
			i=4;
		}

}

void AdvExercise::createAdvExerciseString(){
	// place to store itoa_s result
	char strNumber[5]="";

	// create the exercise string
	for (int i=0; i<4; ++i){
		if (arrNum[i]==10001)
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

bool AdvExercise::solveExercise(int tryNum) const {
	double tmpArr[4];
	int varIndex=0;
	double result;

	// copy to temp arr
	for (int i=0; i<4; ++i)
		tmpArr[i]=(double)arrNum[i];
	
	// set tryNum in the correct place
	for (int i=0; i<4; ++i)
		if (tmpArr[i]==10001){
			tmpArr[i]=(double)tryNum;
			i=4;
		}

	// find the index of the missing variable
	for (int i=0; i<4; ++i)
		if (tmpArr[i]==(double)10001){
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
				result=tmpArr[0]+tmpArr[1]+tmpArr[3];
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

	if (result<=21 && result>=1 && result==(int)result)
				return true;
			else
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
AdvExercise::AdvExercise(int currentLvl){
	//temp variable to help and choose the "+,-,/,*" according to rand function
	int chooseOper1 = rand() % 4;
	int chooseOper2 = rand() % 4;

	// randomly choose 3 numbers using 10 + current level
	for (int i=0; i<3; ++i)	
		arrNum[i] = rand() % (21) + 1;
	arrNum[3]=10001;

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

		// hide lowest numbers
		resetMinNubers();
		// create the exercise string
		createAdvExerciseString();

		break;
	// case the first operator should be -
	case 1:
		oper1 = '-'; // ==========================================> Continue here!!!!

		switch (chooseOper2){
		// case the second operator should be +
		case 0:
			oper2 = '+';
			arrNum[3]=arrNum[0];
			arrNum[0]=arrNum[3]+arrNum[1]+arrNum[2];
			break;
		// case the operator operator should be -
		case 1:
			oper2 = '-';
			arrNum[3]=arrNum[0]-arrNum[1]-arrNum[2];
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
			// arrNum[1]=(res/arrNum[2])
			arrNum[1]=arrNum[1]*arrNum[2];
			arrNum[3]=arrNum[0]-(arrNum[1]/arrNum[2]);
			break;
		default:
			break;
		}

		// hide lowest numbers
		resetMinNubers();
		// create the exercise string
		createAdvExerciseString();

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
			arrNum[3]=(arrNum[0]*arrNum[1])-arrNum[2];
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

		// hide lowest numbers
		resetMinNubers();
		// create the exercise string
		createAdvExerciseString();

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
			arrNum[0]=arrNum[0]*arrNum[1];
			arrNum[3]=(arrNum[0]/arrNum[1])-arrNum[2];
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

		// hide lowest numbers
		resetMinNubers();
		// create the exercise string
		createAdvExerciseString();

		break;
	default:
		break;
	}

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
bool AdvExercise::isAdvExerciseComplete(int tryNum){
	return solveExercise(tryNum);
}

//+++++++++++++++++++++
// END of NEW CODE EX2
//+++++++++++++++++++++
