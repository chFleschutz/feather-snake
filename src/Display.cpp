#include "Display.h"

Display& Display::instance()
{
	static Display instance;
	return instance;
}

void Display::setup()
{
	delay(250);		// wait for the OLED to power up
	m_display.begin(constants::display::I2C, true); 
	m_display.display();
	delay(1000);
	m_display.clearDisplay();
	m_display.display();
	m_display.setTextColor(SH110X_WHITE);
	m_display.setRotation(2);
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

void Display::drawBox(const Vector2& position, int width, int height, int color)
{
	m_display.drawRect(position.x(), position.y(), width, height, color);
}

void Display::display()
{
	m_display.display();
}

void Display::clear()
{
	m_display.clearDisplay();
}

bool Display::isPixelDrawn(const Vector2& position)
{
	return m_display.getPixel(position.x(), position.y());
}

Display::Display()
    : m_display(constants::display::WIDTH, constants::display::HEIGHT, &Wire)
{
}
