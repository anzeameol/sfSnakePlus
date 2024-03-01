#include <SFML/Graphics.hpp>

#include "Fruit.h"

using namespace sfSnake;

const float Fruit::Radius = 5.f;

Fruit::Fruit(FruitColor color, sf::Vector2f position)
{
	shape_.setPosition(position);
	shape_.setRadius(Fruit::Radius);
	fruitColor = color;
	switch (fruitColor)
	{
	case FruitColor::red:
		shape_.setFillColor(sf::Color::Red);
		break;
	case FruitColor::blue:
		shape_.setFillColor(sf::Color::Blue);
		break;
	case FruitColor::green:
		shape_.setFillColor(sf::Color::Green);
		break;
	case FruitColor::brown:
		shape_.setFillColor(sf::Color(96, 57, 18, 255));
		break;
	case FruitColor::black:
		shape_.setFillColor(sf::Color::Black);
		break;
	default:
		shape_.setFillColor(sf::Color::Red);
		break;
	}
	shape_.setOutlineColor(sf::Color::White);
	shape_.setOutlineThickness(-1.f);
}

FruitColor Fruit::getColor()
{
	return fruitColor;
}

void Fruit::render(sf::RenderWindow &window)
{
	window.draw(shape_);
}

sf::FloatRect Fruit::getBounds() const
{
	return shape_.getGlobalBounds();
}