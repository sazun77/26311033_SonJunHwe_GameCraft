#pragma once
#include "glc2text.h"

#define STARTCOUNTDOWN 3
class textCountdown :
    public glc2text
{
public:
    using glc2text::glc2text;
    void SetText()override;
    void SetNumber(int timer);
private:
    int m_number{ 0 };
};

