#include "SnakeBody.h"
#include "Arduino.h"
#include "Defines.h"
#include "Food.h"

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

Snake::~Snake()
{
    for (auto it = m_tail; it != m_head;)
    {
        auto temp = it;
        it = it->next();
        delete temp;
    }
    delete m_head;
}

void Snake::move()
{
    // New head
    auto newHead = new SnakeBody(m_head, m_forward);
    m_head = newHead;

    // Check for game over
    checkHeadCollision();

    // Update pixels
    Display::instance().drawPixel(m_head->position());
    Display::instance().drawPixel(m_tail->position(), SH110X_BLACK);

    // Delete tail
    if (m_digestingFood > 0)
    {   // Skip if food was eaten
        --m_digestingFood;
        return;
    }
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

void Snake::eat(Food* food)
{
    if (!food)
        return;

    m_digestingFood += food->size();
    delete food;
}

bool Snake::hasCrashed()
{
    return m_crashed;
}

Vector2 Snake::headPosition()
{
    return m_head->position();
}

void Snake::checkHeadCollision()
{
    // Todo: Not working properly Collision with border is not registered
    
    auto headPos = m_head->position();
    if (!Display::instance().isPixelDrawn(headPos))
        return;

    // Check for out of bounds
    if (headPos.x() < 0 || headPos.x() > constants::display::WIDTH || headPos.y() < 0 || headPos.y() > constants::display::HEIGHT)
    {
        m_crashed = true;    
        return;
    }
    // Check for snake collision
    for (auto it = m_tail; it != m_head; it = it->next())
    {
        if (headPos == it->position())
        {
            m_crashed = true;
            return;
        }
    }
}
