#include "SnakeGame.h"

SnakeGame::SnakeGame()
{
    m_gameState = nullptr;
}

void SnakeGame::setup()
{
    Display::instance().setup();

    m_gameState = new MainMenuState();
}

void SnakeGame::run()
{
    m_gameState->update();

    if (m_gameState->shouldChange())
        changeState();

    Display::instance().display();
    delay(FRAME_DELAY);
}

void SnakeGame::changeState()
{
    auto nextState = m_gameState->transitionToNextState();
    delete m_gameState;
    m_gameState = nextState;
}