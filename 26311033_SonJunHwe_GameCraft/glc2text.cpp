#include "glc2text.h"
#include "glc2window.h"
#include "glc2d.h"

glc2text::glc2text(glc2window* windowP, CSTR filename, const float x, const float y)
{

}

glc2text::~glc2text()
{
}

void glc2text::Renderglc2text()
{
	g2_FontDrawText(m_windowP->GetFont(), m_pos,m_color,m_text);
}
