#include "Window.h"
#include <exception> // ǥ�� ����

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
		// Ŭ���� ��� ����
		UnregisterClass(className.c_str(), hInstance);
	}
	void Window::Intialize()
	{
		//â Ŭ���� ���� �� ����.
        WNDCLASS wc = { }; // ����ü
    //memset(&wc, 0, sizeof(wc));

    // Invoke. 
        wc.lpfnWndProc = procedure; // �ݹ�(Callback) �����찡 �츮 �Լ��� ȣ�����ְ� �ִ�. / ����(Delegate)
        wc.hInstance = hInstance;
        wc.lpszClassName = className.c_str();

        //â Ŭ���� �̸� ���.
        RegisterClass(&wc);

        // Create the window.

        //â ũ�� ���� 2���� ��� 
        //RECT�� ���簢�� ����ü, (left, top, right, bottom).
        RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>(height) }; // int�� long���� �� ��ȯ
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

        //������ ���簢�� ũ��� â ����/���� ũ�� ���ϱ�
        int windowWidth = rect.right - rect.left;
        int windowHeight = rect.bottom - rect.top;

        //ȭ�� �߽ɿ��� â�� �׸��� ���� ������ǥ ���ϱ�
        // GetSystemMetrics(SM_CXSCREEN) -> ����� ���� ũ�� ���ϴ� �Լ�
        // GetSystemMetrics(SM_CYSCREEN) - > ����� ���� ũ�� ���ϴ� �Լ�
        int xPosition = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
        int yPosition = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;

        handle = CreateWindowEx( //���� ����Ǵ� �ڵ� ��
            0,                              // Optional window styles.
            className.c_str(),                     // Window class
            title.c_str(),    // Window text ������ â �ؽ�Ʈ ��
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
            //���� ó�� - ���̵�� ������ �� �ؼ�
            //return 0; // ���α׷� ����
            throw std::exception("������ ���� ����!");
        }

        ShowWindow(handle, SW_SHOW); // ������ â �����ֶ�� ��
        UpdateWindow(handle); // â�� ����� �������ֶ��
	}
	void Window::SetTitle(const std::wstring& newTitle)
	{

	}
}
