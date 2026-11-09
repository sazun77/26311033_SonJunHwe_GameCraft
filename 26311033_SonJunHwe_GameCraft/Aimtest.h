#pragma once
#include "glc2window.h"
#include <vector>

class glc2image;
class glc2sound;
enum COMMAND
{
	TIME_NULL = 0,

	COOLTIME_FIRE=500,
};

class Aimtest : public glc2window
{
public:
	Aimtest();
	~Aimtest();
	void Setup();
	void FrameMove_Update() override;
	void FrameMove_Mouse() override;
	void FrameMove_Keyboard() override;
	void Event_Rcick();
	void Event_Lcick();
	void Event_Nonecick();

private:
	ULONGLONG m_time{0};
	ULONGLONG m_lastMobSpawn{0};
	ULONGLONG m_lastFireTime{0};

	glc2image* image_aimpoint;
	glc2image* image_gunfire;
	glc2image* image_reloading;

	glc2sound* sound_gunfire;
	glc2sound* sound_hit;
	glc2sound* sound_jam;
	glc2sound* sound_bgm;
};