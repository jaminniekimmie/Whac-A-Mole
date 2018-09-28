#pragma once
#include "gameNode.h"

//��� (������ ����, ������ �ʴ� ����)
//1. const
//2. #define

//�ڽ����� ��ũ��
#define BOXMAX 8

//�ڽ� ����ü
struct ellipse
{
	int dia;
	int x;
	int y;
	int r, g, b;
};
struct exBox
{
	RECT rc;
	bool isHit;
	bool isActive;
	int num;
	int width;
	int height;
	int r, g, b;
};
struct tagBox
{
	RECT rc;
	bool isHit;
	bool isActive;
	bool growing;
	int num;
	int width;
	int height;
	int speed;
	int r, g, b;
	RECT headRc;
	RECT baseRc;
	ellipse head;
	ellipse base;
	ellipse body;
	ellipse nose;
	ellipse foot[2];
	ellipse eye[2];
	ellipse wing[2];
	ellipse mouth[2];
	ellipse comb;
	ellipse underMouth;
	ellipse upperMouth;
};

class mainGame : public gameNode
{
private:
	HDC memDC, backDC;
	HBITMAP backGround;
	HBITMAP hBit, backBitMap;
	RECT crt;
	tagBox _g[BOXMAX];
	int count;
	int holdCt;
	int randNo;
	int randSpeed;
	int darkEyeR, darkEyeG, darkEyeB;
	int lightPurpleR, lightPurpleG, lightPurpleB;
	int chickR, chickG, chickB;
	int adultR, adultG, adultB;
	int pigeonR, pigeonG, pigeonB;
	bool _isGameover;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	mainGame() {}
	~mainGame() {}
};
