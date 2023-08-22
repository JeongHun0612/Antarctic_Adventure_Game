#include "Player.h"

Player::Player()
{
	_Shadow = Shadow();
	_Shadow.setCurrentDot(0);

	_nPosX = SCR_WIDTH / 2 - 16;
	_nPosY = SCR_HEIGHT - 37;
	_nTempPosY = SCR_HEIGHT - 37;
	_nWidth = 32;
	_nHeight = 32;
	_nSpeed = 10;
	_currentDot = _moveDot[0];
	_state = EState::MOVE;

	_moveTime = 0;
	_jumpTime = 0;
	_collisionTime = 0;

	_bIsJumping = false;
	_bIsJumpped = false;
	_bIsCollsion = false;
}

Player::~Player()
{

}

void Player::move()
{
	if (_state != EState::COLLISION)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (_nPosX > 60)
			{
				_nPosX--;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			if (_nPosX < 138)
			{
				_nPosX++;
			}
		}
	}
}

void Player::jump()
{
	// 점프 키를 눌렀을 때
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 && !_bIsJumping)
	{
		_bIsJumping = true;
		_state = EState::JUMP;
		_Shadow.setCurrentDot(_bIsJumping);
	}

	if (_bIsJumping)
	{
		// 위로 상승
		if (_nPosY > MAX_JUMP && !_bIsJumpped)
		{
			_nPosY--;
		}
		// 점프완료
		else if (_bIsJumpped && _nPosY == _nTempPosY)
		{
			_bIsJumping = false;
			_bIsJumpped = false;
			_state = EState::MOVE;
			_Shadow.setCurrentDot(_bIsJumping);
		}
		// 아래로 하강
		else if (_bIsJumpped)
		{
			_nPosY++;
		}
		// 최대 높이 도착
		else if (_nPosY == MAX_JUMP)
		{
			_bIsJumpped = true;
		}
	}
}

void Player::collison(Obstacle** _Obstacle)
{
	for (int i = 0; i < MAX_Obstacle; i++)
	{
		if (_Obstacle[i] != NULL)
		{
			if (_Obstacle[i]->geObstacleX() < _nPosX + (_nWidth - 10) && _Obstacle[i]->geObstacleX() +_Obstacle[i]->getObstacleWidth() > _nPosX + 8)
			{
				switch (_Obstacle[i]->getObstacleTyep())
				{
				case EObstacleType::HOLE:
					if ((_nPosY + _nHeight) - 10 < _Obstacle[i]->getObstacleY() && !_bIsJumping)
					{
						// 충돌
						_bIsCollsion = true;
						_state = EState::COLLISION;
						_nSpeed = 1;
						delete(_Obstacle[i]);
						_Obstacle[i] = NULL;
					}
					break;

				case EObstacleType::FLAG:
					if (_nPosY < _Obstacle[i]->getObstacleY() + (_Obstacle[i]->getObstacleHeight() / 2))
					{
						_nScore += 10;
						delete(_Obstacle[i]);
						_Obstacle[i] = NULL;
					}
					break;
				default:
					break;
				}
			}
		}
	}
}

void Player::changeAnim()
{
	switch (_state)
	{
	case EState::MOVE:
		if (_moveTime == 24)
		{
			_moveTime = 0;
		}
		setCurrentDot(_moveDot[_moveTime / 6]);
		_moveTime++;
		break;

	case EState::JUMP:
		if (_jumpTime == 6)
		{
			_jumpTime = 0;
		}
		setCurrentDot(_jumpDot[_jumpTime / 1]);
		_jumpTime++;
		break;

	case EState::COLLISION:
		if (_collisionTime == 32)
		{
			_collisionTime = 0;
			_state = EState::MOVE;
			_nSpeed = 10;
		}

		if ((_collisionTime / 8) % 2 != 0)
		{
			_nPosX++;
			_nPosY++;
		}
		else
		{
			_nPosY--;
		}

		setCurrentDot(_collisionDot[0]);
		_collisionTime++;
		break;
	}
}