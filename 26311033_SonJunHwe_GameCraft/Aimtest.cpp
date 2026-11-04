#include "Aimtest.h"
#include "Utility.h"
#include "glc2window.h"
#include "glc2image.h"
#include <iostream>

Aimtest::Aimtest()
{
	image_aim = new glc2image(this, "Resource/Sprite/sprite_target.png");
	image_target = new glc2image(this, "Resource/Sprite/sprite_bullet.png");

}

void Aimtest::FrameMove_Update()
{
	DEBUGLOG("framgemove\n");
	if (m_keyboardP[ESC])
	{
		DEBUGLOG("programend\n");

		Close();
	}
}

Aimtest::~Aimtest()
{
	for (glc2image* image : m_images)
	{
		delete image;
	}
}


