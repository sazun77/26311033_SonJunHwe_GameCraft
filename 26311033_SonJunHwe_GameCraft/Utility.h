#pragma once
#define DEBUG_MODE

#ifdef DEBUG_MODE
    #define DEBUGLOG(txt) std::cout << txt
#else
    #define DEBUGLOG(txt)
#endif // _MODE

void SetConsole();