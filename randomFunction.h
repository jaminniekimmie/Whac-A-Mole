#pragma once
#include "singletonBase.h"
#include <time.h>
//=============================================================
//	## randomFunction ## (·£´ýÆã¼Ç)
//=============================================================

class randomFunction : public singletonBase <randomFunction>
{
public:
	randomFunction()
	{
		//srand(time(NULL));
		srand(GetTickCount());
	}
	~randomFunction() {}

	HRESULT init() { return S_OK; }
	void release() {}

	//GetInt
	inline int getInt(int num) { return rand() % num; }
	//GetFromIntTo
	inline int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}
};

