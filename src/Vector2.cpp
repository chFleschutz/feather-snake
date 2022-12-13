#include "Vector2.h"

Vector2::Vector2()
{
    m_x = 0;
    m_y = 0;
}

Vector2::Vector2(int x, int y)
{
    m_x = x;
    m_y = y;
}

Vector2::Vector2(const Vector2& other)
{
    m_x = other.m_x;
    m_y = other.m_y;
}

Vector2 &Vector2::operator=(const Vector2 &other)
{
    m_x = other.m_x;
    m_y = other.m_y;
    return *this;
}

bool Vector2::operator==(const Vector2 &other) const
{
    return m_x == other.m_x && m_y == other.m_y;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(m_x + other.m_x, m_y + other.m_y);
}

void Vector2::rotateLeft()
{
    auto newX = -1 * m_y;
    auto newY = m_x;
    m_x = newX;
    m_y = newY;
}

void Vector2::rotateRight()
{
    auto newX = m_y;
    auto newY = -1 * m_x;
    m_x = newX;
    m_y = newY;
}
