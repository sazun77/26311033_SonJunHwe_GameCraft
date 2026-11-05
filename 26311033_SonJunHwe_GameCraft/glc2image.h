#pragma once

// include the 2d game header file
#include "glc2d.h"
#include <stdio.h>
#include <string>

#define INPUT_NULL -777.7f

class glc2window;

enum
{
	FILENAMEMAX = 300,
	VISIBLE = 1,
	INVISIBLE = 0,
};

class glc2image
{
public:
	glc2image(glc2window* windowP,CSTR filename, const float x = INPUT_NULL, const float y = INPUT_NULL);
	//void Initialize(int sprite);
	void Draw();
	~glc2image();
	//void Release();

	void SetAlpha(int alpha);
	void SetPos(const float x, const float y);
	void SetPosX(const float x);
	void SetPosY(const float y);

	int GetIndex();
	int GetWidth();
	int GetHeight();
	float GetPosX();
	float GetPosY();

private:
	int m_spriteIdx{};
	int m_width{};
	int m_height{};
	int m_alpha{VISIBLE};//투명도(밝기) 관련.


	glc2window* m_windowP{};
	VEC2 m_pos{};

	//const char* m_imageP{};
};

//int RenderMain()
//{
//	VEC2 pos(400, 200);
//
//	g2_Draw2D(nTx, NULL, &pos);
//
//	return 0;
//}