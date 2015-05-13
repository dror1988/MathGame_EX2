#include "Shot.h"


Point Shot::getPosition()const
{
	return shotPosition;
}

Direction::VALUE Shot::getShotDirection()
{
	return shotDirection;
}


Point Shot::setPosition(Point newPosition)
{
	shotPosition.x = newPosition.x;
	shotPosition.y = newPosition.y;
	return shotPosition;
}

Direction::VALUE Shot::setShotDirection(Direction::VALUE newDirection)
{
	shotDirection = newDirection;
	return shotDirection;
}


void Shot::shotDraw()const
{
	setTextColor(RED);
	gotoxy(shotPosition.x, shotPosition.y);
	cout << shotChar;
	setTextColor(WHITE);
}
void Shot::shotErase()const
{
		gotoxy(shotPosition.x, shotPosition.y);
		cout << ' ';	
}

void Shot::shotSetPos()
{
	switch (shotDirection){
	case Direction::UP:
		if (shotPosition.y > Point::minY)
			shotPosition.y--;
		else
			shotPosition.y = Point::maxY;
		break;
	case Direction::DOWN:
		if (shotPosition.y < Point::maxY)
			shotPosition.y++;
		else
			shotPosition.y = Point::minY;
		break;
	case Direction::LEFT:
		if (shotPosition.x > Point::minX)
			shotPosition.x--;
		else
			shotPosition.x = Point::maxX;
		break;
	case Direction::RIGHT:
		if (shotPosition.x < Point::maxX)
			shotPosition.x++;
		else
			shotPosition.x = Point::minX;
		break;
	case Direction::STAY:
		break;
	}
}

Point Shot::shotNextPos()
{
	Shot tmp(this->shotPosition, this->shotDirection);
	tmp.shotSetPos();
	return tmp.getPosition();
}

void Shot::shotMove()
{
	shotErase();
	shotSetPos();
	shotDraw();
}
