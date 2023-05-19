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

    // Returns a pointer to a food at position if one exists there
    // Can be nullptr 
    // Food has to be deleted afterwards
    Food* takeFood(const Vector2& position);

    // Todo: refactor into returning a copy not a pointer to unsafe

private:
    Food* m_food;
};