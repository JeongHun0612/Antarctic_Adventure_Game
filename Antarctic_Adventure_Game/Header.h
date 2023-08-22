#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

// 컬러값 상수 지정
#define BLACK			0		// 검정색
#define BLUE			1		// 파란색
#define GREEN			2		// 초록색
#define	CYAN			3		// 옥색
#define RED				4		// 빨간색
#define MAGENTA			5		// 자주색
#define YELLOW			6		// 노란색
#define WHITE			7		// 흰색
#define GRAY			8		// 회색
#define LIGHT_BLUE		9		// 연한 파란색
#define LIGHT_GREEN		10		// 연한 초록색
#define LIGHT_CYAN		11		// 연한 옥색
#define LIGHT_RED		12		// 연한 빨간색
#define LIGHT_MAGENTA	13		// 연한 자주잭
#define LIGHT_YELLOW	14		// 연한 노란색
#define LIGHT_WHITE		15		// 진한 흰색

#define SCR_WIDTH		224		// 스크린 WIDTH	값
#define SCR_HEIGHT		150		// 스크린 HEIGHT 값

#define MAX_Obstacle	15		// 장애물 생성 최대 갯수

#define UP		72
#define DOWN	80
#define ENTER	13

enum class EScene				// 씬에 대한 enum
{
	TITLE_SCENE,
	GAME_SCENE
};

enum class EObstacleType
{
	HOLE,
	FLAG
};



using namespace std;

using std::cout;
using std::cin;
using std::endl;

