#pragma once

#ifdef ENGINE_BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

// ��� ��Ŭ���.
#include <Windows.h>
#include <string>
#include <vector>
#include <memory>


#include <d3d11.h>
#include <d3dcompiler.h>


// Ÿ�� ������
using uint32 = unsigned int;
using uint64 = unsigned __int64;
using int64 = __int64;

// ���ø� �Լ�
// com ��ü �޸� ����
template<typename Type>
void SafeRelease(Type t)
{
	if (t != nullptr)
	{
		t->Release();
		t = nullptr;
	}
}