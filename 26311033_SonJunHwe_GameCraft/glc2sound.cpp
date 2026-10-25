#include "glc2sound.h"
#include "glc2d.h"

int glc2sound::SetIdx(const char* soundFile)
{
	return m_idx = g2_SoundLoad(soundFile);
}

// 家府 犁积, true甫 持栏搁 风橇.
void glc2sound::SoundPlay(const bool doLoop)
{
	g2_SoundPlay(m_idx, doLoop);
}

void glc2sound::SoundPlayFromStart()
{
	if (!g2_SoundIsPlaying(m_idx))
	{
		g2_SoundReset(m_idx);
		g2_SoundPlay(m_idx);
	}
}
