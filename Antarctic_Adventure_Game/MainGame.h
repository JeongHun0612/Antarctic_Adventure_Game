#pragma once

#include "Header.h"
#include "Draw.h"

class MainGame
{
private:
	clock_t _tRunTimer = 120;
	bool isTimeOver = false;
	bool isClear = false;

	Draw _Draw;
	Title _Title;
	Rest _Rest;
	Timer _Timer;
	Player* _Player;
	Shadow* _Shadow;
	Obstacle* _Obstacle[MAX_Obstacle];

	EScene _activeScene;

public:
	MainGame();
	~MainGame();

	void title(void);
	void run(void);
	void creatObstacle(void);
	void gameReset(void);
};

