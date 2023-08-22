#include "Shadow.h"

Shadow::Shadow()
{
	_nPosY = SCR_HEIGHT - 11;
	_nWidth = 32;
	_nHeight = 6;

	_currentDot = _shadowDot[0];
}

Shadow::~Shadow()
{

}