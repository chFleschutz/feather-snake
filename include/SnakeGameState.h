#ifndef _SNAKEGAMESTATE_H_
#define _SNAKEGAMESTATE_H_

#include "Defines.h"
#include "SnakeBody.h"
#include "Display.h"

class SnakeGameState
{
public:
    SnakeGameState();

    bool shouldChange();

    virtual void update() = 0;
    virtual SnakeGameState* transitionToNextState() = 0;

protected:
    void changeState();

private:
    bool m_shouldChange = false;
};


class MainMenuState : public SnakeGameState
{
public:
    MainMenuState();

	void update() override;
	SnakeGameState* transitionToNextState() override;
};


class GameLoopState : public SnakeGameState
{
public:
    GameLoopState();

	void update() override;
	SnakeGameState* transitionToNextState() override;

private:
    Snake m_snake;
};


class GameOverState : public SnakeGameState
{
public: 
    GameOverState();

	void update() override;
	SnakeGameState* transitionToNextState() override;
};

#endif
