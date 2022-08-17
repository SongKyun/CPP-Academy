#include "Window.h"
#include <exception> // 표쥰 예외

namespace STL
{
	Window::Window(HINSTANCE hInstance, uint32 width, uint32 height,
		const std::wstring& title, WNDPROC procedure)

		: className(L"RenderEngineClass"),
		title(title),
		hInstance(hInstance),
		width(width),
		height(height),
		procedure(procedure),
		handle(nullptr)

	{

	}

	Window::~Window()
	{
		// 클래스 등록 해제
		UnregisterClass(className.c_str(), hInstance);
	}
	void Window::Intialize()
	{
		//창 클래스 설정 및 생성.
        WNDCLASS wc = { }; // 구조체
    //memset(&wc, 0, sizeof(wc));

    // Invoke. 
        wc.lpfnWndProc = procedure; // 콜백(Callback) 윈도우가 우리 함수를 호출해주고 있다. / 위임(Delegate)
        wc.hInstance = hInstance;
        wc.lpszClassName = className.c_str();

        //창 클래스 이름 등록.
        RegisterClass(&wc);

        // Create the window.

        //창 크기 조정 2가지 방법 
        //RECT는 직사각형 구조체, (left, top, right, bottom).
        RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>(height) }; // int를 long으로 형 변환
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

        //조정된 직사각형 크기로 창 가로/세로 크기 구하기
        int windowWidth = rect.right - rect.left;
        int windowHeight = rect.bottom - rect.top;

        //화면 중심에서 창을 그리기 위한 생성좌표 구하기
        // GetSystemMetrics(SM_CXSCREEN) -> 모니터 가로 크기 구하는 함수
        // GetSystemMetrics(SM_CYSCREEN) - > 모니터 세로 크기 구하는 함수
        int xPosition = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
        int yPosition = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;

        handle = CreateWindowEx( //힙에 저장되는 핸들 값
            0,                              // Optional window styles.
            className.c_str(),                     // Window class
            title.c_str(),    // Window text 윈도우 창 텍스트 값
            WS_OVERLAPPEDWINDOW,            // Window style


            // Size and position
            xPosition, yPosition, windowWidth, windowHeight,

            nullptr,       // Parent window
            nullptr,       // Menu
            hInstance,  // Instance handle
            nullptr        // Additional application data
        );

        if (handle == nullptr)
        {
            //예외 처리 - 보이드라 리턴을 안 해서
            //return 0; // 프로그램 종료
            throw std::exception("윈도우 생성 실패!");
        }

        ShowWindow(handle, SW_SHOW); // 윈도우 창 보여주라는 값
        UpdateWindow(handle); // 창을 제대로 갱신해주라는
	}
	void Window::SetTitle(const std::wstring& newTitle)
	{

	}
}
