#include "SnakeGameState.h"
#include "Arduino.h"

SnakeGameState::SnakeGameState()
{
}

bool SnakeGameState::shouldChange()
{
	return m_shouldChange;
}

void SnakeGameState::changeState()
{
	m_shouldChange = true;
}

// MainMenuState ==================================================================

MainMenuState::MainMenuState() 
{
	// m_display.clear();
	// m_display.print("Main Menu", 0, 0, 2);
	// m_display.display();
	Display::instance().clear();
	Display::instance().print("Main Menu", 0, 0, 2);
}

void MainMenuState::update()
{
	if (!digitalRead(BUTTON_A))
		changeState();
}

SnakeGameState *MainMenuState::transitionToNextState()
{
	return new GameLoopState();
}

// GameLoopState ==================================================================

GameLoopState::GameLoopState()
	 : m_snake(20, 20)
{
	Display::instance().clear();
}

void GameLoopState::update()
{
	if (!digitalRead(BUTTON_A))
		m_snake.turnLeft();
	if (!digitalRead(BUTTON_C))
		m_snake.turnRight();

	m_snake.move();

	if (m_snake.hasCrashed())
		changeState();
}

SnakeGameState *GameLoopState::transitionToNextState()
{
	return new GameOverState();
}

// GameOverState ==================================================================

GameOverState::GameOverState()
{
	// m_display.print("Game Over", 0, 0, 2);
	// m_display.display();
	Display::instance().print("Game Over", 0, 0, 2);
	Display::instance().display();
}

void GameOverState::update()
{
	if (!digitalRead(BUTTON_A) || !digitalRead(BUTTON_B) || !digitalRead(BUTTON_C))
		changeState();
}

SnakeGameState *GameOverState::transitionToNextState()
{
	return new MainMenuState();
}
