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
	GLOW_ON = 1,
	GLOW_OFF = 0,
	VISIBLE = 1,
	INVISIBLE = 1,

};

class glc2image
{
public:
	glc2image(glc2window* windowP,CSTR filename, const float x = INPUT_NULL, const float y = INPUT_NULL);
	//void Initialize(int sprite);
	void Draw();
	~glc2image();
	//void Release();

	void Setglow(int alpha);
	void SetPos(const float x, const float y);
	void SetPos(const int x, const int y);
	void SetPosByAbsoluteCoordinate(const float x, const float y);
	void SetPosX(const float x);
	void SetPosY(const float y);
	void SetVisible(bool isVisible);
	void SetScale(float diameter);
	void SetScale(float x,float y);
	int GetIndex();
	int GetWidth();
	int GetHeight();
	float GetPosX();
	float GetPosY();
	float GetPosMidX();
	float GetPosMidY();
	int GetGlow();
	bool GetIsVisible(); 

protected:
	int m_spriteIdx{};
	//RECT source{};
	VEC2 m_pos{};
	VEC2 m_scale{ 1,1 };
	//VEC2 m_rotationMid{};		// 회전 중심 nullptr
	float m_radianAngle{ 0.0F };// 라디안 각도 0.0F
	unsigned int m_argb{ 0xFFFFFFFF };		// RGB(0xAARRGGBB)
	bool m_useSetColor{ false };

	int m_width{};
	int m_height{};
	int m_glow{ GLOW_OFF };//밝기 관련, 투명도와는 관계 없는 듯. 

	glc2window* m_windowP{};

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