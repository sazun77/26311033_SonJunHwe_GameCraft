#pragma once

#include <vector>
#include "glc2d.h"
#include "glc2image.h"

enum
{
	FAILED = 0,
	SUCCESS = 1,

	GAMETICK = 300,

	WINDOWX = 960,
	WINDOWY = 540,
};

typedef enum MOUSEEVENT
{
	// 마우스 이벤트 (0: LButton, 1: RButton, 2: MButton)
	LButton = 0,
	RButton = 1,
	MButton = 2,
	NONE = -1,
}mouse;

 int AppRender();
 int AppFrameMove();
 int AppKeyboard(uint8_t* keyP);
 int AppMouse(int x,int y, int z,int event);

class glc2window
{

public:
	int Render(); // CLEAR.
	int FrameMove(); // CLEAR.
	int Keyboard(uint8_t* keyP); // CLEAR.
	int Mouse(int x, int y, int z, int event); // CLEAR.

	void FrameMove_Update();
	void FrameMove_Mouse();
	void FrameMove_Keyboard();
	//void RenderDetailes();
	void Initialize(); // CLEAR.
	void Run(); // CLEAR.
	void Sleep(int delay=GAMETICK); // CLEAR.
	void Close(); // CLEAR.
	void Destroy(); // CLEAR.
	
	void AddImage(glc2image* glc2image);
	void DeleteImage(glc2image* glc2image);

	void SetPos(float x, float y);// CLEAR.
	void SetPosX(float x);// CLEAR.
	void SetPosY(float y);// CLEAR.

	float GetPosX(); // CLEAR.
	float GetPosY();// CLEAR.
	int GetWidth();// CLEAR.
	int GetHeight();// CLEAR.

	
private:
	HWND m_hWnd{};
	VEC2 m_pos{};
	const int m_width{960};
	const int m_height{ 540 };
	const char* m_name{ "PressSpace" };

	const int m_color{ 0x77777777 };
	//mouse
	int m_mouseX{};
	int m_mouseY{};
	int m_mouseZ{};
	mouse m_mouseEvent{};
	//
	int m_count{};//DEBUG
	std::vector< glc2image*> m_images{};
};

extern glc2window window;
