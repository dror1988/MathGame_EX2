#ifndef _ROWS_FLYER_H
#define _ROWS_FLYER_H
#include "MovingObject.h"
#include "Player.h"
#include "StatusBar.h"

class RowsFlyer : public MovingObject{
public:
	// RowsFlayer constructor	
	RowsFlyer(Direction::VALUE flayerDirection, Point flayerPosition)
		: MovingObject('!', flayerDirection, flayerPosition, BLUE){
	}
	// Flyer creature init
	void initObject(Direction::VALUE setDirection, Point setPosition)
	{
		MovingObject::initObject('!', setDirection, setPosition, BLUE);
	}
	//handling a colusion with a Player
	void coliddedAPlayer(Player& p, int playerNum, StatusBar& stBar);
	//check if the oject colidded a bulet
	bool coliddedAShot(Point shotPos, Point shotNextPos);
};


#endif