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

void target::Update()
{
	if (m_time > m_lifeSpan)
	{
		LocationReset();
	}
}

void target::LocationReset()
{
	std::uniform_int_distribution<int> xLocation(0, m_windowP->GetWidth() - m_width);
	std::uniform_int_distribution<int> yLocation(0, m_windowP->GetHeight() - m_height);

	SetPosX(static_cast<float>(xLocation(m_randomEngineRef)));
	SetPosY(static_cast<float>(yLocation(m_randomEngineRef)));
}
