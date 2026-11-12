#pragma once
#include "glc2image.h"
#include <random>

class glc2window;
typedef	const char* CSTR;

class target : public glc2image
{
public:
	using glc2image::glc2image;

	void LocationReset(std::mt19937 m_randomEngine);
};

