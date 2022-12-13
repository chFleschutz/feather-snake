#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "SnakeGame.h"

SnakeGame snake;

void setup()
{
	Serial.begin(115200);
	
    pinMode(BUTTON_A, INPUT_PULLUP);
	pinMode(BUTTON_B, INPUT_PULLUP);
	pinMode(BUTTON_C, INPUT_PULLUP);

	snake.setup();
}

void loop()
{
	snake.run();
}