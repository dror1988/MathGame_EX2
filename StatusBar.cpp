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
		cout<<"Player-@ ,Lives:"<<p1.getLives()<<" ,Score:"<<p1.getScore();
		gotoxy(28,0);
		cout<<"|        Time:"<<timeLeft;
		gotoxy(51,0);
		cout<<"| Player-# ,Lives:"<<p2.getLives()<<" ,Score:"<<p2.getScore();
	}

	{ //Print 2nd Line in Status Bar
		if (currentLevel <= 20){
			gotoxy(0, 1);
			cout << "Targil: " << p1.getExercise();
			gotoxy(51, 1);
			cout << "| Targil: " << p2.getExercise();
		}
		else{
			gotoxy(0, 1);
			cout << "Targil: " << p1.getAdvExercise();
			gotoxy(51, 1);
			cout << "| Targil: " << p2.getAdvExercise();
		}
		gotoxy(28, 1);
		cout << "|        Level:" << currentLevel;
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
		gotoxy(69,0);
		cout<<p2.getLives();
	}
	setTextColor(WHITE);
}

//===================================
//updates and prints time left value
//===================================
void StatusBar::updateTimeLeft(){
	setTextColor(LIGHTCYAN);
	gotoxy(42,0);
	cout<< "   ";
	gotoxy(42,0);
	cout<<timeLeft;
	setTextColor(WHITE);
}


//new code EX2
//===================================
//updates and prints player life value
//===================================
void StatusBar::updatePlayerExercise(unsigned int playerNumber){
	setTextColor(LIGHTCYAN);
	if (playerNumber == 1){
		gotoxy(8, 1);
		cout << p1.getAdvExercise();
	}
	else if (playerNumber == 2){
		gotoxy(61, 1);
		cout << p2.getAdvExercise();
	}
	setTextColor(WHITE);
}
//end new code EX2

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
