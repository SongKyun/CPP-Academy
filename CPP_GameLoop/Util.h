#pragma once

#include <Windows.h>

namespace Util
{
	//ȭ�� �����.
	void ClearScreen();

	// 1/1000�� ������ ������ ���(����)�ϴ� ���.
	void Delay(unsigned long milliseconds);

	// �ܼ� ȭ���� ��ǥ�� �̵��� �� ���.
	void SetPosition(short x, short y);
}	