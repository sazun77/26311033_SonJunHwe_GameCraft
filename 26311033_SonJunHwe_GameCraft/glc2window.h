#pragma once

#include <vector>
#include "glc2d.h"
#include "glc2image.h"

enum
{
	// 마우스 이벤트 (0: LButton, 1: RButton, 2: MButton)
	LButton=0,
	RButton=1,
	MButton=2,
	//
	GAMETICK = 300,
	SUCCESS=1,

	WINDOWX=960,
	WINDOWY=540,
};

 int AppRender();
 int AppFrameMove();
 int AppKeyboard(uint8_t* keyP);
 int AppMouse(int x,int y, int z,int event);

class glc2window
{

public:
	int Render();
	int FrameMove();
	int Keyboard(uint8_t* keyP);
	int Mouse(int x, int y, int z, int event);

	void FrameMove_Update();
	void FrameMove_Mouse();
	void FrameMove_Keyboard();
	//void RenderDetailes();
	void Initialize();
	void Run();
	void Sleep(int delay=GAMETICK);
	void Close();
	void Destroy();
	
	void AddImage(glc2image* glc2image);

	void SetPos(float x, float y);
	void SetPosX(float x);
	void SetPosY(float y);

	float GetPosX();
	float GetPosY();
	int GetWidth();
	int GetHeight();

	
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

	//
	int m_count{};//DEBUG
	std::vector< glc2image*> m_images{};
};

extern glc2window window;
