#pragma once
#include "main.h"
#define FILENAMEMAX 250

class glc2image
{
public:
	void Setup(const char* fileName);
	void RenderMain();
	void End();

	void SetPos(const int x, const int y);

	int GetWidth();
	int GetHeight();
	int GetIndex();
	int GetX();
	int GetY();
private:
	int m_imageIdx{};
	int m_width{};
	int m_height{};
	VEC2 m_pos{};

	char m_image[FILENAMEMAX]{};
};

