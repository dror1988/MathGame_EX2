#include "RowsFlyer.h"


//handling a colusion with a Player
void RowsFlyer::coliddedAPlayer(Player& p, int playerNum, StatusBar &stBar)
{
	if ((p.getPosition() == objNextPos()) ||
		(p.playerNextPos() == objNextPos())||
		(p.getPosition() == getPosition()))
	{
		p.setLives(p.getLives() - 1);

		if (playerNum == 1)
			stBar.updatePlayerLife(1);

		else if (playerNum == 2)
			stBar.updatePlayerLife(2);

		// if player is ran out of lives
		if (!p.isPlayerAlive())
			p.playerErase();
		else if (playerNum == 1)
		{
			p.playerErase();
			p.setPosition(Point(10, 9));
		}
		else if (playerNum == 2)
		{
			p.playerErase();
			p.setPosition(Point(70, 9));
		}
	}
}


bool RowsFlyer::coliddedAShot(Point shotPos, Point shotNextPos)
{
	if (shotNextPos == objNextPos() ||
		shotPos == getPosition() ||
		shotPos == objNextPos() ||
		shotNextPos == getPosition()
		)
		return true;
	else
		return false;
}
