#include "Util.h"

// 헤더 <-> cpp 파일 이동
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
		// 프로그램 실행을 1/1000 초 단위로 지정
		Sleep(milliseconds);
	}

	void SetPosition(short x, short y)
	{
		COORD position = { x,y };

		// 콘솔창의 커서를 이동시키는 함수
		SetConsoleCursorPosition(
			// 핸들(handle) 값 구하기 , 위치
			GetStdHandle(STD_OUTPUT_HANDLE), position
		);
	}
}