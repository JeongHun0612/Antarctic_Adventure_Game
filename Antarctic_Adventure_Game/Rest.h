#pragma once
#include "Header.h"

class Rest
{
private:
	int _nPosX;
	int _nPosY;
	int _nWidth;
	int _nHeight;

	int _nCurRest;

	char _RestDot[7 * 34] =
	{
		15,15,15,15,15,-1,-1,15,15,15,15,15,15,-1,15,15,15,15,15,15,-1,15,15,15,15,15,15,-1,-1,-1,-1,-1,-1,-1,
		15,-1,-1,-1,-1,15,-1,15,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,15,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		15,-1,-1,-1,-1,15,-1,15,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,15,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		15,15,15,15,15,15,-1,15,15,15,15,15,-1,-1,15,15,15,15,15,15,-1,-1,-1,15,15,-1,-1,-1,15,15,15,15,15,15,
		15,-1,-1,15,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,15,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		15,-1,-1,-1,15,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,15,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		15,-1,-1,-1,-1,15,-1,15,15,15,15,15,15,-1,15,15,15,15,15,15,-1,-1,-1,15,15,-1,-1,-1,-1,-1,-1,-1,-1,-1
	};

	char _KmDot[6 * 11] =
	{
		15,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,
		15,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,
		15,-1,15,-1,-1,-1,15,15,15,15,15,
		15,15,15,-1,-1,-1,15,-1,15,-1,15,
		15,-1,-1,15,-1,-1,15,-1,15,-1,15,
		15,-1,-1,-1,15,-1,15,-1,15,-1,15
	};

public:
	Rest();
	~Rest();

	int getPosX() { return _nPosX; }
	void setPosX(int posX) { _nPosX = posX; }

	int getPosY() { return _nPosY; }
	void setPosY(int posY) { _nPosY = posY; }

	int getWidth() { return _nWidth; }
	void setWidth(int width) { _nWidth = width; }

	int getHeight() { return _nHeight; }
	void setHeight(int height) { _nHeight = height; }

	int getCurRest(int playerSpeed) { return (_nCurRest -= playerSpeed) / 100; }
	void setCurRest(int curRest) { _nCurRest = curRest; }

	char* getRestDot() { return _RestDot; }
	char* getKmDot() { return _KmDot; }
};

