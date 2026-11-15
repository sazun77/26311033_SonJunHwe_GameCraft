#pragma once
#include "glc2d.h"
#define INPUT_NULL -777

class glc2window;
class glc2text
{	
public:	
	glc2text(glc2window* windowP, CSTR inputText=nullptr, const int x = INPUT_NULL, const int y = INPUT_NULL);
	~glc2text();

	void Updateglc2text();

	void Renderglc2text();

protected:
	virtual void SetText() {};

private:
	void InitialPos(const int x, const int y);
protected:
	glc2window* m_windowP;
	bool m_doRender{ true };

	const char* m_text;
	VEC2i m_pos;
	unsigned int m_color{ 0xFFFFFFFF };
};

