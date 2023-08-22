#include "Draw.h"

Draw::Draw()
{
	// back_buffer / front_buffer 초기화
	for (int i = 0; i < SCR_HEIGHT; i++)
	{
		for (int j = 0; j < SCR_WIDTH; j++)
		{
			front_buffer[i][j] = -1;
			back_buffer[i][j] = -1;
		}
	}
}

Draw::~Draw()
{

}

void Draw::drawTitleScene(Title _Title)
{
	for (int i = 0; i < SCR_HEIGHT; i++)
	{
		for (int j = 0; j < SCR_WIDTH; j++)
		{
			back_buffer[i][j] = BLACK;
		}
	}

	// 타이틀 로고 도트
	drawToBackBuffer((SCR_WIDTH / 2) - 88, 20, 177, 16, _Title.getTitleDot1());
	drawToBackBuffer((SCR_WIDTH / 2) - 48, 44, 95, 8, _Title.getTitleDot2());
	drawToBackBuffer((SCR_WIDTH / 2) - 43, 80, 86, 7, _Title.getTitleDot3());

	// 선택 문자 도트
	drawToBackBuffer((SCR_WIDTH / 2) - 38, _Title.getSelectPosY(), 13, 6, _Title.getSelectDot());
	drawToBackBuffer((SCR_WIDTH / 2) - 19, 110, 39, 7, _Title.getStartDot());
	drawToBackBuffer((SCR_WIDTH / 2) - 16, 125, 30, 7, _Title.getExitDot());
}

void Draw::drawGameScene(Player* _Player, Timer _Timer, Rest _Rest, int curRest, Obstacle** _Obstacle)
{
	// 맵 그리기
	drawMap();

	// 상단 바 정보 그리기
	drawTopBar(_Timer, _Rest, _Player, curRest);

	// 장애물 그리기
	drawObstacle(_Obstacle);

	// 플레이어 그리기
	drawPlayer(_Player);

	if (curRest < 80)
	{
		// 도착 장소 그리기
		drawArrive(curRest);
	}
}

void Draw::drawGameOver(char* gameOverDot)
{
	drawToBackBuffer((SCR_WIDTH / 2) - 34, 40, 69, 9, gameOverDot);
	render();
}


void Draw::drawClear(Player* _Player)
{
	_Player->setCurrentDot(_Player->getMoveDot1());
	_Player->setPosY(SCR_HEIGHT - 37);

	while (_Player->getPosX() + (_Player->getWidth() / 2) != SCR_WIDTH / 2)
	{
		for (int i = 88; i < SCR_HEIGHT; i++)
		{
			for (int j = 60; j < 138 + _Player->getWidth(); j++)
			{
				back_buffer[i][j] = LIGHT_WHITE;
			}
		}

		if (_Player->getPosX() + (_Player->getWidth() / 2) <= (SCR_WIDTH / 2))
		{
			_Player->setPosX(_Player->getPosX() + 1);
		}
		else
		{
			_Player->setPosX(_Player->getPosX() - 1);
		}

		drawPlayer(_Player);
		render();
		Sleep(40);
	}

	for (int i = 0; i < 20; i++)
	{
		for (int i = 88; i < SCR_HEIGHT; i++)
		{
			for (int j = 60; j < 138 + _Player->getWidth(); j++)
			{
				back_buffer[i][j] = LIGHT_WHITE;
			}
		}

		if (i % 2 == 0)
		{
			_Player->setCurrentDot(_Player->getFrontDot1());
		}
		else
		{
			_Player->setCurrentDot(_Player->getFrontDot2());
		}

		drawPlayer(_Player);
		render();
		Sleep(200);
	}
}


void Draw::drawTopBar(Timer _Timer, Rest _Rest, Player* _Player, int curRest)
{
	int num1 = 10;
	int num2 = 1;

	// Timer 그리기
	drawToBackBuffer(10, _Timer.getPosY(), 33, 7, _Timer.getTimerDot());
	for (int i = 4; i > 0; i--)
	{
		drawToBackBuffer(_Timer.getPosX() + ((i - 1) * 7), _Timer.getPosY(), _Timer.getHeight(), _Timer.getWidth(), _Timer.getTimeNumDot((_Timer.getRunCur() % num1) / num2));
		num1 *= 10;
		num2 *= 10;
	}

	// Rest 그리기
	num1 = 10;
	num2 = 1;
	drawToBackBuffer(_Rest.getPosX(), _Rest.getPosY(), _Rest.getWidth(), _Rest.getHeight(), _Rest.getRestDot());
	for (int i = 4; i > 0; i--)
	{
		drawToBackBuffer((_Rest.getPosX() + 36) + ((i - 1) * 7), _Rest.getPosY(), _Timer.getHeight(), _Timer.getWidth(), _Timer.getTimeNumDot((curRest % num1) / num2));
		num1 *= 10;
		num2 *= 10;
	}
	drawToBackBuffer(_Rest.getPosX() + 66, _Rest.getPosY() + 1, 11, 6, _Rest.getKmDot());

	// Score 그리기
	int scorePosX = 173;
	num1 = 10;
	num2 = 1;

	for (int i = 6; i > 0; i--)
	{
		drawToBackBuffer(scorePosX + ((i - 1) * 7), 10, 6, 7, _Timer.getTimeNumDot((_Player->getScore() % num1) / num2));
		num1 *= 10;
		num2 *= 10;
	}
}

void Draw::drawMap()
{
	// 맵 배경색 저장
	for (int i = 10; i < SCR_HEIGHT; i++)
	{
		for (int j = 10; j < SCR_WIDTH - 10; j++)
		{
			if (i <= 20)
			{
				back_buffer[i][j] = BLACK;
			}
			else if (i > 20 && i < 50)
			{
				back_buffer[i][j] = LIGHT_CYAN;
			}
			else
			{
				back_buffer[i][j] = LIGHT_WHITE;
			}
		}
	}

	// 맵 배경(빙산) 저장
	drawToBackBuffer(10, 43, 204, 7, _Map.getMapDot());
}

void Draw::drawPlayer(Player* _Player)
{
	// 그림자 그리기
	drawToBackBuffer(_Player->getPosX(), _Player->getShadow().getPosY(), _Player->getShadow().getWidth(), _Player->getShadow().getHeight(), _Player->getShadow().getCurrentDot());

	// 플레이어 그리기
	drawToBackBuffer(_Player->getPosX(), _Player->getPosY(), _Player->getWidth(), _Player->getHeight(), _Player->getCurrentDot());
}

void Draw::drawObstacle(Obstacle** _Obstacle)
{
	for (int i = 0; i < MAX_Obstacle; i++)
	{
		if (_Obstacle[i] != NULL)
		{
			drawToBackBuffer(_Obstacle[i]->geObstacleX(), _Obstacle[i]->getObstacleY(), _Obstacle[i]->getObstacleWidth(), _Obstacle[i]->getObstacleHeight(), _Obstacle[i]->getCurrentDot());

			if ((_Obstacle[i]->getObstacleY() + _Obstacle[i]->getObstacleHeight()) > SCR_HEIGHT - 1)
			{
				delete(_Obstacle[i]);
				_Obstacle[i] = NULL;
			}
			else
			{
				_Obstacle[i]->setObstacleY(_Obstacle[i]->getObstacleY() + 1);
			}
		}
	}
}

void Draw::drawArrive(int curRest)
{
	if (curRest < 80 && curRest > 60)
	{
		drawToBackBuffer((SCR_WIDTH / 2) - 9, 50, 19, 12, _Map.getArriveDot1());
	}
	else if (curRest < 60 && curRest > 30)
	{
		drawToBackBuffer((SCR_WIDTH / 2) - 15, 50, 28, 16, _Map.getArriveDot2());
	}
	else if (curRest < 30 && curRest > 10)
	{
		drawToBackBuffer((SCR_WIDTH / 2) - 25, 40, 51, 36, _Map.getArriveDot3());
	}
	else if (curRest < 10)
	{
		drawToBackBuffer((SCR_WIDTH / 2) - 40, 29, 80, 58, _Map.getArriveDot4());
	}
}

void Draw::drawToBackBuffer(short x, short y, int width, int height, char* dotArray)
{
	for (int i = y; i < y + height; i++)
	{
		for (int j = x; j < x + width; j++)
		{
			int value = dotArray[(j - x) + ((i - y) * width)];

			if (back_buffer[i][j] == value || value == -1) continue;
			back_buffer[i][j] = value;
		}
	}
}

void Draw::render()
{
	for (int i = 0; i < SCR_HEIGHT; i++)
	{
		for (int j = 0; j < SCR_WIDTH; j++)
		{
			if (back_buffer[i][j] != front_buffer[i][j])
			{
				int color = back_buffer[i][j];
				textColor(color, color);

				gotoXY(j * 2, i);
				printf("■");
			}

			front_buffer[i][j] = back_buffer[i][j];
		}
	}
}

void Draw::gotoXY(short posX, short posY)
{
	COORD CursorPos = { posX , posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);
}

void Draw::textColor(int font, int backGround)
{
	int Color = font + backGround * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}


