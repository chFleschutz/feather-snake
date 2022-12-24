#ifndef DEFINES_H
#define DEFINES_H

namespace constants
{
    // Button pins for esp32-s3
    namespace button
    {
        constexpr int A = 9;
        constexpr int B = 6;
        constexpr int C = 5;
    }
    // OLED screen 
    namespace display
    {
        constexpr int WIDTH  = 62;
        constexpr int HEIGHT = 128;
        constexpr int I2C    = 0x3C;
    }
    // Game settings
    namespace game
    {
        constexpr int FRAME_DELAY = 200;    //< Micro-seconds between frames
    }
}

#endif