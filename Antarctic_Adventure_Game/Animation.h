#pragma once
#include "Draw.h"
#include "Player.h"

class Animation
{
private:
	Draw _Draw;

	static int _nLooptime;
	static int _deltaTime;
	int _nAnimInterval;

public:
	Animation();
	~Animation();
};

