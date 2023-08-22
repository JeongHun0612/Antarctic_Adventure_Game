#include "MainGame.h"

MainGame::MainGame()
{
	// 씬 초기화
	_activeScene = EScene::TITLE_SCENE;

	// 콘솔창 초기화
	system("mode con:cols=448 lines=160");
	// 콘솔 색깔 변경
	system("color 0F");

	// 랜덤 시드 초기화
	srand(time(NULL));

	// Cursor 초기화
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
	// 장애물 객체 배열에 빈값이 있는지 확인
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

	// 장애물 객체 생성
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
		// 타이틀 씬 그리기
		_Draw.drawTitleScene(_Title);

		// 메뉴 선택 값 반환
		switch (_Title.getSelectMenu())
		{
		case 0:
			// 게임 씬 전환
			run();
			break;
		case 1:
			// 게임 종료
			return;
		}
		// 출력
		_Draw.render();
	}
}

void MainGame::run(void)
{
	// 게임 bgm 실행
	PlaySound(TEXT("./sound/bgm.wav"), NULL, SND_ASYNC || SND_LOOP);

	_Shadow = new Shadow();
	_Player = new Player();

	// 게임 러닝 타임 초기화
	_Timer.setRunStart(clock() + (_tRunTimer * CLOCKS_PER_SEC));

	while (!isTimeOver && !isClear)
	{
		// 현재 거리 구하기
		int curRest = _Rest.getCurRest(_Player->getSpeed());

		// 게임 씬 그리기
		_Draw.drawGameScene(_Player, _Timer, _Rest, curRest, _Obstacle);

		// 장애물 생성
		if (curRest > 80)
		{
			creatObstacle();
		}

		// 플레이어 이동
		_Player->move();

		// 플레이어 점프
		_Player->jump();

		// 플레이어 충돌 처리
		_Player->collison(_Obstacle);

		// 플레이어 애니메이션 변경
		_Player->changeAnim();

		// 타임 오버
		if (_Timer.getRunCur() < 1)
		{
			_Draw.drawGameOver(_Timer.getTimeOverDot());
			isTimeOver = true;
		}

		// 도착 시 클리어 변수 true로 반복문 빠져나가기
		if (curRest < 1)
		{
			isClear = true;
		}

		Sleep(8);

		// 출력
		_Draw.render();
	}

	// 게임 클리어 시 애니메이션 실행
	if (isClear)
	{
		_Draw.drawClear(_Player);
	}

	// 사운드 종료
	PlaySound(NULL, 0, 0);

	Sleep(5000);
	gameReset(); // 게임 초기화
	title();
}

void MainGame::gameReset(void)
{
	// 인스턴스 삭제
	delete(_Shadow);
	delete(_Player);

	// 장애물 객체 삭제
	for (int i = 0; i < MAX_Obstacle; i++)
	{
		if (_Obstacle[i] != NULL)
		{
			delete(_Obstacle[i]);
			_Obstacle[i] = NULL;
		}
	}

	// 종료 조건 초기화
	isTimeOver = false;
	isClear = false;

	// 거리 초기화
	_Rest.setCurRest(35000);

	// 애니메이션 루프 타임 초기화
	_Player->setMoveTime(0);
	_Player->setJumpTime(0);
	_Player->setCollisionTime(0);
}