#ifndef _SHOTS_ARRAY_H
#define _SHOTS_ARRAY_H

#include "Shot.h"
#include <stdio.h>
#include <iostream>

class shotsArray{
	unsigned int size;
	Shot* Arr[30];
public:
	shotsArray();
	~shotsArray();
	shotsArray(const shotsArray& a) : size(a.size)
	{
		*Arr = new Shot;
		**Arr = **(a.Arr);
	}

	void initArr();
	void printShots() const;
	unsigned int getSize();
	Shot* getShotInArr(int i);
	unsigned int setSize(unsigned int newSize);
	void move();
	int addShot(Point shotPosition, Direction::VALUE shotDirection);
	void delShot(int i);
	void swap(Shot* &a, Shot* &b);
};

#endif