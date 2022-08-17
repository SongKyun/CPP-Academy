#include "Util.h"

// ��� <-> cpp ���� �̵�
// Ctrl + K / Ctrl + O
namespace Util
{
	void ClearScreen()
	{
		// cls -> clear screen.
		system("cls");
	}

	void Delay(unsigned long milliseconds)
	{
		// ���α׷� ������ 1/1000 �� ������ ����
		Sleep(milliseconds);
	}

	void SetPosition(short x, short y)
	{
		COORD position = { x,y };

		// �ܼ�â�� Ŀ���� �̵���Ű�� �Լ�
		SetConsoleCursorPosition(
			// �ڵ�(handle) �� ���ϱ� , ��ġ
			GetStdHandle(STD_OUTPUT_HANDLE), position
		);
	}
}