#pragma once
#include "Header.h"

class Obstacle
{
private:


	char _holeDot[7 * 40] =
	{
		-1,-1,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,-1,-1,
		-1,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,-1,
		7,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,7,
		7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,
		-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,-1
	};

	char _flagDot[15 * 12] =
	{
		2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,
		2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	};

	int _nObstacleX;
	int _nObstacleY;
	int _nObstacleWidth;
	int _nObstacleHeight;
	char* _currentDot;
	EObstacleType _obsatcleType;

public:
	Obstacle();
	~Obstacle();

	int geObstacleX() { return _nObstacleX; }
	void setObstacleX(int posX) { _nObstacleX = posX; }

	int getObstacleY() { return _nObstacleY; }
	void setObstacleY(int posY) { _nObstacleY = posY; }

	int getObstacleWidth() { return _nObstacleWidth; }
	void setObstacleWidth(int width) { _nObstacleWidth = width; }

	int getObstacleHeight() { return _nObstacleHeight; }
	void setObstacleHeight(int height) { _nObstacleHeight = height; }

	char* getCurrentDot() { return _currentDot; }
	void setCurrentDot(char* currnetDot) { _currentDot = currnetDot; }

	EObstacleType getObstacleTyep() { return _obsatcleType; }
	void setObstacleType(EObstacleType obsatcleType) { _obsatcleType = obsatcleType; }

	// Hole
	int getHoleWidth() { return 40; }
	int getHoleHeight() { return 7; }
	char* getHoleDot() { return _holeDot; }

	// Flag
	int getFlagWidth() { return 12; }
	int getFlagHeight() { return 15; }
	char* getFlagDot() { return _flagDot; }
};

