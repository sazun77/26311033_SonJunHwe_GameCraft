#pragma once
#include "glc2window.h"

#include <vector>
#include <random>
#define SECOND 1000
class glc2image;
class glc2sound;
class target;
typedef  unsigned long long score;

enum COMMAND
{
	TIME_NULL = 0,

	COOLTIME_FIRE=500,
};
enum SCENE
{
	SCENE_START = 0,
	SCENE_MAIN,
	SCENE_END,
};

class Aimtest : public glc2window
{
public:
	Aimtest();
	~Aimtest();

	ULONGLONG GetTime();
	score GetScore();
	void ScoreDecreaseTimeOut();
	void SetFireAble();

private:
	void FrameMove_Update() override;
	void FrameMove_Mouse() override;
	void FrameMove_Keyboard() override;

	void SceneStart();
	void SceneMain();
	//void SceneEnd();

	void SetMousePos();
	void SetcurrentMouse(mouse & currentMouse);
	void MouseEvent(const mouse currentMouse);
	void LclickEvent();
	void ScoreCalculate();
public:
	std::mt19937 m_randomEngine;
	score m_score{};
	score m_perfectCutline{ 99 };
	SCENE m_scene{ SCENE_START };
protected:
	ULONGLONG m_time;
	ULONGLONG m_timer{0};

	target* m_target;
	glc2image* image_aimpoint;
	glc2image* image_gunfire;
	glc2image* image_reloading;

	glc2text* text_countdown;
	glc2text* text_score;

	glc2sound* sound_gunfire;
	glc2sound* sound_hit;
	glc2sound* sound_jam;
	glc2sound* sound_bgm;

	score m_maxDecreaseTimeOut{30000};
};