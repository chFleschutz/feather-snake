#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SH110X.h"
#include "Defines.h"
#include "Vector2.h"

class Display
{
public:
    Display(const Display&) = delete;
    void operator=(const Display&) = delete;

    static Display& instance();

    void setup();

    void print(const char* text);
    void print(const char* text, int x, int y, int size = 1);
    void drawPixel(const Vector2& position, int color = SH110X_WHITE);
    
    void display();
    void clear();

private:
    Display();

    Adafruit_SH1107 m_display;
};

#endif