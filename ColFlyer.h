#ifndef _COL_FLYER_H
#define _COL_FLYER_H
#include "MovingObject.h"
#include "Player.h"
#include "StatusBar.h"

class ColFlyer : public MovingObject{
public:
	// ColFlyer constructor	
	ColFlyer(Direction::VALUE flayerDirection, Point flayerPosition)
		: MovingObject('$', flayerDirection, flayerPosition, MAGENTA){
	}
	// Flyer creature init
	void initObject(Direction::VALUE setDirection, Point setPosition)
	{
		MovingObject::initObject('$', setDirection, setPosition, MAGENTA);
	}
	//handling a colusion with a Player
	void coliddedAPlayer(Player& p, int playerNum, StatusBar& stBar);
	//check if the oject colidded a bulet
	bool coliddedAShot(Point shotPos, Point shotNextPos);
};

#endif