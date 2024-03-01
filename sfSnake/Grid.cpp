#include "Grid.h"
#include "Game.h"

using namespace sfSnake;

Grid::Grid()
{
    vericalLine.setSize(sf::Vector2f(Game::Width, 0.5f));
    horizonLine.setSize(sf::Vector2f(1.f, Game::Height));
}

Grid::Grid(GridColor gridColor)
    : gridColor{gridColor}
{
    vericalLine.setSize(sf::Vector2f(Game::Width, 0.5f));
    horizonLine.setSize(sf::Vector2f(1.f, Game::Height));
    switch (gridColor)
    {
    case GridColor::white:
        vericalLine.setFillColor(sf::Color::White);
        horizonLine.setFillColor(sf::Color::White);
        break;
    case GridColor::black:
        vericalLine.setFillColor(sf::Color::Black);
        horizonLine.setFillColor(sf::Color::Black);
        break;
    case GridColor::brown:
        vericalLine.setFillColor(sf::Color(96, 57, 18, 255));
        horizonLine.setFillColor(sf::Color(96, 57, 18, 255));
        break;
    default:
        break;
    }
}

void Grid::setColor(GridColor color)
{
    gridColor = color;
    switch (gridColor)
    {
    case GridColor::white:
        vericalLine.setFillColor(sf::Color::White);
        horizonLine.setFillColor(sf::Color::White);
        break;
    case GridColor::black:
        vericalLine.setFillColor(sf::Color::Black);
        horizonLine.setFillColor(sf::Color::Black);
        break;
    case GridColor::brown:
        vericalLine.setFillColor(sf::Color(96, 57, 18, 255));
        horizonLine.setFillColor(sf::Color(96, 57, 18, 255));
        break;
    default:
        break;
    }
}

void Grid::setColor(int color)
{
    switch (color)
    {
    case 0:
        gridColor = GridColor::white;
        vericalLine.setFillColor(sf::Color::White);
        horizonLine.setFillColor(sf::Color::White);
        break;
    case 1:
        gridColor = GridColor::black;
        vericalLine.setFillColor(sf::Color::Black);
        horizonLine.setFillColor(sf::Color::Black);
        break;
    case 2:
        gridColor = GridColor::brown;
        vericalLine.setFillColor(sf::Color(96, 57, 18, 255));
        horizonLine.setFillColor(sf::Color(96, 57, 18, 255));
        break;
    default:
        break;
    }
}

void Grid::render(sf::RenderWindow &window)
{
    float deltaX = Game::Width / densityX;
    float deltaY = Game::Height / densityY;
    for (int i = 1; i < densityX; i++)
    {
        horizonLine.setPosition(i * deltaX, 0);
        window.draw(horizonLine);
    }
    for (int i = 1; i < densityY; i++)
    {
        vericalLine.setPosition(0, i * deltaY);
        window.draw(vericalLine);
    }
}
