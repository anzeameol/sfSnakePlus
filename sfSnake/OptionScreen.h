#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Screen.h"

namespace sfSnake
{
    class OptionScreen : public Screen
    {
    public:
        OptionScreen();

        void handleInput(sf::RenderWindow &window) override;
        void update(sf::Time delta) override;
        void render(sf::RenderWindow &window) override;

    private:
        sf::Font font_;
        std::vector<sf::Text> option_;
        std::vector<sf::Text> openGrid_;
        std::vector<sf::Text> gridColor_;
        std::vector<sf::Text> backgroundColor_;
        sf::Text return_;
        int focus[2];
    };
}