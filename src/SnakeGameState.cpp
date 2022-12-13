#include "SnakeGameState.h"
#include "Arduino.h"

SnakeGameState::SnakeGameState(Display &display)
	: m_display(display)
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

MainMenuState::MainMenuState(Display &display) : SnakeGameState(display)
{
	m_display.clear();
	m_display.print("Main Menu", 0, 0, 2);
	m_display.display();
}

void MainMenuState::update()
{
	if (!digitalRead(BUTTON_A))
		changeState();
}

SnakeGameState *MainMenuState::transitionToNextState()
{
	return new GameLoopState(m_display);
}

// GameLoopState ==================================================================

GameLoopState::GameLoopState(Display &display)
	: SnakeGameState(display),
	  m_snake(20, 20)
{
	m_display.clear();
}

void GameLoopState::update()
{
	if (!digitalRead(BUTTON_A))
		m_snake.turnLeft();
	if (!digitalRead(BUTTON_C))
		m_snake.turnRight();

	m_snake.move(m_display);

	if (m_snake.hasCrashed())
		changeState();
}

SnakeGameState *GameLoopState::transitionToNextState()
{
	return new GameOverState(m_display);
}

// GameOverState ==================================================================

GameOverState::GameOverState(Display &display) : SnakeGameState(display)
{
	m_display.print("Game Over", 0, 0, 2);
	m_display.display();
}

void GameOverState::update()
{
	if (!digitalRead(BUTTON_A) || !digitalRead(BUTTON_B) || !digitalRead(BUTTON_C))
		changeState();
}

SnakeGameState *GameOverState::transitionToNextState()
{
	return new MainMenuState(m_display);
}
