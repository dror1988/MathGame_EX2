//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// NumberList.h
// -----------
// This file declares a class to manage the numbers list data structor for the screen.
//
// Author: Dror Moyal
// First version: 2015-02-06
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-06-02   Dror Moyal     implemented the NumberList class

#ifndef __NUMBER_LIST_H
#define __NUMBER_LIST_H

#include "Number.h"

struct NumberListNode{
	Number data;
	NumberListNode *next;
	NumberListNode *prev;
};

class NumberList
{
	NumberListNode *head;
	NumberListNode *tail;
public:
	// Default constructor
	NumberList() :head(NULL), tail(NULL){}

	// Object destructor
	~NumberList();
	// Function that verifies if the list is empty
	bool isEmpty() const;
	// Function that make a list an emprt list
	void makeEmpty();
	// Function to create a new node and store the given data
	NumberListNode* createNode(Number* data);
	// Function to insert a data into a list tail
	void insertToTail(Number* data);
	// Function delete a node
	void deleteNode(NumberListNode* pNode);
	// Find closest Number on the screen to a given point
	Point findClosestNumber(Point curPoint) const;
	// return the number in the tail
	Number getTail()const{
		return tail->data;
	}
};


#endif
