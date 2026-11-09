// include the 2d game header file
#include "glc2d.h"
#include <stdio.h>

#include "glc2sound.h"
#include "glc2window.h"



glc2sound::glc2sound(glc2window* windowP, CSTR filename)
{
	m_windowP = windowP;
	m_idx = g2_SoundLoad(filename);

	
}

glc2sound::~glc2sound()
{
	m_windowP->DeleteSound(this);

	g2_SoundRelease(m_idx);
}

//int glc2sound::SetIdx(const char* soundFile)
//{
//	return m_idx = g2_SoundLoad(soundFile);
//}

// 家府 犁积, true甫 持栏搁 风橇.
void glc2sound::Play(const bool doLoop)
{
	if (g2_SoundIsPlaying(m_idx))
	{
		g2_SoundReset(m_idx);
	}

	g2_SoundPlay(m_idx, doLoop);
}
//void glc2sound::SoundPlay(const bool doLoop)
//{
//	if (g2_SoundIsPlaying(m_idx))
//	{
//		g2_SoundReset(m_idx);
//	}
//
//	g2_SoundPlay(m_idx, doLoop);
//}

//void glc2sound::SoundPlayFromStart()
//{
//	if (!g2_SoundIsPlaying(m_idx))
//	{
//		g2_SoundReset(m_idx);
//		g2_SoundPlay(m_idx);
//	}
//}
