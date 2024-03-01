#include <SFML/Graphics.hpp>

#include <cassert>

#include "SnakeNode.h"
#include "Math.h"

using namespace sfSnake;

const float SnakeNode::Width = 20.f;
const float SnakeNode::Height = 6.f;
const float SnakeNode::Radius = SnakeNode::Width / 2;

SnakeNode::SnakeNode(sf::Vector2f position, float rotation)
	: position_{position}, rotation_{rotation}
{
	circle.setRadius(SnakeNode::Radius);
	circle.setOrigin(circle.getLocalBounds().left + circle.getLocalBounds().width / 2,
					 circle.getLocalBounds().top + circle.getLocalBounds().height / 2);
	circle.setPosition(position);
	circle.setRotation(rotation);
	circle.setFillColor(sf::Color::Yellow);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(-1.f);

	rectangle.setSize(sf::Vector2f(SnakeNode::Width, SnakeNode::Height));
	rectangle.setOrigin(rectangle.getLocalBounds().left + rectangle.getLocalBounds().width / 2,
						rectangle.getLocalBounds().top + rectangle.getLocalBounds().height / 2);
	rectangle.setPosition(position);
	rectangle.setRotation(rotation);
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(-1.f);
}

void SnakeNode::setPosition(sf::Vector2f position)
{
	position_ = position;
	circle.setPosition(position_);
	rectangle.setPosition(position_);
}

void SnakeNode::setRotation(float rotation)
{
	rotation_ = rotation;
	rectangle.setRotation(rotation_);
	circle.setRotation(rotation_);
}

void SnakeNode::move(sf::Vector2f offset)
{
	position_ += offset;
	circle.setPosition(position_);
	rectangle.setPosition(position_);
}

void SnakeNode::rotate(float angle)
{
	rotation_ += angle;
	while (rotation_ >= 360)
	{
		rotation_ -= 360;
	}
	circle.rotate(angle);
	rectangle.rotate(angle);
}

sf::Vector2f SnakeNode::getLeftBottom() const
{
	return sfSnake::getLoc(position_, 2 * Radius, rotation_ + 270);
}

sf::Vector2f SnakeNode::getPosition() const
{
	return position_;
}

float SnakeNode::getRotation() const
{
	return rotation_;
}

sf::FloatRect SnakeNode::getBounds()
{
	return circle.getGlobalBounds();
}

void SnakeNode::render(sf::RenderWindow &window)
{
	window.draw(circle);
	window.draw(rectangle);
}