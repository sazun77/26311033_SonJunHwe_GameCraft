#include <string>

#include "Aimtest.h"
#include "textCountdown.h"

void textCountdown::SetText()
{
	Aimtest* ptr = static_cast<Aimtest*>(m_windowP);
	
	m_pos.x = (ptr->GetWidth() - ptr->GetFontSize() * m_subString.size()) / 2;
	m_pos.y = (ptr->GetHeight()-ptr->GetFontSize()) / 2;

	if (m_number < STARTCOUNTDOWN)
	{
		m_subString = '0'+ STARTCOUNTDOWN - m_number;
	}
	else
	{
		m_subString = "START";
	}

	m_textP = m_subString.c_str();
}

void textCountdown::SetNumber(int timer)
{
	m_number = timer;
}
