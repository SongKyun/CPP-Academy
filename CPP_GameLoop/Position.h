#pragma once

struct Position
{
	//구조체는 접근 제한자(한정자)를 지정하지 않으면
	//public 이 기본 적용된다

	Position(int x = 0, int y = 0)
		: x(x), y(y)
	{
	}

	int x;
	int y;
};