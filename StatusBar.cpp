//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// StatusBar.cpp
// -----------
// This file declares a class presents and updates the first 3 rows in the play screen.
//
// Author: Dror Moyal
// First version: 2015-04-11
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-11     Dror Moyal      implemented the status bar class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX1, author=Dror Moyal, date=2015-04-11
// +++++++++++++++++++++++++++++++++++++++++++++++++


#include "StatusBar.h"

void StatusBar::drawStatusBar(){
	setTextColor(LIGHTCYAN);
	{ //Print 1st Line in Status Bar
		gotoxy(0,0);
		cout << "Player-@ ,Lives:" << p1.getLives() << " ,Score:" << p1.getScore();
		gotoxy(33,0);
		cout<<"|  Time:"<<timeLeft;
		gotoxy(46,0);
		cout << "| Player-# ,Lives:" << p2.getLives() << " ,Score:" << p2.getScore();
	}

	{ //Print 2nd Line in Status Bar
		if (currentLevel <= 20){
			gotoxy(0, 1);
			cout << "Shots: " << p1.getShotsCounter()<<" ,Targil: " << p1.getExercise();
			gotoxy(46, 1);
			cout << "| Shots: " << p2.getShotsCounter() << " ,Targil: " << p2.getExercise();
		}
		else{
			gotoxy(0, 1);
			cout << "Shots: " << p1.getShotsCounter() << " ,Targil: " << p1.getAdvExercise();
			gotoxy(46, 1);
			cout << "| Shots: " << p2.getShotsCounter() << " ,Targil: " << p2.getAdvExercise();
		}
		gotoxy(33, 1);
		cout << "|  Level:" << currentLevel;
	}

	{
		gotoxy(0,2);
		cout<<"================================================================================";
	}

	setTextColor(WHITE);

}

//===================================
//updates and prints player life value
//===================================
void StatusBar::updatePlayerLife(unsigned int playerNumber){
	setTextColor(LIGHTCYAN);
	if (playerNumber==1){
		gotoxy(16,0);
		cout<<p1.getLives();
	}
	else if (playerNumber==2){
		gotoxy(64,0);
		cout<<p2.getLives();
	}
	setTextColor(WHITE);
}

//===================================
//updates and prints time left value
//===================================
void StatusBar::updateTimeLeft(){
	setTextColor(LIGHTCYAN);
	gotoxy(41,0);
	cout<< "   ";
	gotoxy(41,0);
	cout<<timeLeft;
	setTextColor(WHITE);
}


// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX2, author=Dror Moyal, date=2015-05-09
// +++++++++++++++++++++++++++++++++++++++++++++++++

//===================================
//updates and prints player exercise
//===================================
void StatusBar::updatePlayerExercise(unsigned int playerNumber){
	setTextColor(LIGHTCYAN);
	if (playerNumber == 1){
		gotoxy(18, 1);
		cout << p1.getAdvExercise();
	}
	else if (playerNumber == 2){
		gotoxy(66, 1);
		cout << p2.getAdvExercise();
	}
	setTextColor(WHITE);
}

//===================================
//updates and prints player shots
//===================================
void StatusBar::updatePlayerShots(unsigned int playerNumber){
	setTextColor(LIGHTCYAN);
	if (playerNumber == 1){
		gotoxy(7, 1);
		cout << p1.getShotsCounter();
	}
	else if (playerNumber == 2){
		gotoxy(55, 1);
		cout << p2.getShotsCounter();
	}
	setTextColor(WHITE);
}
//+++++++++++++++++++++
// END of NEW CODE EX2
//+++++++++++++++++++++

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
