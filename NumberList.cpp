//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// NumberList.cpp
// -----------
// This file declares a class to manage the numbers list data structor for the screen.
//
// Author: Dror Moyal
// First version: 2015-06-02
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-06-02   Dror Moyal     implemented the NumberList class
// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX3, author=Dror Moyal, date=2015-06-02
// +++++++++++++++++++++++++++++++++++++++++++++++++

#include "NumberList.h"

//===================================
// Object destructor
//===================================
NumberList::~NumberList(){
	NumberListNode* pTemp = NULL;

	// if the list is not empty
	if (!isEmpty())
		// release all allocated nodes in the list
	for (NumberListNode* pNode = head; pNode != NULL;){
		pTemp = pNode->next;
		delete pNode;
		pNode = pTemp;
	}
}

//===================================
// Function that verifies if the list is empty
//===================================
bool NumberList::isEmpty() const{
	if (head == NULL) // list is empty
		return true;
	else        // list is not empty
		return false;
}

//===================================
// Function that make a list an emprt list
//===================================
void NumberList::makeEmpty(){
	// if the list is not empty
	if (!isEmpty()){
		NumberListNode* pTemp = NULL;
		// release all allocated nodes in the list
		for (NumberListNode* pNode = head; pNode != NULL;){
			pTemp = pNode->next;
			delete pNode;
			pNode = pTemp;
		}
	}

	// set the head and tail as NULL
	head = tail = NULL;
}

//===================================
// Function to create a new node and store the given data
//===================================
NumberListNode* NumberList::createNode(Number *data){
	NumberListNode* pNode = new NumberListNode;

	// store the data
	pNode->data = *data;
	pNode->next = NULL;
	pNode->prev = NULL;

	return pNode;
}

//===================================
// Function to insert a data into a list tail
//===================================
void NumberList::insertToTail(Number* data){
	NumberListNode *pNode = createNode(data);

	if (!isEmpty()){
		// make the tail node to point on the new node
		tail->next = pNode;
		pNode->prev = tail;
		// make the tail to point on the new node
		tail = pNode;
	}else{
		head = tail = pNode;
	}
}

//===================================
// Function delete a node
//===================================
void NumberList::deleteNode(NumberListNode* pNode){
	if (pNode != NULL && !isEmpty()){
		if (pNode->next != NULL && pNode->prev != NULL){
			pNode->next->prev = pNode->prev;
			pNode->prev->next = pNode->next;
			delete pNode;
		}
		else if (pNode->next != NULL && pNode->prev == NULL){
			head = pNode->next;
			pNode->next->prev = NULL;
			delete pNode;
		}
		else if (pNode->next == NULL && pNode->prev != NULL){
			tail = pNode->prev;
			pNode->prev->next = NULL;
			delete pNode;
		}
		else{
			head = tail = NULL;
			delete pNode;
		}
	}
}

//===================================
// find the shortest distance from a
// given node in the list until its end
// used to find the distnace to the new
// number on the screen
//===================================
Point NumberList::shortestDistanceToNewNumber(Point curPoint)const{
	Point p(0, 0), tmpPoint(0, 0);
	unsigned int distance = 999;
	NumberListNode *pTemp;

	for (pTemp = getTailNumber(); pTemp != NULL; pTemp = pTemp->next){
		tmpPoint = pTemp->data.getNumberPosition();
		if (curPoint.pointDistance(tmpPoint) < distance){
			distance = curPoint.pointDistance(tmpPoint);
			p = tmpPoint;
		}
	}

	return p;
}

//===================================
// Function to find the closest number on the screen
//===================================
Point NumberList::findClosestNumber(Point curPoint) const{
	Point p(0,0),tmpPoint(0,0);
	unsigned int distance=999;

	if (!isEmpty()){ // if the list is not empty
		for (NumberListNode* pNode = head; pNode != NULL; pNode = pNode->next){
			tmpPoint = pNode->data.getNumberPosition();
			if (curPoint.pointDistance(tmpPoint) < distance){ // point that is closer
				distance = curPoint.pointDistance(tmpPoint);
				p = tmpPoint;
			}
		}
	}
	
	return p;
}

//===================================
// function that returns the node of 
// the last number in the list.
// in case the number has 2 digits it
// will return the address of the node 
// before the tail
//===================================
NumberListNode* NumberList::getTailNumber()const{
	if (tail->data.getIsOnes())
		return tail->prev;
	else
		return tail;
}

//===================================
// return the tail node
//===================================
NumberListNode* NumberList::getTail()const{
	return tail;
}

//+++++++++++++++++++++
// END of NEW CODE EX3
//+++++++++++++++++++++