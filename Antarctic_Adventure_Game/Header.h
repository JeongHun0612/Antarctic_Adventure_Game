#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

// �÷��� ��� ����
#define BLACK			0		// ������
#define BLUE			1		// �Ķ���
#define GREEN			2		// �ʷϻ�
#define	CYAN			3		// ����
#define RED				4		// ������
#define MAGENTA			5		// ���ֻ�
#define YELLOW			6		// �����
#define WHITE			7		// ���
#define GRAY			8		// ȸ��
#define LIGHT_BLUE		9		// ���� �Ķ���
#define LIGHT_GREEN		10		// ���� �ʷϻ�
#define LIGHT_CYAN		11		// ���� ����
#define LIGHT_RED		12		// ���� ������
#define LIGHT_MAGENTA	13		// ���� ������
#define LIGHT_YELLOW	14		// ���� �����
#define LIGHT_WHITE		15		// ���� ���

#define SCR_WIDTH		224		// ��ũ�� WIDTH	��
#define SCR_HEIGHT		150		// ��ũ�� HEIGHT ��

#define MAX_Obstacle	15		// ��ֹ� ���� �ִ� ����

#define UP		72
#define DOWN	80
#define ENTER	13

enum class EScene				// ���� ���� enum
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

