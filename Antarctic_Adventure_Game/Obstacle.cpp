#include "Obstacle.h"

Obstacle::Obstacle()
{
	_nObstacleX = 0;
	_nObstacleY = 60;
	_nObstacleWidth = 0;
	_nObstacleHeight = 0;
	_currentDot = getHoleDot();
}

Obstacle::~Obstacle()
{

}