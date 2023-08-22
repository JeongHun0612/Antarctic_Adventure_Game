#include "Title.h"

Title::Title()
{
	_selectPosY = 111;
}
Title::~Title()
{

}

int Title::getSelectMenu(void)
{
	if (_kbhit()) // 키보드 입력 시 True값 반환
	{
		char inputKey = _getch();

		switch (inputKey)
		{
		case UP:
			if (_selectPosY > 111)
			{
				_selectPosY -= 15;
			}
			break;
		case DOWN:
			if (_selectPosY < 126)
			{
				_selectPosY += 15;
			}
			break;
		case ENTER:
			return (_selectPosY - 111) / 15;
		}
	}

	return -1;
}