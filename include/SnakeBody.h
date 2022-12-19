#include "Vector2.h"
#include "Display.h"

class SnakeBody
{
public:
    SnakeBody(const Vector2& position);
    SnakeBody(SnakeBody* previousBody, const Vector2& forwardVector);
    ~SnakeBody();

    SnakeBody* next();
    Vector2& position();
        
private:
    Vector2 m_pos;
    SnakeBody* m_nextBody;
    SnakeBody* m_previousBody;
};

class Snake
{
public:
    Snake(int xPos, int yPos);
    ~Snake();

    void move();
    void turnLeft();
    void turnRight();
    bool hasCrashed();

private:
    void checkHeadCollision();

    bool m_crashed = false;
    int m_snakeSize = 0;
    Vector2 m_forward;
    SnakeBody* m_head;
    SnakeBody* m_tail;
};
