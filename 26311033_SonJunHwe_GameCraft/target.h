#pragma once
#include "glc2image.h"
#include <random>


class glc2window;
typedef	const char* CSTR;
typedef unsigned long long ULONGLONG;
class target : public glc2image
{
private:
	std::mt19937& m_randomEngineRef;
	ULONGLONG m_time{ 0 };
	ULONGLONG m_lifeSpan{ 1000 };
public:
	using glc2image::glc2image;
	
	target(std::mt19937& m_randomEngine, glc2window* windowP, CSTR filename, const float x = INPUT_NULL, const float y = INPUT_NULL);
	
	void Update();


	void LocationReset();



};

