#pragma once
#include "glc2text.h"
class ScoreText :
    public glc2text
{
    using glc2text::glc2text;
    
    void SetText() override;

};

