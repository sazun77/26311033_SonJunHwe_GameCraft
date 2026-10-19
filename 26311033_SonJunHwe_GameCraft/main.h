#pragma once
#include <glc2d.h>

#if defined(_DEBUG)
#if defined(_M_X64)
#pragma comment(lib, "glc2d_x64_debug.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "glc2d_win32_debug.lib")
#endif
#else
#if defined(_M_X64)
#pragma comment(lib, "glc2d_x64_release.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "glc2d_win32_release.lib")
#endif
#endif

#include <string>
#include <vector>
#include <iostream>
#include "glc2image.h"
#include "glc2sound.h"
#include "glc2window.h"

using namespace std;