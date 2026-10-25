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

using namespace std;

typedef enum PHASE
{
	BATTLE_START_FORE,
	BATTLE_START,
	TURN_START_FORE,
	TURN_START,
	ACTION_FORE,
	ACTION_START,
	ATTACK_FORE,
	ATTACK_START,
	GETHIT,
	ATTACK_HIT,
	DIED,
	KILLED,
	ATTACK_END,
	TURN_END,
	BATTLE_END,
}PHASE;