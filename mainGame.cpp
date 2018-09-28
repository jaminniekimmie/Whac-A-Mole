#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//   ## 초기화 ## init(void)
//=============================================================
HRESULT mainGame::init(void)
{
	gameNode::init();
	//이곳에서 초기화를 한다

	//박스 구조체 초기화

	count = 0;
	holdCt = 0;
	chickR = 255;
	chickG = 217;
	chickB = 54;
	adultR = 255;
	adultG = 255;
	adultB = 255;
	pigeonR = 65;
	pigeonG = 43;
	pigeonB = 79;
	darkEyeR = 1;
	darkEyeG = 1;
	darkEyeB= 1;
	lightPurpleR = 190;
	lightPurpleG = 194;
	lightPurpleB = 206;


	for (int i = 0; i < BOXMAX; i++)
	{
		_g[i].isHit = false;
		_g[i].isActive = false;
		_g[i].growing = false;
		_g[i].width = 75;
		_g[i].speed = 1;
		_g[i].height = _g[i].width;
		_g[0].rc = RectMakeCenter(WINSIZEX / (BOXMAX + 2) * 4, WINSIZEY / (BOXMAX + 2) * 3 + _g[0].width / 2, _g[0].width, _g[0].height);
		_g[1].rc = RectMakeCenter(WINSIZEX / (BOXMAX + 2) * 6, WINSIZEY / (BOXMAX + 2) * 3 + _g[1].width / 2, _g[1].width, _g[1].height);
		_g[2].rc = RectMakeCenter(WINSIZEX / (BOXMAX + 2) * 3, WINSIZEY / (BOXMAX + 2) * 4 + _g[2].width / 2, _g[2].width, _g[2].height);
		_g[3].rc = RectMakeCenter(WINSIZEX / (BOXMAX + 2) * 5, WINSIZEY / (BOXMAX + 2) * 4 + _g[3].width / 2, _g[3].width, _g[3].height);
		_g[4].rc = RectMakeCenter(WINSIZEX / (BOXMAX + 2) * 7, WINSIZEY / (BOXMAX + 2) * 4 + _g[4].width / 2, _g[4].width, _g[4].height);
		_g[5].rc = RectMakeCenter(WINSIZEX / (BOXMAX + 2) * 4, WINSIZEY / (BOXMAX + 2) * 5 + _g[5].width / 2, _g[5].width, _g[5].height);
		_g[6].rc = RectMakeCenter(WINSIZEX / (BOXMAX + 2) * 6, WINSIZEY / (BOXMAX + 2) * 5 + _g[6].width / 2, _g[6].width, _g[6].height);
		_g[7].rc = RectMakeCenter(WINSIZEX / (BOXMAX + 2) * 5, WINSIZEY / (BOXMAX + 2) * 6 + _g[7].width / 2, _g[7].width, _g[7].height);
		_g[i].r = 144;
		_g[i].g = 92;
		_g[i].b = 70;
		_g[i].head.dia = _g[i].width;
		_g[i].head.x = _g[i].rc.left + (_g[i].rc.right - _g[i].rc.left) / 2;
		_g[i].head.y = _g[i].rc.top;
		_g[i].head.r = chickR;
		_g[i].head.g = chickG;
		_g[i].head.b = chickB;
		_g[i].headRc = RectMakeCenter(_g[i].head.x, _g[i].head.y, _g[i].head.dia, _g[i].head.dia);
		_g[i].body.dia = _g[i].width * 1.2;
		_g[i].body.x = _g[i].rc.left + (_g[i].rc.right - _g[i].rc.left) / 2;
		_g[i].body.y = _g[i].rc.top + _g[i].body.dia / 2;
		_g[i].base.dia = _g[i].width;
		_g[i].base.x = _g[i].rc.left + (_g[i].rc.right - _g[i].rc.left) / 2;
		_g[i].base.y = _g[i].rc.bottom;
		_g[i].baseRc = RectMakeCenter(_g[i].base.x, _g[i].base.y, _g[i].base.dia, _g[i].base.dia);
		for (int k = 0; k < 2; k++)
		{
			_g[i].eye[k].dia = _g[i].head.dia / 9;
			_g[i].eye[0].x = _g[i].head.x - _g[i].eye[0].dia * 1.8;
			_g[i].eye[1].x = _g[i].head.x + _g[i].eye[1].dia * 1.8;
			_g[i].eye[k].y = _g[i].head.y - _g[i].eye[k].dia * 1;
			_g[i].eye[k].r = darkEyeR;
			_g[i].eye[k].g = darkEyeG;
			_g[i].eye[k].b = darkEyeB;
		}
		for (int k = 0; k < 2; k++)
		{
			_g[i].mouth[k].dia = _g[i].eye[k].dia;
			_g[i].mouth[k].x = _g[i].head.x;
			_g[i].mouth[0].y = _g[i].eye[k].y + _g[i].mouth[k].dia;
			_g[i].mouth[1].y = _g[i].mouth[0].y + _g[i].mouth[1].dia / 2;
			_g[i].mouth[k].r = 239;
			_g[i].mouth[k].g = 123;
			_g[i].mouth[k].b = 0;
		}
		_g[i].comb.dia = 0;
		_g[i].comb.x = _g[i].head.x;
		_g[i].comb.y = _g[i].headRc.top;
		_g[i].comb.r = 240;
		_g[i].comb.g = 61;
		_g[i].comb.b = 42;
		_g[i].underMouth.dia = 0;
		_g[i].underMouth.x = _g[i].mouth[1].x;
		_g[i].underMouth.y = _g[i].mouth[1].y + _g[i].underMouth.dia / 2;
		_g[i].upperMouth.dia = 0;
		_g[i].upperMouth.x = _g[i].mouth[1].x;
		_g[i].upperMouth.y = _g[i].mouth[1].y - _g[i].upperMouth.dia / 2;
		_g[i].upperMouth.r = lightPurpleR;
		_g[i].upperMouth.g = lightPurpleG;
		_g[i].upperMouth.b = lightPurpleB;
	}

	//게임오버
	_isGameover = false;

	return S_OK;
}

//=============================================================
//   ## 해제 ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();
	//이미지 클래스 나갈때까진 사용할 일 없다
	//init함수에서 동적할당 new를 사용했다면 이곳에서 delete 사용한다
}

//=============================================================
//   ## 업데이트 ## update(void)
//=============================================================
void mainGame::update(void)
{
	gameNode::update();
	//이곳에서 계산식, 키보드, 마우스등등 업데이트를 한다
	//간단하게 이곳에서 코딩한다고 생각하면 된다

	++count;
	randNo = RND->getInt(BOXMAX);

	if (count % BOXMAX == randNo)
	{
		if (_g[randNo].isActive)
		{
			randSpeed = RND->getFromIntTo(1, 5);
			count = 0;
			_g[randNo].isActive = false;
		}
		else
		{
			randSpeed = RND->getFromIntTo(1, 5);
			count = 0;
			_g[randNo].growing = true;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < BOXMAX; i++)
		{
			//같은것 체크하지 않도록 컨티뉴
			if (!_g[i].isActive) continue;

			//충돌처리
			if (PtInRect(&_g[i].rc, _ptMouse) || PtInRect(&_g[i].headRc, _ptMouse) || PtInRect(&_g[i].baseRc, _ptMouse))
			{
				_g[i].isHit = true;
				if (_g[i].head.b == chickB)
				{
					_g[i].head.r = adultR;
					_g[i].head.g = adultG;
					_g[i].head.b = adultB;
					_g[i].comb.dia = _g[i].mouth[0].dia * 1.5;
					_g[i].underMouth.dia = _g[i].mouth[0].dia * 1.5;
				}
				else if (_g[i].head.b == adultB || _g[i].head.b == pigeonB)
				{
					_g[i].head.r = chickR;
					_g[i].head.g = chickG;
					_g[i].head.b = chickB;
					_g[i].eye[0].r = darkEyeR;
					_g[i].eye[0].g = darkEyeG;
					_g[i].eye[0].b = darkEyeB;
					_g[i].upperMouth.dia = 0;
					_g[i].comb.dia = 0;
					_g[i].underMouth.dia = 0;
				}
				break;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		for (int i = 0; i < BOXMAX; i++)
		{
			//같은것 체크하지 않도록 컨티뉴
			if (!_g[i].isActive) continue;

			//충돌처리
			if (PtInRect(&_g[i].rc, _ptMouse) || PtInRect(&_g[i].headRc, _ptMouse) || PtInRect(&_g[i].baseRc, _ptMouse))
			{
				_g[i].isHit = true;
				if (_g[i].head.b == chickB || _g[i].head.b == adultB)
				{
					_g[i].head.r = pigeonR;
					_g[i].head.g = pigeonG;
					_g[i].head.b = pigeonB;
					_g[i].eye[0].r = chickR;
					_g[i].eye[0].g = chickG;
					_g[i].eye[0].b = chickB;
					_g[i].upperMouth.dia = _g[i].mouth[0].dia * 1.5;
					_g[i].comb.dia = 0;
					_g[i].underMouth.dia = 0;
				}
				else if (_g[i].head.b == pigeonB)
				{
					_g[i].head.r = chickR;
					_g[i].head.g = chickG;
					_g[i].head.b = chickB;
					_g[i].eye[0].r = darkEyeR;
					_g[i].eye[0].g = darkEyeG;
					_g[i].eye[0].b = darkEyeB;
					_g[i].upperMouth.dia = 0;
				}
				break;
			}
		}
	}

	for (int i = 0; i < BOXMAX; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			if (_g[i].isHit)
			{
				_g[i].rc.top = _g[i].rc.bottom;
				_g[i].isHit = false;
				_g[i].isActive = false;
			}
			if (_g[i].growing)
			{
				_g[i].isActive = true;
				_g[i].rc.top -= randSpeed;
				_g[i].head.y = _g[i].rc.top;
				if (_g[i].rc.bottom - _g[i].rc.top >= _g[i].width)
				{
					_g[i].rc.top = _g[i].rc.bottom - _g[i].width;
					_g[i].growing = false;
				}
			}
			else if (!_g[i].isActive)
			{
				_g[i].rc.top += randSpeed;
				_g[i].head.y = _g[i].rc.top;
				if (_g[i].rc.top >= _g[i].rc.bottom)
					_g[i].rc.top = _g[i].rc.bottom;
			}
			_g[i].headRc = RectMakeCenter(_g[i].head.x, _g[i].head.y, _g[i].head.dia, _g[i].head.dia);
			_g[i].comb.y = _g[i].headRc.top;
			_g[i].underMouth.y = _g[i].mouth[1].y + _g[i].underMouth.dia / 2;
			_g[i].upperMouth.y = _g[i].mouth[1].y - _g[i].upperMouth.dia / 2;
			_g[i].eye[k].y = _g[i].head.y - _g[i].eye[k].dia * 1;
			_g[i].mouth[0].y = _g[i].eye[k].y + _g[i].mouth[k].dia;
			_g[i].mouth[1].y = _g[i].mouth[0].y + _g[i].mouth[1].dia / 2;
		}
	}

	if (_isGameover)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			this->init();
		}
	}

}

//=============================================================
//   ## 렌더 ## render(HDC hdc)
//=============================================================
void mainGame::render(HDC hdc)
{
	//HBRUSH myBrush, oldBrush;
	//HPEN myPen, oldPen;

	memDC = CreateCompatibleDC(hdc);
	backBitMap = CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	hBit = (HBITMAP)SelectObject(memDC, backBitMap);
	backDC = CreateCompatibleDC(hdc);
	GetClientRect(_hWnd, &crt);
	FillRect(memDC, &crt, GetSysColorBrush(COLOR_WINDOW));

	SelectObject(memDC, GetStockObject(DC_BRUSH));
	SelectObject(memDC, GetStockObject(NULL_PEN));
	SetDCBrushColor(memDC, RGB(_g[0].mouth[0].r, _g[0].mouth[0].g, _g[0].mouth[0].b));
	Rectangle(memDC, 0, 0, WINSIZEX, WINSIZEY);

	for (int i = 0; i < BOXMAX; i++)
	{
		SetDCBrushColor(memDC, RGB(_g[i].head.r, _g[i].head.g, _g[i].head.b));
		Rectangle(memDC, _g[i].rc);
		EllipseMakeCenter(memDC, _g[i].base.x, _g[i].base.y, _g[i].base.dia, _g[i].base.dia);
		EllipseMakeCenter(memDC, _g[i].head.x, _g[i].head.y, _g[i].head.dia, _g[i].head.dia);

		SetDCBrushColor(memDC, RGB(_g[i].eye[0].r, _g[i].eye[0].g, _g[i].eye[0].b));
		EllipseMakeCenter(memDC, _g[i].eye[0].x, _g[i].eye[0].y, _g[i].eye[0].dia, _g[i].eye[0].dia);
		EllipseMakeCenter(memDC, _g[i].eye[1].x, _g[i].eye[1].y, _g[i].eye[1].dia, _g[i].eye[1].dia);

		SetDCBrushColor(memDC, RGB(_g[i].comb.r, _g[i].comb.g, _g[i].comb.b));
		EllipseMakeCenter(memDC, _g[i].comb.x, _g[i].comb.y, _g[i].comb.dia, _g[i].comb.dia * 2);
		EllipseMakeCenter(memDC, _g[i].underMouth.x, _g[i].underMouth.y, _g[i].underMouth.dia, _g[i].underMouth.dia);

		SetDCBrushColor(memDC, RGB(_g[i].upperMouth.r, _g[i].upperMouth.g, _g[i].upperMouth.b));
		EllipseMakeCenter(memDC, _g[i].upperMouth.x, _g[i].upperMouth.y, _g[i].upperMouth.dia, _g[i].upperMouth.dia);

		SetDCBrushColor(memDC, RGB(_g[0].mouth[0].r, _g[0].mouth[0].g, _g[0].mouth[0].b));
		EllipseMakeCenter(memDC, _g[i].mouth[0].x, _g[i].mouth[0].y, _g[i].mouth[0].dia * 2, _g[i].mouth[0].dia);
		EllipseMakeCenter(memDC, _g[i].mouth[1].x, _g[i].mouth[1].y, _g[i].mouth[1].dia * 2, _g[i].mouth[1].dia);
	}

	DeleteObject(backDC);
	BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, memDC, 0, 0, SRCCOPY);
	SelectObject(memDC, hBit);
	DeleteObject(backBitMap);
	DeleteDC(memDC);

	//DeleteObject(myPen);
	//DeleteObject(myBrush);
}