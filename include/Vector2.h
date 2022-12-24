#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    Vector2();
    Vector2(int x, int y);
    Vector2(const Vector2& other);

    Vector2& operator=(const Vector2& other);
    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;
    Vector2 operator+(const Vector2& other) const;

    int x() const { return m_x; } 
    int y() const { return m_y; } 

    void rotateLeft();
    void rotateRight();

private:
    int m_x;
    int m_y;
};

#endif