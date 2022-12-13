#include "SnakeGame.h"

SnakeGame::SnakeGame()
{
    m_gameState = nullptr;
}

void SnakeGame::setup()
{
    m_display.setup();

    m_gameState = new MainMenuState(m_display);
}

void SnakeGame::run()
{
    m_gameState->update();

    if (m_gameState->shouldChange())
        changeState();

    m_display.display();
    delay(800);
}

void SnakeGame::changeState()
{
    auto nextState = m_gameState->transitionToNextState();
    delete m_gameState;
    m_gameState = nextState;
}