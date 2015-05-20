//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// TheMathGame.cpp
// -----------
// This file declares a class to implement TheMathGame as expected
// Author: Dror Moyal
// First version: 2015-04-11
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-11     Dror Moyal      implemented the TheMathGame class
// 2015-05-12	  Maya Bugana	  Add Shootings in subIteration
// 2015-05-13     Dror Moyal      Adding logic and fix bugs

// In the file itself, add above each change/addition a remark saying: "NEW CODE EX1, author=<name>, date=<YYYY-MM-DD>"
// and close it at the end with a remark saying "END of NEW CODE EX1" 
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX1, author=Dror Moyal, date=2015-04-11
// +++++++++++++++++++++++++++++++++++++++++++++++++

//================================================================================================
// This claas will inherint from ISpecificGame and will implement the abstract functions
// In addition we added 2 functions to help and manage the game by printing a game "Snap shot"
// and reseting the game neccesary variables for a totaly new game
//================================================================================================

#include "TheMathGame.h"


//=================================================
// Printing a snaphot of the current game
//=================================================
void TheMathGame::printCurrentScreen(){
	clear_screen();
	setTextColor(WHITE);
	stBar.drawStatusBar();
	myScreen.printMatrix();
	playShooting.printShots();
}

//=================================================
// Reset the game necessary variables for a new game
//=================================================
void TheMathGame::resetAll(){
	player1.setScore(0);
	player2.setScore(0);
	currentLevel = 0;
}

//=================================================
// Check if a level is done and print a message 
// regarding  the way the level was ended
//=================================================
bool TheMathGame::isLevelDone(){
	// at least 1 player is still alive
	bool alivePlayer = player1.isPlayerAlive() || player2.isPlayerAlive();
	// one of the players or the two of them are done
	bool playerNotDone = player1.getPlayerDone() || player2.getPlayerDone();

	// in case time is not up, at least 1 player is a live and players are not done yet
	if (clockTicksCurrentLevel < CLOCK_TICKS_PER_LEVEL && alivePlayer && !playerNotDone)
		return false;
	else{
		clear_screen();
		setTextColor(YELLOW);

		//=======================================================
		// according to the reason of ending the level, print
		// the appropriet message to the screen
		//=======================================================

		// case the times run out
		if (clockTicksCurrentLevel >= CLOCK_TICKS_PER_LEVEL){
			gotoxy(33, 12);
			cout << "Time is up!!!";
			gotoxy(29, 13);
			cout << "Try better next time!!";
		}
		// case both players are dead
		else if (!alivePlayer){
			gotoxy(28, 12);
			cout << "Both Players are dead!!!";
			gotoxy(29, 13);
			cout << "Try better next time!!";
		}
		// case that player 1 is done and player 2 not
		else if (player1.getPlayerDone() && !player2.getPlayerDone()){
			gotoxy(33, 12);
			cout << "Player1 WIN!!";
		}
		// case that player 2 is done and player 1 not
		else if (player2.getPlayerDone() && !player1.getPlayerDone()){
			gotoxy(33, 12);
			cout << "Player2 WIN!!";
		}
		// case that bothe players finished at the same time
		else{
			gotoxy(35, 12);
			cout << "Its a TIE";
		}

		setTextColor(WHITE);
		return true;
	}
}

//=================================================
// Check if there are more levels to play
//=================================================
bool TheMathGame::hasNextLevel()const{
	// check if reached to max level
	if (currentLevel < MAX_LEVEL)
		return true;
	else
		return false;
}

//=================================================
// setting up all the necessary things for the 
// start of a new level
//=================================================
void TheMathGame::startLevel(int level){
	clear_screen();
	currentLevel = level;
	clockTicksCurrentLevel = 0;

	// setting up player1 for a new level
	player1.setLives(3);
	player1.setPosition(Point(10, 9));
	player1.changeDirection(Direction::RIGHT);
	// +++++++++++++++++++++++++++++++++++++++++++++++++
	// "NEW CODE EX2, author=Dror Moyal, date=2015-05-09
	// +++++++++++++++++++++++++++++++++++++++++++++++++
	if (currentLevel >= 1 && currentLevel < 20){
		player1.resetExercise();
		player1.createExercise(currentLevel);
	}
	else if (currentLevel == 20){
		player1.resetExercise();
		player1.createAdvExercise(currentLevel);
	}
	else{
		player1.resetAdvExercise();
		player1.createAdvExercise(currentLevel);
	}
	//+++++++++++++++++++++
	// END of NEW CODE EX2
	//+++++++++++++++++++++
	player1.resetPlayerAlive();
	player1.resetPlayerDone();
	player1.setShotsCounter(5);

	// setting up player2 for a new level
	player2.setLives(3);
	player2.setPosition(Point(70, 9));
	player2.changeDirection(Direction::LEFT);
	// +++++++++++++++++++++++++++++++++++++++++++++++++
	// "NEW CODE EX2, author=Dror Moyal, date=2015-05-09
	// +++++++++++++++++++++++++++++++++++++++++++++++++
	if (currentLevel >= 1 && currentLevel < 20){
		player2.resetExercise();
		player2.createExercise(currentLevel);
	}
	else if (currentLevel == 20){
		player2.resetExercise();
		player2.createAdvExercise(currentLevel);
	}
	else{
		player2.resetAdvExercise();
		player2.createAdvExercise(currentLevel);
	}
	//+++++++++++++++++++++
	// END of NEW CODE EX2
	//+++++++++++++++++++++
	player2.resetPlayerAlive();
	player2.resetPlayerDone();
	player2.setShotsCounter(5);

	//settinp up status bar for a new level
	stBar.setTimeLeft(300);
	stBar.setCurrentLevel(currentLevel);
	stBar.drawStatusBar();

	// erasing the screen matrix
	myScreen.eraseMatrix();

	// erase all bullets from screen and cleans the array
	playShooting.initArr();
}

//=================================================
// this is the actual game itteration. in this 
// we move the players on the screen, creates numbers
// and all other actions that are used in
// a game itteration
//=================================================
void TheMathGame::doIteration(const list<char>& keyHits){
	// counting seconds in a leve and printing
	// the time left for each level
	++clockTicksCurrentLevel;
	if (clockTicksCurrentLevel % 5 == 0){
		stBar.decTimeLeft();
		stBar.updateTimeLeft();

		// +++++++++++++++++++++++++++++++++++++++++++++++++
		// "NEW CODE EX2, author=Maya Bugana, date=2015-05-12
		// +++++++++++++++++++++++++++++++++++++++++++++++++
		//adding shots to the player every 200 clocks cycles
		if (clockTicksCurrentLevel % 200 == 0){
			player1.setShotsCounter(player1.getShotsCounter() + 1);
			stBar.updatePlayerShots(1);
			player2.setShotsCounter(player2.getShotsCounter() + 1);
			stBar.updatePlayerShots(2);
		}
		//+++++++++++++++++++++
		// END of NEW CODE EX2
		//+++++++++++++++++++++

		// create a number each second instaed of each 200ms, if successful print to screen
		myScreen.createNumber(currentLevel);
	}

	// using the input from the users keyboard hits
	for (list<char>::const_iterator itr = keyHits.begin(); itr != keyHits.end(); ++itr){
		char ch = *itr;
		// according to the users key hits change the direction if needed
		switch (ch){
		case 'i':
			player2.changeDirection(Direction::UP);
			break;
		case 'w':
			player1.changeDirection(Direction::UP);
			break;
		case 'j':
			player2.changeDirection(Direction::LEFT);
			break;
		case 'a':
			player1.changeDirection(Direction::LEFT);
			break;
		case 'm':
			player2.changeDirection(Direction::DOWN);
			break;
		case 'x':
			player1.changeDirection(Direction::DOWN);
			break;
		case 'l':
			player2.changeDirection(Direction::RIGHT);
			break;
		case 'd':
			player1.changeDirection(Direction::RIGHT);
			break;
			// +++++++++++++++++++++++++++++++++++++++++++++++++
			// "NEW CODE EX2, author=Maya Bugana, date=2015-05-12
			// +++++++++++++++++++++++++++++++++++++++++++++++++
		case 'z':
			if ((player1.getShotsCounter() > 0) && player1.isPlayerAlive()){
				int index;
				index=playShooting.addShot(player1.getPosition(), player1.getDirection());
				playShooting.getShotInArr(index)->shotMove(); 
				playShooting.getShotInArr(index)->shotMove();
				player1.setShotsCounter(player1.getShotsCounter() - 1);
				stBar.updatePlayerShots(1);
			}
			break;
		case 'n':
			int index;
			if ((player2.getShotsCounter() > 0) && player2.isPlayerAlive()){
				index = playShooting.addShot(player2.getPosition(), player2.getDirection());
				playShooting.getShotInArr(index)->shotMove();
				playShooting.getShotInArr(index)->shotMove();
				player2.setShotsCounter(player2.getShotsCounter() - 1);
				stBar.updatePlayerShots(2);
			}
			break;
			//+++++++++++++++++++++
			// END of NEW CODE EX2
			//+++++++++++++++++++++
		default:
			break;
		}
	}

	// check if the player is still alive and according to the direction of its
	// movment and the position of the oponent player see if the player can move
	if (player1.isPlayerAlive() && player1.isMoveLegal(player2.getPosition())){
		player1.playerErase();
		player1.playerMove();
		player1.playerDraw();

		// check if the player is now eating a number
		if (myScreen.isNumberExist(player1.getPosition())){
			if (currentLevel <= 20 || (player1.numMissinValues(currentLevel) == 1)){
				// check if the number that the player is eating is the sulotion for his "targil"
				if (!player1.isPlayerDone(myScreen.getNumberInPos(player1.getPosition()))){
					player1.setLives(player1.getLives() - 1);
					stBar.updatePlayerLife(1);
					// if user ran out of lives
					if (!player1.isPlayerAlive())
						player1.playerErase();
				}
				else{
					player1.setScore(player1.getScore() + 1);
				}
			}
			// +++++++++++++++++++++++++++++++++++++++++++++++++
			// "NEW CODE EX2, author=Dror Moyal, date=2015-05-09
			// +++++++++++++++++++++++++++++++++++++++++++++++++
			else if (player1.numMissinValues(currentLevel) == 2){
				if (!player1.isPossibleSulotion(myScreen.getNumberInPos(player1.getPosition()))){
					player1.setLives(player1.getLives() - 1);
					stBar.updatePlayerLife(1);
					// if user ran out of lives
					if (!player1.isPlayerAlive())
						player1.playerErase();
				}
				else{
					stBar.updatePlayerExercise(1);
				}
				//+++++++++++++++++++++
				// END of NEW CODE EX2
				//+++++++++++++++++++++
			}
		}

	}

	// check if the player is still alive and according to the direction of its
	// movment and the position of the oponent player see if the player can move
	if (player2.isPlayerAlive() && player2.isMoveLegal(player1.getPosition())){
		player2.playerErase();
		player2.playerMove();
		player2.playerDraw();

		// check if the player is now eating a number
		if (myScreen.isNumberExist(player2.getPosition())){
			if (currentLevel <= 20 || (player2.numMissinValues(currentLevel) == 1)){
				// check if the number that the player is eating is the sulotion for his "targil"
				if (!player2.isPlayerDone(myScreen.getNumberInPos(player2.getPosition()))){
					player2.setLives(player2.getLives() - 1);
					stBar.updatePlayerLife(2);
					// if user ran out of lives
					if (!player2.isPlayerAlive())
						player2.playerErase();
				}
				else{
					player2.setScore(player2.getScore() + 1);
				}
			}
			// +++++++++++++++++++++++++++++++++++++++++++++++++
			// "NEW CODE EX2, author=Dror Moyal, date=2015-05-09
			// +++++++++++++++++++++++++++++++++++++++++++++++++
			else if (player2.numMissinValues(currentLevel) == 2){
				if (!player2.isPossibleSulotion(myScreen.getNumberInPos(player2.getPosition()))){
					player2.setLives(player2.getLives() - 1);
					stBar.updatePlayerLife(2);
					// if user ran out of lives
					if (!player2.isPlayerAlive())
						player2.playerErase();
				}
				else{
					stBar.updatePlayerExercise(2);
				}
				//+++++++++++++++++++++
				// END of NEW CODE EX2
				//+++++++++++++++++++++
			}
		}

	}
}

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX2, author=Maya Bugana, date=2015-05-12
// +++++++++++++++++++++++++++++++++++++++++++++++++

void TheMathGame::doSubIteration()
{
	if (playShooting.getSize() > 0)
	{
		for (unsigned int i = 0; i < playShooting.getSize(); i++)
		{
			Point shotNextPos = playShooting.getShotInArr(i)->shotNextPos();

			//check if a shot is now "eating" a number
			if (myScreen.isNumberExist(shotNextPos))
			{
				myScreen.getNumberInPos(shotNextPos);
				playShooting.delShot(i);
			}
			//check if a shot is "eating" Player1
			else if ((player1.getPosition().comparePoints(shotNextPos)) || 
				(player1.playerNextPos().comparePoints(shotNextPos)))
			{
				player1.setLives(player1.getLives() - 1);
				stBar.updatePlayerLife(1);
				playShooting.delShot(i);
				// if player is ran out of lives
				if (!player1.isPlayerAlive())
					player1.playerErase();
				else
				{
					player1.playerErase();
					player1.setPosition(Point(10, 9));
				}	
			}
			//check if a shot is "eating" Player2
			else if ((player2.getPosition().comparePoints(shotNextPos)) ||
				(player2.playerNextPos().comparePoints(shotNextPos)))
			{
				player2.setLives(player2.getLives() - 1);
				stBar.updatePlayerLife(2);
				playShooting.delShot(i);
				// if player is ran out of lives
				if (!player2.isPlayerAlive())
					player2.playerErase();
				else
				{
					player2.playerErase();
					player2.setPosition(Point(70, 9));
				}
					
			}
			else
				playShooting.getShotInArr(i)->shotMove();

		}
	}
}

//+++++++++++++++++++++
// END of NEW CODE EX2
//+++++++++++++++++++++
