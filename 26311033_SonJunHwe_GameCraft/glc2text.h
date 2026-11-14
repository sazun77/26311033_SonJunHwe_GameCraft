#pragma once
#include "glc2d.h"
#define INPUT_NULL -777.7f

class glc2window;
class glc2text
{	
public:	
	glc2text(glc2window* windowP, CSTR filename, const float x = INPUT_NULL, const float y = INPUT_NULL);
	~glc2text();
	void Renderglc2text();
protected:
	glc2window* m_windowP;

	char* m_text;
	VEC2 m_pos;
	unsigned int m_color{ 0xFFFFFFFF };
};

