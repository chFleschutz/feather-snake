#include "SnakeGameState.h"
#include "Arduino.h"
#include "SnakeGame.h"

SnakeGameState::SnakeGameState(SnakeGame* game) : m_game(game)
{
}

void SnakeGameState::changeState(SnakeGameState* newState)
{
	m_game->changeState(newState);
}

// MainMenuState ==================================================================

MainMenuState::MainMenuState(SnakeGame* game) : SnakeGameState(game)
{
	Display::instance().clear();
	Display::instance().print("Main Menu", 2, 2, 2);
}

void MainMenuState::update()
{
	if (!digitalRead(constants::button::A) || !digitalRead(constants::button::B) || !digitalRead(constants::button::C))
		changeState(new GameLoopState(m_game));
}

// GameLoopState ==================================================================

GameLoopState::GameLoopState(SnakeGame* game) : SnakeGameState(game), 
	m_snake(20, 20)
{
	Display::instance().clear();
	Display::instance().drawBox(Vector2(0, 0), constants::display::WIDTH, constants::display::HEIGHT);
}

void GameLoopState::update()
{
	moveSnake();

	feedSnake();

	checkGameOver();
}

void GameLoopState::moveSnake()
{
	// Change direction
	if (!digitalRead(constants::button::A))
		m_snake.turnRight();
	if (!digitalRead(constants::button::C))
		m_snake.turnLeft();

	// Move snake forward
	m_snake.move();
}

void GameLoopState::feedSnake()
{
	if (auto food = m_foodProvider.takeFood(m_snake.headPosition()))
		m_snake.eat(food);
}

void GameLoopState::checkGameOver()
{
	if (!m_snake.hasCrashed())
		return;
	if (digitalRead(constants::button::B))
		return;
	
	changeState(new GameOverState(m_game));
}

// GameOverState ==================================================================

GameOverState::GameOverState(SnakeGame* game) : SnakeGameState(game)
{
	Display::instance().print("Game Over", 2, 2, 2);
	Display::instance().display();
}

void GameOverState::update()
{
	if (!digitalRead(constants::button::A) || !digitalRead(constants::button::B) || !digitalRead(constants::button::C))
		changeState(new MainMenuState(m_game));
}
