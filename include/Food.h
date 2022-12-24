#include "Vector2.h"

class Food
{
public:
    explicit Food(const Vector2& position, int size = 1);

    int size();
    const Vector2& position();

private:
    Vector2 m_position;
    int m_size;
};


class FoodProvider
{
public:
    FoodProvider();

    Food* takeFood(const Vector2& position);

private:
    Food* m_food;
};