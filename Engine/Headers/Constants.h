#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SDL3/SDL.h>

// Constants (screen dimensions, fps etc.)
constexpr int ScreenWidth{256};
constexpr int ScreenHeight{240};
constexpr int ScreenFps{60};
constexpr SDL_Color bgColor{255, 255, 255, 255};
constexpr float gravity{98.0f};
const int targetFps{60};
const uint64_t targetFrameNs{1000000000 / targetFps};

#endif
