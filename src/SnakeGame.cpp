#include "SnakeGame.h"

SnakeGame::SnakeGame()
{
    m_gameState = nullptr;
}

void SnakeGame::setup()
{
    Display::instance().setup();

    m_gameState = new MainMenuState(this);
}

void SnakeGame::run()
{
    m_gameState->update();
    checkGameState();

    Display::instance().display();
    delay(constants::game::FRAME_DELAY);
}

void SnakeGame::changeState(SnakeGameState* newState)
{
    m_nextState = newState;
}

void SnakeGame::checkGameState()
{
    if (m_nextState)
    {
        delete m_gameState;
        m_gameState = m_nextState;
        m_nextState = nullptr;
    }
}
