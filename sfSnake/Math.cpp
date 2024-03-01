#include "Math.h"
#include <cmath>
#define PI 3.14159265358

float sfSnake::getDistence(sf::Vector2f a, sf::Vector2f b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

sf::Vector2f sfSnake::getLoc(sf::Vector2f p, float l, float r)
{
    return sf::Vector2f(p.x + l * cos(r * PI / 180), p.y + l * sin(r * PI / 180));
}

float sfSnake::getLength(sf::Vector2f a)
{
    return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

float sfSnake::getAngle(sf::Vector2f dir)
{
    if (dir.x == 0 && dir.y > 0)
    {
        return 180;
    }
    else if (dir.x == 0 && dir.y < 0)
    {
        return 0;
    }
    else if (dir.y == 0 && dir.x > 0)
    {
        return 90;
    }
    else if (dir.y == 0 && dir.x < 0)
    {
        return 270;
    }
    else
    {
        float angle = atan(dir.y / dir.x) * 180 / PI;
        if (dir.x > 0 && dir.y > 0)
        {
            return angle + 90;
        }
        else if (dir.x < 0 && dir.y > 0)
        {
            return angle + 270;
        }
        else if (dir.x < 0 && dir.y < 0)
        {
            return angle + 270;
        }
        else if (dir.x > 0 && dir.y < 0)
        {
            return angle + 90;
        }
    }
}