#include "OptionScreen.h"

#include "Game.h"
#include "MenuScreen.h"
#include <iostream>

using namespace sfSnake;

OptionScreen::OptionScreen()
{
    font_.loadFromFile("Fonts/game_over.ttf");
    option_.resize(3);
    openGrid_.resize(2);
    gridColor_.resize(3);
    backgroundColor_.resize(3);
    for (int i = 0; i < 3; i++)
    {
        if (i < 2)
        {
            openGrid_[i].setFont(font_);
            openGrid_[i].setPosition(480 + 300 * i, 240);
            openGrid_[i].setColor(sf::Color::Yellow);
        }
        option_[i].setFont(font_);
        option_[i].setPosition(50, 240 * (i + 1));
        option_[i].setColor(sf::Color::Green);
        gridColor_[i].setFont(font_);
        gridColor_[i].setPosition(480 + 300 * i, 480);
        gridColor_[i].setColor(sf::Color::Yellow);
        backgroundColor_[i].setFont(font_);
        backgroundColor_[i].setPosition(480 + 300 * i, 720);
        backgroundColor_[i].setColor(sf::Color::Yellow);
    }
    option_[0].setString("Open Grid:");
    option_[1].setString("Grid Color:");
    option_[2].setString("BackGround Color:");
    openGrid_[0].setString("close");
    openGrid_[1].setString("open");
    gridColor_[0].setString("white");
    gridColor_[1].setString("black");
    gridColor_[2].setString("brown");
    backgroundColor_[0].setString("white");
    backgroundColor_[1].setString("black");
    backgroundColor_[2].setString("brown");

    return_.setFont(font_);
    return_.setPosition(640, 840);
    return_.setString("return");
    return_.setColor(sf::Color::Green);
    focus[0] = focus[1] = -1;
}

void OptionScreen::handleInput(sf::RenderWindow &window)
{
    focus[0] = focus[1] = -1;
    sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    for (int i = 0; i < 3; i++)
    {
        if (i < 2)
        {
            if (openGrid_[i].getGlobalBounds().contains(mousePosition))
            {
                focus[0] = 0;
                focus[1] = i;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    Game::isGridOpen = i;
                }
                return;
            }
        }
        if (gridColor_[i].getGlobalBounds().contains(mousePosition))
        {
            focus[0] = 1;
            focus[1] = i;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Game::grid.setColor(i);
            }
            return;
        }
        if (backgroundColor_[i].getGlobalBounds().contains(mousePosition))
        {
            focus[0] = 2;
            focus[1] = i;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Game::setBackgroundColor(i);
            }
            return;
        }
    }
    if (return_.getGlobalBounds().contains(mousePosition))
    {
        focus[0] = 3;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Screen = std::make_shared<MenuScreen>();
        }
    }
}

void OptionScreen::update(sf::Time delta)
{
    for (int i = 0; i < 3; i++)
    {
        if (i < 2)
        {
            openGrid_[i].setColor(sf::Color::Yellow);
        }
        option_[i].setColor(sf::Color::Green);
        gridColor_[i].setColor(sf::Color::Yellow);
        backgroundColor_[i].setColor(sf::Color::Yellow);
    }
    return_.setColor(sf::Color::Green);
    switch (focus[0])
    {
    case 0:
        openGrid_[focus[1]].setColor(sf::Color::Blue);
        break;
    case 1:
        gridColor_[focus[1]].setColor(sf::Color::Blue);
        break;
    case 2:
        backgroundColor_[focus[1]].setColor(sf::Color::Blue);
        break;
    case 3:
        return_.setColor(sf::Color::Blue);
    default:
        break;
    }
}

void OptionScreen::render(sf::RenderWindow &window)
{
    window.draw(Game::background);
    if (Game::isGridOpen)
    {
        Game::grid.render(window);
    }
    for (auto &i : option_)
        window.draw(i);
    for (auto &i : openGrid_)
        window.draw(i);
    for (auto &i : gridColor_)
        window.draw(i);
    for (auto &i : backgroundColor_)
        window.draw(i);
    window.draw(return_);
}