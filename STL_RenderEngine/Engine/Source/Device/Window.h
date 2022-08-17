#pragma once
#include <Core/Core.h>

namespace STL
{

class ENGINE_API Window
	{
public:
	//생성자
	Window(
		HINSTANCE hInstance,
		uint32 width,
		uint32 height,
		const std::wstring& title,
		WNDPROC procedure
	);

	//소멸자
	~Window();

	//창 생성/창 보이기
	void Intialize();

	// Getter
	std::wstring Title() const { return title; } // 짧은 것은 인라인 처리 해준다.
	HINSTANCE Instance() const { return hInstance; }
	HWND Handle() const { return handle; }
	uint32 Width() const { return width; }
	uint32 Height() const { return height; }

	// Setter
	void SetTitle(const std::wstring& newTitle);

private:
	std::wstring className; // 창 등록할 때 사용할 클래스 이름
	std::wstring title;		// 창 제목
	HINSTANCE hInstance;	// 창을 생성하는 프로그램의 포인터(주소)
	HWND handle;			// 생성된 창을 가리키는 포인터(주소)
	uint32 width;			// 창의 가로 크기
	uint32 height;			// 창의 세로 크기
	WNDPROC procedure;		// 창 이벤트(클릭, 키보드 입력 등)를 처리할 함수 포인터

	};

}

