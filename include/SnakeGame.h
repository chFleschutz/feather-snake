#include "SnakeGameState.h"
#include "Display.h"
#include "Defines.h"

class SnakeGame
{
public:
    SnakeGame();
    void setup();

    void run();

private:
    void changeState();

    SnakeGameState* m_gameState;
    Display m_display;
};