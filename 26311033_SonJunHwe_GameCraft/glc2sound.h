#pragma once
typedef	const char* CSTR;

class glc2window;

class glc2sound
{
public:
	glc2sound(glc2window* windowP, CSTR filename);
	~glc2sound();
	//int SetIdx(const char* soundFile);
	void Play(const bool doLoop = false);
	//void SoundPlay(const bool doLoop = false);
	//void SoundPlayFromStart();

private:
	int m_idx{};
	glc2window* m_windowP{};
};

