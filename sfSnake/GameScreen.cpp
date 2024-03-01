#include <SFML/Graphics.hpp>

#include <random>
#include <memory>
#include <time.h>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "Game.h"

using namespace sfSnake;

GameScreen::GameScreen() : snake_()
{
}

void GameScreen::handleInput(sf::RenderWindow &window)
{
	snake_.handleInput(window);
}

void GameScreen::update(sf::Time delta)
{
	while (fruit_.size() <= 5)
	{
		static std::default_random_engine engine(time(NULL));
		static std::uniform_int_distribution<int> distribution(1, 200);
		int num = distribution(engine);
		if (num <= 25)
		{
			generateFruit(FruitColor::black);
		}
		else if (num <= 50)
		{
			generateFruit(FruitColor::brown);
		}
		else if (num <= 100)
		{
			generateFruit(FruitColor::red);
		}
		else if (num <= 150)
		{
			generateFruit(FruitColor::blue);
		}
		else
		{
			generateFruit(FruitColor::green);
		}
	}

	snake_.update(delta);
	snake_.checkFruitCollisions(fruit_);

	if (snake_.hitSelf())
		Game::Screen = std::make_shared<GameOverScreen>(snake_.getSize());
}

void GameScreen::render(sf::RenderWindow &window)
{
	window.draw(Game::background);
	if (Game::isGridOpen)
	{
		Game::grid.render(window);
	}
	snake_.render(window);

	for (auto fruit : fruit_)
		fruit.render(window);
}

void GameScreen::generateFruit(FruitColor color)
{
	static std::default_random_engine engine(time(NULL));
	static std::uniform_int_distribution<int> xDistribution(0, Game::Width - SnakeNode::Width);
	static std::uniform_int_distribution<int> yDistribution(0, Game::Height - SnakeNode::Height);

	fruit_.push_back(Fruit(color, sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}