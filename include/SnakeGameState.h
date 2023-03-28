#ifndef SNAKEGAMESTATE_H
#define SNAKEGAMESTATE_H

#include "Defines.h"
#include "SnakeBody.h"
#include "Display.h"
#include "Food.h"

class SnakeGame;

class SnakeGameState
{
public:
    SnakeGameState(SnakeGame* game);

    virtual void update() = 0;

protected:
    void changeState(SnakeGameState* newState);

    SnakeGame* m_game;
};


class MainMenuState : public SnakeGameState
{
public:
    MainMenuState(SnakeGame* game);

	void update() override;
};


class GameLoopState : public SnakeGameState
{
public:
    GameLoopState(SnakeGame* game);

	void update() override;

private:
    void moveSnake();
    void feedSnake();
    void checkGameOver();

    Snake m_snake;
    FoodProvider m_foodProvider;
};


class GameOverState : public SnakeGameState
{
public: 
    GameOverState(SnakeGame* game);

	void update() override;
};

#endif
