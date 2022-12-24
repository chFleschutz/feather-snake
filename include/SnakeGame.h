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
    SnakeGameState* m_gameState;
};