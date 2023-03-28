#include "SnakeGameState.h"
#include "Display.h"
#include "Defines.h"

class SnakeGame
{
public:
    SnakeGame();
    void setup();

    void run();

    void changeState(SnakeGameState* newState);

private:
    void checkGameState();

    SnakeGameState* m_gameState;
    SnakeGameState* m_nextState = nullptr;
};