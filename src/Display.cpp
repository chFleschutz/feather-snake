#include "Display.h"

Display::Display()
    : m_display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire)
{
}

void Display::setup()
{
	delay(250);		// wait for the OLED to power up
	m_display.begin(DISPLAY_I2C, true); 
	m_display.display();
	delay(1000);
	m_display.clearDisplay();
	m_display.display();
    m_display.setTextSize(2);
	m_display.setTextColor(SH110X_WHITE);
	m_display.setCursor(0, 0);
	m_display.setRotation(1);
}

void Display::print(const char* text)
{
    m_display.setCursor(0, 0);
    m_display.println(text);
}

void Display::print(const char* text, int x, int y, int size)
{
	m_display.setCursor(x, y);
	m_display.setTextSize(size);
	m_display.println(text);
}

void Display::drawPixel(const Vector2& position, int color)
{
	m_display.drawPixel(position.x(), position.y(), color);
}

void Display::display()
{
	m_display.display();
}

void Display::clear()
{
	m_display.clearDisplay();
}
    