#include <time.h>
#include <thread>
#include <iostream>
#include "myheader.h"
#include "glc2window.h"
#include "glc2image.h"
#include "glc2d.h"

extern glc2window window;

float testPos{ 0.0f };
// 랜더 함수. RenderDetailes를 호출함.
// RenderDetailes은 일종의 update(), main()의 역할인 듯?
int RenderMain()
{
	const KEYCODE* pKey = g2_GetKeyboard();

	/*if (pKey[VK_SPACE])
	{
		std::cout << "sound Played." << pKey << '\n';
		testSound.SoundPlay();

		window.m_images[0].SetPos(g2_GetMouseX(), g2_GetMouseY());
	}*/

	std::this_thread::sleep_for(std::chrono::milliseconds(GAMETICK));
	return window.RenderDetailes();
}
int glc2window::RenderDetailes()
{
	std::cout << "Rendering start..." << time(NULL) << '\n';

	for (auto& image : m_images)
	{
		image.Main();
	}

	return SUCCESS;
}

void glc2window::Setup()
{
	// SDK 초기화
	std::cout << "Initialliseing SDK\n";
	g2_InitSdk();
	// 윈도우 색 설정.
	std::cout << "Window color set\n";
	g2_SetClearColor(m_color);
	//화면 출력 함수 등록.
	g2_SetRender(RenderMain);
	// 윈도우 생성
	std::cout << "Createing Window\n";



	g2_CreateWin(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_width, m_height, m_name);

	// 씬 셋업.
	std::cout << "Scene Graphic setup\n";
}

void glc2window::Run()
{
	std::cout << "Running Window\n";
	g2_Run();	// 여기서 명령을 추가로 하는 법을 모르겠음.
	std::cout << "Running End\n";
}

void glc2window::Destroy()
{
	std::cout << "Desroying Window\n";
	g2_DestroyWin();
}

// 초기 좌표를 입력하지 않을 경우 초기 좌표는 (0,0)으로 설정됩니다.
// 추가된 요소가 몇 번째 인덱스인지를 반환합니다.
int glc2window::SetImageNew(const char* fileP, const int x, const int y)
{
	glc2image td{};
	td.Setup(fileP);
	td.SetPos(x, y);

	m_images.push_back(td);

	return static_cast<int>(m_images.size()) - 1;
}

void glc2window::SetImagePos(const int imageIdx, const int x, const int y)
{
	m_images[imageIdx].SetPos(x, y);
}

int glc2window::GetWidth()
{
	return m_width;
}
int glc2window::GetHeight()
{
	return m_height;
}

int glc2window::GetImageWidth(const int imageIdx)
{
	return m_images[imageIdx].GetWidth();
}

int glc2window::GetImageHeight(const int imageIdx)
{
	return m_images[imageIdx].GetHeight();
}

int glc2window::GetImageX(const int imageIdx)
{
	return m_images[imageIdx].GetX();
}

int glc2window::GetImageY(const int imageIdx)
{
	return m_images[imageIdx].GetY();
}
