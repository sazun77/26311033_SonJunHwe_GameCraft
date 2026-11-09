#include <iostream>
#include <thread>
#include <time.h>
#include <vector>
#include "glc2d.h"

#include "glc2window.h"
#include "glc2image.h"
#include "glc2sound.h"
#include "Utility.h"

extern glc2window* selfP{nullptr};

// RenderDetailes은 일종의 update(), main()의 역할인 듯?
int AppRender()
{
	return glc2window::Render();
}
int AppFrameMove()
{
	return glc2window::FrameMove();
}
int AppKeyboard(uint8_t* keyP)
{
	return glc2window::Keyboard(keyP);
}
int AppMouse(int x, int y, int z, int event)
{
	return glc2window::Mouse(x,y,z,event);
}

//
glc2window::glc2window()
{
	selfP = this;
	// SDK 초기화
	DEBUGLOG("Initialliseing SDK\n");
	g2_InitSdk();

	// 윈도우 색 설정.
	DEBUGLOG( "Window color set\n");
	g2_SetClearColor(m_color);

	//화면 출력,update,키보드 이벤트,마우스 이벤트 함수 등록.
	DEBUGLOG( "Set Render\n");
	g2_SetRender(AppRender);
	DEBUGLOG( "Set Update\n");
	g2_SetFrameMove(AppFrameMove);
	DEBUGLOG( "Set Keyboard event\n");
	g2_SetKeyboard(AppKeyboard);
	DEBUGLOG( "Set mouse event\n");
	g2_SetMouse(AppMouse);

	// 윈도우 생성
	DEBUGLOG( "Createing Window\n");
	g2_CreateWin(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_width, m_height, m_name);

	// 윈도우 핸들 받아오기
	// 이거 있어야 창 닫기 가능.
	m_hWnd = g2_GetHwnd();
}
glc2window::~glc2window()
{
	DEBUGLOG("deleting images\n");
	while (!m_images.empty())
	{
		delete m_images.back();
	}
	DEBUGLOG("deleting sounds\n");
	while (!m_sounds.empty())
	{
		delete m_sounds.back();
	}

	DEBUGLOG( "Desroying Window\n");
	g2_DestroyWin();
}
// 위에 있는 것들의 파츠 같은 놈들?
int glc2window::Render()
{
	if(selfP)
	{
		for (auto& image : selfP->m_images)
		{
			image->Draw();
		}
	}

	return SUCCESS;
}
int glc2window::FrameMove()
{
	if (selfP)
	{
		selfP->FrameMove_Mouse();
		selfP->FrameMove_Keyboard();
		selfP->FrameMove_Update();
	}

	return SUCCESS;
}
int glc2window::Keyboard(uint8_t* keyP)
{
	//	DEBUGLOG( keyP << '\n';

	return SUCCESS;
}
int glc2window::Mouse(int x, int y, int z, int event)
{
	// 어째서인지 내부 구조가 작동 안함...
	//DEBUGLOG( x << ' ';
	//DEBUGLOG( y << ' ';
	//DEBUGLOG( z << ' ';
	//DEBUGLOG( event << '\n';
	return SUCCESS;
}

void glc2window::FrameMove_Update()
{

}
void glc2window::FrameMove_afterUpdate()
{

}
void glc2window::FrameMove_Mouse()
{
	m_mouseX = g2_GetMouseX();
	m_mouseY = g2_GetMouseY();
	m_mouseZ = g2_GetMouseZ();

	if (g2_GetMouseEvent(LButton))
	{
		DEBUGLOG( "L click\n");
		m_mouseEvent = LButton;
	}
	else if (g2_GetMouseEvent(RButton))
	{
		DEBUGLOG( "R click\n");
		m_mouseEvent = RButton;
	}
	else if (g2_GetMouseEvent(MButton))
	{
		DEBUGLOG( "M click\n");
		m_mouseEvent = MButton;
	}
	else
	{
		DEBUGLOG( "No click\n");
		//m_mouseEvent = NONE;
	}
}
void glc2window::FrameMove_Keyboard()
{
	m_keyboardP = g2_GetKeyboard();

	for (int i = 9; i < 128; ++i)
	{
		if (m_keyboardP[i])
		{
			DEBUGLOG("You Pressed" << i << " key!!!\n");
			break;
		}
	}
}

void glc2window::Run()
{
	DEBUGLOG( "Running Window\n");
	g2_Run();
}
void glc2window::CheckEscape()
{
	if (m_keyboardP[ESC])
	{
		DEBUGLOG("programend\n");

		Close();
	}
}
//void glc2window::Sleep(int delay)
//{
//	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
//}
void glc2window::Close()
{
	PostMessage(m_hWnd, WM_CLOSE, 0, 0);
}

void glc2window::AddImage(glc2image* glc2image)
{
	m_images.push_back(glc2image);
}

void glc2window::DeleteImage(glc2image* glc2image)
{
	auto targetLocation = find(m_images.begin(), m_images.end(), glc2image);

	if (targetLocation != m_images.end())
	{
		m_images.erase(targetLocation);
	}
}

void glc2window::AddSound(glc2sound* glc2sound)
{
	m_sounds.push_back(glc2sound);
}

void glc2window::DeleteSound(glc2sound* glc2sound)
{
	auto targetLocation = find(m_sounds.begin(), m_sounds.end(), glc2sound);

	if (targetLocation != m_sounds.end())
	{
		m_sounds.erase(targetLocation);
	}
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

