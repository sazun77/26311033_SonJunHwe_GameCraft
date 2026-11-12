#include "target.h"
#include "Aimtest.h"
#include "glc2window.h"
#include "glc2image.h"
#include <random>
#include "Utility.h"
#include <iostream>



void target::LocationReset(std::mt19937 m_randomEngine)
{
	std::uniform_int_distribution<int> xLocation(0, m_windowP->GetWidth() - m_width);
	m_pos.x = static_cast<float>(xLocation(m_randomEngine));
	std::uniform_int_distribution<int> yLocation(0, m_windowP->GetHeight() - m_height);
	m_pos.y = static_cast<float>(yLocation(m_randomEngine));
}
