#include "Aimtest.h"
#include "Utility.h"
#include "glc2window.h"
#include "glc2image.h"
#include "glc2sound.h"

#include <iostream>
#include <random>

void Aimtest::FrameMove_Update()
{
	// 실험용 코드들.
	//m_mouseX = 100;
	//m_mouseY = 100;

	// 조준점 위치 업데이트
	image_aimpoint->SetPos(static_cast<float>(m_mouseX), static_cast<float>(m_mouseY));		
	image_reloading->SetPos(static_cast<float>(m_mouseX + image_aimpoint->GetWidth()/3*2), static_cast<float>(m_mouseY+image_aimpoint->GetHeight()/3*2 ));
	//image_reloading->SetPosByAbsoluteCoordinate(static_cast<float>(m_mouseX-image_aimpoint->GetWidth()/2), static_cast<float>(m_mouseY- image_aimpoint->GetHeight() / 2));		
	
	// 발사 후, 관련 후속 처리.
	if (0 != m_lastFireTime)
	{
		if (COOLTIME_FIRE <= m_time - m_lastFireTime)
		{
			image_reloading->SetVisible(false);
			m_lastFireTime = 0;
		}
		else if (COOLTIME_FIRE / 2 <= m_time - m_lastFireTime && image_gunfire->GetIsVisible() == true)
		{
			image_gunfire->SetVisible(false);
		}
		else if (COOLTIME_FIRE/3 <= m_time - m_lastFireTime && image_aimpoint->GetIsVisible() == true)
		{
			image_gunfire->Setglow(GLOW_OFF);

			image_aimpoint->Setglow(GLOW_OFF);
		}

	}


	m_time = GetTickCount64();
}

void Aimtest::FrameMove_Mouse()
{
	m_mouseX = g2_GetMouseX();
	m_mouseY = g2_GetMouseY();
	m_mouseZ = g2_GetMouseZ();

	mouse currentMouse{};

	if (g2_GetMouseEvent(LButton))
	{
		//DEBUGLOG("L click\n");
		currentMouse = LButton;
	}
	else if (g2_GetMouseEvent(RButton))
	{
		//DEBUGLOG("R click\n");
		currentMouse = RButton;
	}
	else if (g2_GetMouseEvent(MButton))
	{
		//DEBUGLOG("M click\n");
		currentMouse = MButton;
	}
	else
	{
	//	DEBUGLOG("No click\n");
		currentMouse = NONE;
	}
	// 누르면 발동, 홀드 여부 상관 없이.
	if (currentMouse != NONE) 
	{
		// '클릭 시' 발동일 경우 이전 명령과 다르기만 하면 됨. 
		if (m_mouseEvent == currentMouse)
		{
			// ... 대충 홀드하면 생기는 이벤트
		}
		else
		{
			switch (currentMouse)
			{
			case LButton:
			{
				if (m_time - m_lastFireTime >= COOLTIME_FIRE)
				{
					// 이미지 처리.
					image_gunfire->SetPos(m_mouseX, m_mouseY);
					image_gunfire->SetVisible(true);
					image_gunfire->Setglow(GLOW_ON);
					
					image_aimpoint->Setglow(GLOW_ON);
					
					image_reloading->SetVisible(true);

					sound_gunfire->Play();

					m_lastFireTime = m_time;
				}
				else
				{
					sound_jam->Play();
				}

				break;
			}
			default:
			{
				break;
			}
			}
		}
	}

	m_mouseEvent = currentMouse;
}
void Aimtest::FrameMove_Keyboard()
{
	m_keyboardP = g2_GetKeyboard();

	CheckEscape();
}
Aimtest::~Aimtest()
{

}

void Aimtest::Setup()
{
	image_aimpoint = new glc2image(this, "Resource/Images/aimpoint.png");
	image_gunfire = new glc2image(this, "Resource/Images/gunfire.png", 100, 100);	image_gunfire->SetVisible(false);
	image_reloading = new glc2image(this, "Resource/Images/reloading.png", 100, 100); image_reloading->SetVisible(false); image_reloading->SetScale(0.3f);

	sound_gunfire = new glc2sound(this,"Resource/Sounds/gunfire.wav");
	sound_hit = new glc2sound(this, "Resource/Sounds/hit.wav");
	sound_jam = new glc2sound(this, "Resource/Sounds/jam.wav");
	//sound_bgm = new glc2sound(this, "Resource/Sounds/bgm.");
}


