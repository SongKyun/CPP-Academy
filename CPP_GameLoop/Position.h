#pragma once

struct Position
{
	//����ü�� ���� ������(������)�� �������� ������
	//public �� �⺻ ����ȴ�

	Position(int x = 0, int y = 0)
		: x(x), y(y)
	{
	}

	int x;
	int y;
};