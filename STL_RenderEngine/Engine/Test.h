#pragma once

#include <Windows.h>
#include "Source/Core/Core.h"
//#include <Core/Core.h>
#include "Core/Core.h"

//이름 공간.
//구분 짓고 싶을 때 사용
namespace STL
{
	/*__declspec(dllexport)*/ ENGINE_API void Show(const wchar_t* message);
}

