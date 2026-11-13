#pragma once
#include "glc2window.h"

#include <vector>
#include <random>
class glc2image;
class glc2sound;
class target;
typedef  unsigned long long score;

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

private:

	void Setup();
	void FrameMove_Update() override;
	void FrameMove_Mouse() override;
	void FrameMove_Keyboard() override;

	void SetMousePos();
	void SetcurrentMouse(mouse & currentMouse);
	void MouseEvent(const mouse currentMouse);
	void LclickEvent();
	void ScoreCalculate();
public:
	std::mt19937 m_randomEngine;
	score m_score{};
	score m_perfectCutline{ 90 };
protected:
	ULONGLONG m_time{0};
	ULONGLONG m_lastFireTime{0};

	glc2image* image_aimpoint;
	glc2image* image_gunfire;
	glc2image* image_reloading;

	glc2sound* sound_gunfire;
	glc2sound* sound_hit;
	glc2sound* sound_jam;
	glc2sound* sound_bgm;

	target* m_target;
};