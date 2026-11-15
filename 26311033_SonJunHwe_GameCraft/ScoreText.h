#pragma once
#include "glc2text.h"
#include <string>
class ScoreText :
    public glc2text
{
    using glc2text::glc2text;
    
    void SetText() override;
private:
    std::string m_subString{};
};

