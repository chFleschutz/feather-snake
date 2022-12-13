#ifndef _SNAKEGAMESTATE_H_
#define _SNAKEGAMESTATE_H_

#include "Defines.h"
#include "SnakeBody.h"
#include "Display.h"

class SnakeGameState
{
public:
    SnakeGameState(Display& display);

    bool shouldChange();

    virtual void update() = 0;
    virtual SnakeGameState* transitionToNextState() = 0;

protected:
    void changeState();

    Display& m_display;

private:
    bool m_shouldChange = false;
};


class MainMenuState : public SnakeGameState
{
public:
    MainMenuState(Display& display);

	void update() override;
	SnakeGameState* transitionToNextState() override;
};


class GameLoopState : public SnakeGameState
{
public:
    GameLoopState(Display& display);

	void update() override;
	SnakeGameState* transitionToNextState() override;

private:
    Snake m_snake;
};


class GameOverState : public SnakeGameState
{
public: 
    GameOverState(Display& display);

	void update() override;
	SnakeGameState* transitionToNextState() override;
};

#endif
