#include "MainGame.h"

MainGame::MainGame()
{
	// �� �ʱ�ȭ
	_activeScene = EScene::TITLE_SCENE;

	// �ܼ�â �ʱ�ȭ
	system("mode con:cols=448 lines=160");
	// �ܼ� ���� ����
	system("color 0F");

	// ���� �õ� �ʱ�ȭ
	srand(time(NULL));

	// Cursor �ʱ�ȭ
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.dwSize = 1;
	CursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}

MainGame::~MainGame()
{

}

void MainGame::creatObstacle(void)
{
	// ��ֹ� ��ü �迭�� ���� �ִ��� Ȯ��
	int idx = -1;
	for (int i = 0; i < MAX_Obstacle; i++)
	{
		if (_Obstacle[i] == NULL)
		{
			idx = i;
			break;
		}
	}

	if (idx == -1) return;

	// ��ֹ� ��ü ����
	int obstacleCycle = rand() % 5 + 1;
	if (_Timer.getCycleCur() > obstacleCycle)
	{
		_Obstacle[idx] = new Obstacle;
		_Obstacle[idx]->setObstacleX(rand() % 76 + 60);

		if (rand() % 2 == 0)
		{
			_Obstacle[idx]->setObstacleWidth(_Obstacle[idx]->getHoleWidth());
			_Obstacle[idx]->setObstacleHeight(_Obstacle[idx]->getHoleHeight());
			_Obstacle[idx]->setCurrentDot(_Obstacle[idx]->getHoleDot());
			_Obstacle[idx]->setObstacleType(EObstacleType::HOLE);
		}
		else
		{
			_Obstacle[idx]->setObstacleWidth(_Obstacle[idx]->getFlagWidth());
			_Obstacle[idx]->setObstacleHeight(_Obstacle[idx]->getFlagHeight());
			_Obstacle[idx]->setCurrentDot(_Obstacle[idx]->getFlagDot());
			_Obstacle[idx]->setObstacleType(EObstacleType::FLAG);
		}

		_Timer.setCycleInit(clock());
	}
}

void MainGame::title(void)
{

	_Title = Title();

	while (true)
	{
		// Ÿ��Ʋ �� �׸���
		_Draw.drawTitleScene(_Title);

		// �޴� ���� �� ��ȯ
		switch (_Title.getSelectMenu())
		{
		case 0:
			// ���� �� ��ȯ
			run();
			break;
		case 1:
			// ���� ����
			return;
		}
		// ���
		_Draw.render();
	}
}

void MainGame::run(void)
{
	// ���� bgm ����
	PlaySound(TEXT("./sound/bgm.wav"), NULL, SND_ASYNC || SND_LOOP);

	_Shadow = new Shadow();
	_Player = new Player();

	// ���� ���� Ÿ�� �ʱ�ȭ
	_Timer.setRunStart(clock() + (_tRunTimer * CLOCKS_PER_SEC));

	while (!isTimeOver && !isClear)
	{
		// ���� �Ÿ� ���ϱ�
		int curRest = _Rest.getCurRest(_Player->getSpeed());

		// ���� �� �׸���
		_Draw.drawGameScene(_Player, _Timer, _Rest, curRest, _Obstacle);

		// ��ֹ� ����
		if (curRest > 80)
		{
			creatObstacle();
		}

		// �÷��̾� �̵�
		_Player->move();

		// �÷��̾� ����
		_Player->jump();

		// �÷��̾� �浹 ó��
		_Player->collison(_Obstacle);

		// �÷��̾� �ִϸ��̼� ����
		_Player->changeAnim();

		// Ÿ�� ����
		if (_Timer.getRunCur() < 1)
		{
			_Draw.drawGameOver(_Timer.getTimeOverDot());
			isTimeOver = true;
		}

		// ���� �� Ŭ���� ���� true�� �ݺ��� ����������
		if (curRest < 1)
		{
			isClear = true;
		}

		Sleep(8);

		// ���
		_Draw.render();
	}

	// ���� Ŭ���� �� �ִϸ��̼� ����
	if (isClear)
	{
		_Draw.drawClear(_Player);
	}

	// ���� ����
	PlaySound(NULL, 0, 0);

	Sleep(5000);
	gameReset(); // ���� �ʱ�ȭ
	title();
}

void MainGame::gameReset(void)
{
	// �ν��Ͻ� ����
	delete(_Shadow);
	delete(_Player);

	// ��ֹ� ��ü ����
	for (int i = 0; i < MAX_Obstacle; i++)
	{
		if (_Obstacle[i] != NULL)
		{
			delete(_Obstacle[i]);
			_Obstacle[i] = NULL;
		}
	}

	// ���� ���� �ʱ�ȭ
	isTimeOver = false;
	isClear = false;

	// �Ÿ� �ʱ�ȭ
	_Rest.setCurRest(35000);

	// �ִϸ��̼� ���� Ÿ�� �ʱ�ȭ
	_Player->setMoveTime(0);
	_Player->setJumpTime(0);
	_Player->setCollisionTime(0);
}