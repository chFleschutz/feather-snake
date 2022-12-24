#include "Food.h"
#include "Display.h"

Food::Food(const Vector2& position, int size) :
    // m_position(random(constants::display::WIDTH - 1), random(constants::display::HEIGHT - 1)),
    m_size(size)
{
    // Display::instance().drawPifxel(m_position);
}

int Food::size()
{
    return m_size;
}

const Vector2& Food::position()
{
    return m_position;
}


FoodProvider::FoodProvider()
{
    m_food = new Food(Vector2(10, 10));
}

Food* FoodProvider::takeFood(const Vector2& position)
{
    if (m_food->position() != position)
        return nullptr;
    
    auto food = m_food;
    m_food = new Food(food->position() + Vector2(2, 2));
    return food;
}
