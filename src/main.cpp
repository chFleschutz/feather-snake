#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "SnakeGame.h"

SnakeGame snake;

void setup()
{
	Serial.begin(115200);
	
    pinMode(constants::button::A, INPUT_PULLUP);
	pinMode(constants::button::B, INPUT_PULLUP);
	pinMode(constants::button::C, INPUT_PULLUP);

	snake.setup();
}

void loop()
{
	snake.run();
}