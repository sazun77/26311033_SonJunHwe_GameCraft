#include "Aimtest.h"
#include "Utility.h"
#include "glc2window.h"
#include "glc2image.h"

#include <iostream>

Aimtest::Aimtest()
{

}

void Aimtest::FrameMove_Update()
{
	if (0== m_time) { Setup(); }

	ULONGLONG currentTime = GetTickCount64();
	
	aimpoint->SetPosByAbsoluteCoordinate(static_cast<float>(m_mouseX-aimpoint->GetWidth()/2), static_cast<float>(m_mouseY- aimpoint->GetHeight() / 2));
	
	CheckEscape();

	if (200 <= currentTime - m_time)	//0.2s마다 판정
	{
		if (m_mouseEvent == LButton)
		{
			Event_Rcick();
		}
		if (1000 <= currentTime - m_time)
		{
		DEBUGLOG("L click\n");
		}
			//else if (m_mouseEvent == RButton)
		//{
		//	DEBUGLOG("R click\n");
		//	image_target->SetPos(static_cast<float>(m_mouseX - image_target->GetWidth() / 2), static_cast<float>(m_mouseY - image_target->GetHeight() / 2));
		//}
		//else if (m_mouseEvent == MButton)
		//{
		//	DEBUGLOG("M click\n");
		//	image_target->SetPos(static_cast<float>(m_mouseX - image_target->GetWidth() / 2), static_cast<float>(m_mouseY - image_target->GetHeight() / 2));
		//}	
		else
		{
			m_mouseEvent = NONE;
		}

		m_time = currentTime;
	}
}

void Aimtest::Event_Rcick()
{
	hit->SetPosByAbsoluteCoordinate(static_cast<float>(m_mouseX - hit->GetWidth() / 2), static_cast<float>(m_mouseY - hit->GetHeight() / 2));
	
}

Aimtest::~Aimtest()
{
	for (glc2image* image : m_images)
	{
		delete image;
	}
}

void Aimtest::Setup()
{
	aimpoint = new glc2image(this, "Resource/Sprite/aim.png");
	hit = new glc2image(this, "Resource/Sprite/hit.png", 100, 100);


	if (true) { {} }
}


