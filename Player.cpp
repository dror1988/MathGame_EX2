//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Player.cpp
// -----------
// This file declares a class to manage a player includeing its score, number of lives, position, direction etc.
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
// 2015-04-08     Dror Moyal      implemented the Player class

#include "Player.h"

//===========================
// player destructor
//===========================
Player::~Player(){
	// if player has an exercise, release it
	if (playerExercise != NULL)
	delete playerExercise;
	// if player has an advance exercise, release it
	if (playerAdvExercise != NULL)
		delete playerAdvExercise;
}

//===========================
// delete old exercise and
// create a new one
//===========================
void Player::resetAdvExercise(){
	// if there is an exercise 
	if (playerAdvExercise != NULL){
		delete playerAdvExercise;
		playerAdvExercise = NULL;
	}
}


//===========================
// delete old exercise and
// create a new one
//===========================
void Player::resetExercise(){
	// if there is an exercise 
	if (playerExercise != NULL){
		delete playerExercise;
		playerExercise = NULL;
	}
}

//==========================
// reset the player alive
//==========================
void Player::resetPlayerAlive(){
	playerAlive = true;
}

//==========================
// reset the player done
//==========================
void Player::resetPlayerDone(){
	playerDone = false;
}

//===================================
// score getter
//===================================
unsigned int Player::getScore()const{
	return playerScore;
}

//===================================
// lives getter
//===================================
unsigned int Player::getLives()const{
	return playerLives;
}

//===================================
// ShotsCounter getter
//===================================
unsigned int Player::getShotsCounter()const{
	return shotsCounter;
}

//===================================
// position getter
//===================================
Point Player::getPosition()const{
	return playerPosition;
}

//===================================
// direction getter
//===================================
Direction::VALUE Player::getDirection()const{
	return playerDirection;
}

//===================================
// exercise getter
//===================================
string Player::getExercise()const{
	if (playerExercise != NULL)
		return playerExercise->getExercise();
	else
		return "";
}

//===================================
// return how many missing values
//===================================
int Player::numMissinValues(int currentLevel)const{
	if (currentLevel <= 20)
		return -1;
	else
		return playerAdvExercise->getMissingVars();
}

//===================================
// score setter
//===================================
unsigned int Player::setScore(unsigned int newScore){
	playerScore = newScore;
	return playerScore;
}

//===================================
// lives setter
//===================================
unsigned int Player::setLives(unsigned int newLives){
	playerLives = newLives;
	return playerLives;
}

//===================================
// shotsCounter setter
//===================================
unsigned int Player::setShotsCounter(unsigned int newShotsCounter){
	shotsCounter = newShotsCounter;
	return shotsCounter;
}

//===================================
// position setter
//===================================
Point Player::setPosition(Point newPosition){
	playerPosition = newPosition;
	return playerPosition;
}

//===================================
// direction setter
//===================================
Direction::VALUE Player::changeDirection(Direction::VALUE newDirection){
	playerDirection = newDirection;
	return playerDirection;
}

//===================================
// exercise creator
//===================================
Exercise* Player::createExercise(int currentLevel){
	if (playerExercise == NULL){
		playerExercise = new Exercise(currentLevel);
		return playerExercise;
	}
	else
		return NULL;
}


//===================================
// verify if player is alive 
// according to the number
// of lives he has left
//===================================
bool Player::isPlayerAlive(){
	if (playerLives==0)
		playerAlive=false;
	return playerAlive;
}

//===================================
// advance exercise getter
//===================================
string Player::getAdvExercise()const{
	if (playerAdvExercise != NULL)
		return playerAdvExercise->getAdvExercise();
	else
		return "";
}

//===================================
// advance exercise creator
//===================================
AdvExercise* Player::createAdvExercise(int currentLevel){
	if (playerAdvExercise == NULL){
		playerAdvExercise = new AdvExercise(currentLevel);
		return playerAdvExercise;
	}
	else
		return NULL;
}

//===================================
// verify if a player is done 
// according to the number he ate
//===================================
bool Player::isPlayerDone(unsigned int eatenNumber){
	if (playerExercise!=NULL)
		playerDone=playerExercise->isExerciseComplete(eatenNumber);
	else if ((playerAdvExercise != NULL) && (playerAdvExercise->getMissingVars()==1))
		playerDone = playerAdvExercise->isAdvExerciseComplete(eatenNumber);
	return playerDone;
}

//===================================
// verify if a player eaten number
// is a possible solution
//===================================
bool Player::isPossibleSulotion(unsigned int eatenNumber){
	return playerAdvExercise->isPossibleSolution(eatenNumber);
}

//===================================
// player done getter
//===================================
bool Player::getPlayerDone(){
	return playerDone;
}

//===================================
// print a player in his 
// position on screen
//===================================
void Player::playerDraw() const{
	setTextColor(LIGHTGREEN);
	gotoxy(playerPosition.x, playerPosition.y);
	cout << playerChar;
	setTextColor(WHITE);
}

//===================================
// erase a player from his position 
// on screen
//===================================
void Player::playerErase()const{
	gotoxy(playerPosition.x, playerPosition.y);
	cout << ' ';
}

//===================================
// computes the movement of a player 
// according to the players direction
//===================================
void Player::playerMove(){
	// use direction as a case
	// make sure player will no go out
	// of screen borders
	switch (playerDirection){
	case Direction::UP:
		if (playerPosition.y > Point::minY)
			playerPosition.y--;
		else
			playerPosition.y = Point::maxY;
		break;
	case Direction::DOWN:
		if (playerPosition.y < Point::maxY)
			playerPosition.y++;
		else
			playerPosition.y = Point::minY;
		break;
	case Direction::LEFT:
		if (playerPosition.x > Point::minX)
			playerPosition.x--;
		else
			playerPosition.x = Point::maxX;
		break;
	case Direction::RIGHT:
		if (playerPosition.x < Point::maxX)
			playerPosition.x++;
		else
			playerPosition.x = Point::minX;
		break;
	case Direction::STAY:
		break;
	}
}

//===================================
// verify if a move is legal 
// according to the other 
// players position
//===================================
bool Player::isMoveLegal(Point otherPlayerPos){
	// create a temp position to 
	// compute the position of the
	// player after movment
	Point tempPoint=playerPosition;

	// use direction as a case
	switch (playerDirection){
	case Direction::UP:
		if (tempPoint.y > Point::minY)
			tempPoint.y--;
		else
			tempPoint.y = Point::maxY;
		break;
	case Direction::DOWN:
		if (tempPoint.y < Point::maxY)
			tempPoint.y++;
		else
			tempPoint.y = Point::minY;
		break;
	case Direction::LEFT:
		if (tempPoint.x > Point::minX)
			tempPoint.x--;
		else
			tempPoint.x = Point::maxX;
		break;
	case Direction::RIGHT:
		if (tempPoint.x < Point::maxX)
			tempPoint.x++;
		else
			tempPoint.x = Point::minX;
		break;
	default:
		break;
	}

	// if the new position of the player is not in the
	// same position as the other player then the move
	// is legal
	//if (tempPoint.x == otherPlayerPos.x && tempPoint.y == otherPlayerPos.y)
	if (tempPoint == otherPlayerPos)
		return false;
	else
		return true;
}

Point Player::playerNextPos()
{
	Player tmp;
	tmp.setPosition(this->playerPosition);
	tmp.changeDirection(this->playerDirection);
	tmp.playerMove();
	return tmp.getPosition();
}
