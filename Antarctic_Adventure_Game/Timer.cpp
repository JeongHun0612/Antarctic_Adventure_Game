#include "Timer.h"

Timer::Timer()
{
	_tRunStart = clock();
	_tRunCur = clock();

	_tCycleInit = clock();
	_tCycleCur = clock();

	_nPosX = 45;
	_nPosY = 10;
	_nWidth = 7;
	_nHeight = 6;
}

Timer::~Timer()
{

}
