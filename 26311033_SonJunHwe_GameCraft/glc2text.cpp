#include "glc2text.h"
#include "glc2window.h"
#include "glc2d.h"
#include <type_traits>

glc2text::glc2text(glc2window* windowP, CSTR inputText, const int x, const int y)
{
	m_windowP = windowP;
	
	m_text = inputText;

	InitialPos(x,y);

	m_windowP->AddText(this);
}

glc2text::~glc2text()
{
	m_windowP->DeleteText(this);
}
void glc2text::Updateglc2text()
{
	if (!m_doRender)
	{ 
		return; 
	}

	SetText();
}
void glc2text::Renderglc2text()
{
	if (!m_doRender)
	{
		return;
	}

	g2_FontDrawText(m_windowP->GetFont(), m_pos,m_color,m_text);
}

void glc2text::InitialPos(const int x, const int y)
{
	if (y == INPUT_NULL)
	{
		m_pos.x = INPUT_NULL;
		m_pos.y = INPUT_NULL;
	}
	else
	{
		m_pos.x = x;
		m_pos.y = y;
	}
}
