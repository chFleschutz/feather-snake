#include "SnakeBody.h"
#include "Defines.h"
#include "Arduino.h"

SnakeBody::SnakeBody(const Vector2 &position)
{
    m_nextBody = nullptr;
    m_previousBody = nullptr;

    m_pos = position;
}

SnakeBody::SnakeBody(SnakeBody *previousBody, const Vector2 &forwardVector)
{
    // Set next and previous of this
    m_nextBody = nullptr;
    m_previousBody = previousBody;

    // Set next of previous body
    if (m_previousBody)
    {
        m_previousBody->m_nextBody = this;

        // Set pos
        m_pos = m_previousBody->m_pos + forwardVector;
    }
}

SnakeBody::~SnakeBody()
{
    if (m_previousBody && m_nextBody)
    {
        m_previousBody->m_nextBody = m_nextBody;
        m_previousBody = nullptr;
        m_nextBody->m_previousBody = m_previousBody;
        m_nextBody = nullptr;
    }

    if (m_nextBody)
        m_nextBody->m_previousBody = nullptr;

    if (m_previousBody)
        m_previousBody->m_nextBody = nullptr;
}

SnakeBody *SnakeBody::next()
{
    return m_nextBody;
}

Vector2 &SnakeBody::position()
{
    return m_pos;
}

Snake::Snake(int xPos, int yPos)
{
    Serial.println("Creating Snake");

    m_snakeSize = 1;
    m_forward = Vector2(1, 0);

    m_tail = new SnakeBody(Vector2(xPos, yPos));
    m_head = new SnakeBody(m_tail, m_forward);
}

void Snake::move(Display &display)
{
    Serial.println("Moving Snake");

    // New Head
    auto newHead = new SnakeBody(m_head, m_forward);
    m_head = newHead;

    auto headPos = m_head->position();
    display.drawPixel(headPos);
    Serial.print("    Head Pos: "); 
    Serial.print(headPos.x());
    Serial.print(" ");
    Serial.print(headPos.y());

    auto tailPos = m_tail->position();
    display.drawPixel(tailPos, SH110X_BLACK);
    Serial.print("    Tail Pos: "); 
    Serial.print(tailPos.x());
    Serial.print(" ");
    Serial.println(tailPos.y());

    // Delete Tail
    auto newTail = m_tail->next();
    delete m_tail;
    m_tail = newTail;
}

void Snake::turnLeft()
{
    m_forward.rotateLeft();
}

void Snake::turnRight()
{
    m_forward.rotateRight();
}

bool Snake::hasCrashed()
{
    return m_crashed;
}
