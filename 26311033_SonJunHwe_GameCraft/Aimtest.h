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
	void Event_Rcick();
	void Event_Lcick();
	void Event_Nonecick();

private:
	ULONGLONG m_time{};

	glc2image* aimpoint;
	glc2image* hit;
};

