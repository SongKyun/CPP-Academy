#pragma once
#include <Core/Core.h>

namespace STL
{

class ENGINE_API Window
	{
public:
	//������
	Window(
		HINSTANCE hInstance,
		uint32 width,
		uint32 height,
		const std::wstring& title,
		WNDPROC procedure
	);

	//�Ҹ���
	~Window();

	//â ����/â ���̱�
	void Intialize();

	// Getter
	std::wstring Title() const { return title; } // ª�� ���� �ζ��� ó�� ���ش�.
	HINSTANCE Instance() const { return hInstance; }
	HWND Handle() const { return handle; }
	uint32 Width() const { return width; }
	uint32 Height() const { return height; }

	// Setter
	void SetTitle(const std::wstring& newTitle);

private:
	std::wstring className; // â ����� �� ����� Ŭ���� �̸�
	std::wstring title;		// â ����
	HINSTANCE hInstance;	// â�� �����ϴ� ���α׷��� ������(�ּ�)
	HWND handle;			// ������ â�� ����Ű�� ������(�ּ�)
	uint32 width;			// â�� ���� ũ��
	uint32 height;			// â�� ���� ũ��
	WNDPROC procedure;		// â �̺�Ʈ(Ŭ��, Ű���� �Է� ��)�� ó���� �Լ� ������

	};

}

