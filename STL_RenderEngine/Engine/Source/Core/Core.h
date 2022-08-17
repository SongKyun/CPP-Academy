#pragma once

#ifdef ENGINE_BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

// 헤더 인클루드.
#include <Windows.h>
#include <string>
#include <vector>
#include <memory>


#include <d3d11.h>
#include <d3dcompiler.h>


// 타입 재정의
using uint32 = unsigned int;
using uint64 = unsigned __int64;
using int64 = __int64;

// 템플릿 함수
// com 객체 메모리 해제
template<typename Type>
void SafeRelease(Type t)
{
	if (t != nullptr)
	{
		t->Release();
		t = nullptr;
	}
}