#ifndef _SHOT_H
#define _SHOT_H

#include <string>
#include "Point.h"
#include "Direction.h"
#include "io_utils.h"
#include <iostream>

class Shot
{
	unsigned char shotChar;
	Direction::VALUE shotDirection;
	Point shotPosition;
public:
	Shot(Point shotPosition, Direction::VALUE shotDirection) :
		shotChar('*'), shotPosition(shotPosition), shotDirection(shotDirection){
	}

	Shot(){};

	~Shot(){};

	Point getPosition()const;
	Direction::VALUE getShotDirection();
	Point setPosition(Point newPosition);
	Direction::VALUE setShotDirection(Direction::VALUE newDirection);

	void shotDraw()const;
	void shotErase()const;
	void shotSetPos();
	Point shotNextPos();
	void shotMove();
};


#endif // !_SHOT_H
