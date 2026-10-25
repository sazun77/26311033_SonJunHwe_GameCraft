#include "glc2image.h"
#include "main.h"
//#define _CRT_SECURE_NO_WARNINGS

// 좌표를 입력하면 해당 위치에 이미지 표시.
// 렌더를 안하면 바로 다음render()에서 아라야시키 당하는 듯.
// m_pos는 생략 가능한 듯.
void glc2image::RenderMain()
{
	g2_Draw2D(m_imageIdx, nullptr, &m_pos);
}

// 이후에 활용할 수 있도록 이미지의 주소,인덱스,너비,폭을 설정함.
void glc2image::Setup(const char* fileName)
{
	strcpy_s(m_image, fileName);
	m_imageIdx = g2_TextureLoad(m_image);
	m_width = g2_TextureWidth(m_imageIdx);
	m_height = g2_TextureHeight(m_imageIdx);
}


// 이걸 호출하면 이후에 Render해도 이미지가 나타나지 않음.
// 다만 Setup을 다시 해주면 부활함.
//	- 정확히는 유사한 객체를 다시 만드는 것이라 할 수 있을 듯.
void glc2image::End()
{
	g2_TextureRelease(m_imageIdx);
}

void glc2image::SetPos(const int x, const int y)
{
	m_pos.x = static_cast<float>(x);
	m_pos.y = static_cast<float>(y);
}

int glc2image::GetWidth()
{
	return m_width;
}

int glc2image::GetHeight()
{
	return m_height;
}

int glc2image::GetIndex()
{
	return m_imageIdx;
}

int glc2image::GetX()
{
	return static_cast<int>(m_pos.x);
}

int glc2image::GetY()
{
	return static_cast<int>(m_pos.y);
}
