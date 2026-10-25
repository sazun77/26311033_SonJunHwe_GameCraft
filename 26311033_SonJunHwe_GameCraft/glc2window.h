#pragma once
#include <vector>
#include "glc2image.h"

int RenderMain();

class glc2window
{
public:
	int RenderDetailes();

	void Setup();
	void Run();
	void Destroy();

	int SetImageNew(const char* fileP, const int x = {}, const int y = {});
	void SetImagePos(const int imageIdx, const int x, const int y);

	int GetWidth();
	int GetHeight();

	int GetImageWidth(const int imageIdx);
	int GetImageHeight(const int imageIdx);
	int GetImageX(const int imageIdx);
	int GetImageY(const int imageIdx);
private:
	VEC2 m_pos{};
	const int m_width{ 1280 };
	const int m_height{ 720 };
	const char* m_name{ "PressSpace" };

	const int m_color{ 0x77777777 };
public:
	std::vector<glc2image> m_images{};	// 나중에 그냥 포인터 추가하는 형식으로 바꿔야 할 듯.
};