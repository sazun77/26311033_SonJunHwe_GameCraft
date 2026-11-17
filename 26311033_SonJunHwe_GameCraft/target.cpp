#include "target.h"
#include "Aimtest.h"
#include "glc2window.h"
#include "glc2image.h"
#include <random>
#include "Utility.h"
#include <iostream>



target::target(std::mt19937& m_randomEngine, glc2window* windowP, CSTR filename, const float x, const float y)
	:m_randomEngineRef(m_randomEngine),glc2image(windowP, filename, x, y)
{
}

void target::Updatetarget()
{
	Aimtest* ptr = static_cast<Aimtest*>(m_windowP);

	m_time += GetTickCount64() - ptr->GetTime();

	// 일정 시간마다 초기화.
	if (m_time > m_lifeSpan)
	{
		if (0 != m_hp)
		{
			ptr->ScoreDecreaseTimeOut();
		}

		m_hp = 1;
		m_time = 0;

		LocationReset();
	}
}

void target::LocationReset()
{
	std::uniform_int_distribution<int> xLocation(0, m_windowP->GetWidth() - GetWidth());
	std::uniform_int_distribution<int> yLocation(0, m_windowP->GetHeight() - GetHeight());

	SetPosX(static_cast<float>(xLocation(m_randomEngineRef)));
	SetPosY(static_cast<float>(yLocation(m_randomEngineRef)));
}
