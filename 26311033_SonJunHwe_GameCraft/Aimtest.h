#pragma once
#include "glc2window.h"

class glc2image;
enum COMMAND
{
	ESC = 27,
	COOLTIME_CLICK=1
};

class Aimtest : public glc2window
{
public:
	Aimtest();
	~Aimtest();
	void Setup();
	void FrameMove_Update() override;


private:
	ULONGLONG m_updateTime{};

	glc2image* image_aim;
	glc2image* image_target;
};

