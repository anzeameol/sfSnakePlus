#pragma once

#include <SFML/Graphics.hpp>

namespace sfSnake
{
    enum class GridColor
    {
        white,
        black,
        brown
    };

    class Grid
    {
    private:
        GridColor gridColor;
        sf::RectangleShape vericalLine;
        sf::RectangleShape horizonLine;

    public:
        const int densityX = 40;
        const int densityY = 30;
        Grid();
        Grid(GridColor gridColor);
        void setColor(GridColor color);
        void setColor(int color);
        void render(sf::RenderWindow &window);
    };

}