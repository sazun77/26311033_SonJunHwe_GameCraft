#include <iostream>
#include <thread>
#include <time.h>
#include "glc2d.h"

#include "glc2window.h"
#include "glc2sound.h"

using std::cout;


glc2window window{};

// RenderDetailes은 일종의 update(), main()의 역할인 듯?
int AppRender()
{
	return window.Render();
}

int AppFrameMove()
{
	return window.FrameMove();
}

int AppKeyboard(uint8_t* keyP)
{
	return window.Keyboard(keyP);
}

int AppMouse(int x, int y, int z, int event)
{
	return window.Mouse(x,y,z,event);
}

int glc2window::Render()
{
	for (auto& image : m_images)
	{
		image->Draw();
	}

	return SUCCESS;
}

int glc2window::FrameMove()
{
	FrameMove_Update();

	FrameMove_Mouse();

	FrameMove_Keyboard();

	Sleep();
	return SUCCESS;
}
void glc2window::FrameMove_Update()
{

}
void glc2window::FrameMove_Mouse()
{
	m_mouseX = g2_GetMouseX();
	m_mouseY = g2_GetMouseY();
	m_mouseZ = g2_GetMouseZ();

	if (g2_GetMouseEvent(LButton))
	{
		cout << "L click\n";
	}
	else if (g2_GetMouseEvent(RButton))
	{
		cout << "R click\n";

	}
	else if (g2_GetMouseEvent(MButton))
	{
		cout << "M click\n";
	}
	else
	{
		cout << "No click\n";
	}
}
void glc2window::FrameMove_Keyboard()
{
	const KEYCODE* pKeyboard = g2_GetKeyboard();

	for (int i = 9; i < 128; ++i)
	{
		if (pKeyboard[i])
		{
			printf("You Pressed %d key!!!\n", i);
		}
	}
}

int glc2window::Keyboard(uint8_t* keyP)
{
	std::cout << keyP << '\n';

	return SUCCESS;
}

int glc2window::Mouse(int x, int y, int z, int event)
{
	std::cout << x << ' ';
	std::cout << y << ' ';
	std::cout << z << ' ';
	std::cout << event << '\n';
	return SUCCESS;
}


void glc2window::Sleep(int delay)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

void glc2window::Close()
{
	PostMessage(m_hWnd, WM_CLOSE, 0, 0);
}

void glc2window::Initialize()
{
	// SDK 초기화
	std::cout << "Initialliseing SDK\n";
	g2_InitSdk();
	
	// 윈도우 색 설정.
	std::cout << "Window color set\n";
	g2_SetClearColor(m_color);
	
	//화면 출력,update,키보드 이벤트,마우스 이벤트 함수 등록.
	std::cout << "Set Render\n";
	g2_SetRender(AppRender);
	std::cout << "Set Update\n";
	g2_SetFrameMove(AppFrameMove);
	std::cout << "Set Keyboard event\n";
	g2_SetKeyboard(AppKeyboard);
	std::cout << "Set mouse event\n";
	g2_SetMouse(AppMouse);
	
	// 윈도우 생성
	std::cout << "Createing Window\n";
	g2_CreateWin(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_width, m_height, m_name);
	
	// 윈도우 핸들 받아오기
	// 이거 있어야 창 닫기 가능.
	m_hWnd = g2_GetHwnd();
}

void glc2window::Run()
{
	std::cout << "Running Window\n";
	g2_Run();	// 여기서 명령을 추가로 하는 법을 모르겠음.
}

void glc2window::Destroy()
{
	std::cout << "Desroying Window\n";
	g2_DestroyWin();
}

void glc2window::AddImage(glc2image* glc2image)
{
	m_images.push_back(glc2image);
}

void glc2window::SetPos(const float x, const float y)
{
	SetPosX(x);
	SetPosY(y);
}

void glc2window::SetPosX(const float x)
{
	m_pos.x = x;
}

void glc2window::SetPosY(const float y)
{
	m_pos.y = y;
}

float glc2window::GetPosX()
{
	return m_pos.x;
}

float glc2window::GetPosY()
{
	return m_pos.y;
}

int glc2window::GetWidth()
{
	return m_width;
}
int glc2window::GetHeight()
{
	return m_height;
}

