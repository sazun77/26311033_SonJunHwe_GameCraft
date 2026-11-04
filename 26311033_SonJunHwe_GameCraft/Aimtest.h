#pragma once
#include "glc2window.h"
enum COMMAND
{
	ESC = 27,
};

class Aimtest : public glc2window
{
public:
	Aimtest();
	~Aimtest();
	void FrameMove_Update() override;


private:
	glc2image* image_aim;
	glc2image* image_target;
};

