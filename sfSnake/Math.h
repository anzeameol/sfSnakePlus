#pragma once
#include <SFML/Graphics.hpp>

namespace sfSnake
{
    float getDistence(sf::Vector2f a, sf::Vector2f b);
    sf::Vector2f getLoc(sf::Vector2f p, float l, float r);
    float getAngle(sf::Vector2f dir);
    float getLength(sf::Vector2f a);
}