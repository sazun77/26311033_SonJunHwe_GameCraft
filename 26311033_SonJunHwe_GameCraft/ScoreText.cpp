#include "ScoreText.h"
#include"glc2window.h"
#include "Aimtest.h"
#include <string>

void ScoreText::SetText()
{
	m_pos.x = 0;
	m_pos.y = m_windowP->GetHeight() - m_windowP->GetFontSize();

	Aimtest* aimtestP = static_cast<Aimtest*>(m_windowP);
	m_subString = "Score : " + std::to_string(aimtestP->GetScore());
	m_text = m_subString.c_str();
}
