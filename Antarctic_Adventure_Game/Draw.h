#pragma once
#include "Header.h"
#include "Title.h"
#include "Map.h"
#include "Timer.h"
#include "Rest.h"
#include "Obstacle.h"
#include "Player.h"
#include "Shadow.h"

class Draw
{
private:
	char _gameOverDot =
	{

	};

	Map _Map;

	char back_buffer[SCR_HEIGHT][SCR_WIDTH];
	char front_buffer[SCR_HEIGHT][SCR_WIDTH];

public:
	Draw();
	~Draw();

	void drawTitleScene(Title _Title);
	void drawGameScene(Player* _Player, Timer _Timer, Rest _Rest, int curRest, Obstacle** _Obstacle);
	void drawGameOver(char* gameOverDot);
	void drawClear(Player* _Player);

	void drawMap();
	void drawPlayer(Player* _Player);
	void drawTopBar(Timer _Timer, Rest _Rest, Player* _Player, int curRest);
	void drawObstacle(Obstacle** _Obstacle);
	void drawArrive(int curRest);

	void drawToBackBuffer(short x, short y, int width, int height, char* dotArray);
	void render();

	void gotoXY(short x, short y);
	void textColor(int font, int backGround);
};

