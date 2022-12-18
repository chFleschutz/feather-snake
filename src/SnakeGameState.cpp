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
	Display::instance().clear();
	Display::instance().print("Main Menu", 2, 2, 2);
}

void MainMenuState::update()
{
	if (!digitalRead(BUTTON_A) || !digitalRead(BUTTON_B) || !digitalRead(BUTTON_C))
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
	Display::instance().drawBox(Vector2(0, 0), DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

void GameLoopState::update()
{
	if (!digitalRead(BUTTON_B))
		changeState();

	if (!digitalRead(BUTTON_A))
		m_snake.turnRight();
	if (!digitalRead(BUTTON_C))
		m_snake.turnLeft();

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
	Display::instance().print("Game Over", 2, 2, 2);
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
