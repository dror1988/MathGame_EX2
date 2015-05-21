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
// 2015-04-13	 Dror Moyal      Adding functions

#include "shotsArray.h"

//===================================
// shotsArray constructor
//===================================
shotsArray::shotsArray()
{
	for (unsigned int i = 0; i < size; i++)
		Arr[i] = NULL;
	
	size = 0;
}

//===================================
// shotsArray destructor
//===================================
shotsArray::~shotsArray()
{
	for (unsigned int i = 0; i < size; i++)
	{
		delete Arr[i];
		Arr[i] = NULL;
	}
	size = 0;
}

//===================================
// inits the array
//===================================
void shotsArray::initArr(){
	for (unsigned int i = 0; i < size; i++)
	{
		Arr[i]->shotErase();
		delete Arr[i];
		Arr[i] = NULL;
	}
	size = 0;
}

//===================================
// print all shts in array
//===================================
void shotsArray::printShots() const{
	for (unsigned int i = 0; i < size; i++)
		Arr[i]->shotDraw();
}

//===================================
// size getter
//===================================
unsigned int shotsArray::getSize()
{
	return size;
}

//===================================
// returns a shot in a specific index
//===================================
Shot* shotsArray::getShotInArr(int i)
{
	return Arr[i];
}

//===================================
// size setter
//===================================
unsigned int  shotsArray::setSize(unsigned int newSize)
{
	size = newSize;
	return size;
}

//===================================
// manage the movements of all shots in array
//===================================
void shotsArray::move()
{
	if (size != 0)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			Arr[i]->shotMove();
			delete Arr[i];
			Arr[i] = NULL;
			--size;
		}		
	}
}

//===================================
// add new shot to shotsArray
//===================================
int shotsArray::addShot(Point shotPosition, Direction::VALUE shotDirection)
{	
	Arr[size] = new Shot(shotPosition, shotDirection);
	size++;
	return size - 1;
}

//===================================
// delete shot in a specific index
//===================================
void shotsArray::delShot(int i)
{
	Arr[i]->shotErase();
	swap(Arr[i], Arr[size - 1]);
	delete Arr[size - 1];
	Arr[size - 1] = NULL;
	
	--size;
}

//===================================
// swap between 2 shots
//===================================
void shotsArray::swap(Shot* &a, Shot* &b)
{
	Shot* tmp;
	tmp = a;
	a = b;
	b = tmp;
}
