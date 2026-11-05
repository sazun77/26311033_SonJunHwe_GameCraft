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
	if (0== m_updateTime) { Setup(); }

	ULONGLONG currentTime = GetTickCount64();
	
	image_aim->SetPos(static_cast<float>(m_mouseX-image_aim->GetWidth()/2), static_cast<float>(m_mouseY- image_aim->GetHeight() / 2));
	
	CheckEscape();

	if (10 <= currentTime - m_updateTime)
	{
		if(m_mouseEvent == LButton)
		{
			DEBUGLOG("L click\n");
			image_target->SetPos(static_cast<float>(m_mouseX - image_target->GetWidth() / 2), static_cast<float>(m_mouseY - image_target->GetHeight() / 2));
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
		m_updateTime = currentTime;

	}

	

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
	image_aim = new glc2image(this, "Resource/Sprite/sprite_target.png");
	image_target = new glc2image(this, "Resource/Sprite/sprite_bullet.png", 100, 100);


	if (true) { {} }
}


