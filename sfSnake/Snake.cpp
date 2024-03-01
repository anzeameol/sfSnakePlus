#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include <cmath>

#include "Snake.h"
#include "Game.h"
#include "Fruit.h"
#include "SnakeNode.h"
#include "GameOverScreen.h"
#include "Math.h"

using namespace sfSnake;

const int Snake::InitialSize = 5;
const float Snake::speed = 15;

Snake::Snake() : direction_(sf::Vector2f(0, -1)), rotation_{0}, hitSelf_{false}
{
	headTexture_.loadFromFile("Image/snakeHead.png");
	headTexture_.setSmooth(true);
	headSprite_.setTexture(headTexture_);
	headSprite_.setScale(SnakeNode::Width / headSprite_.getLocalBounds().width, SnakeNode::Width / headSprite_.getLocalBounds().height);
	headSprite_.setOrigin(headSprite_.getLocalBounds().left + headSprite_.getLocalBounds().width / 2,
						  headSprite_.getLocalBounds().top + headSprite_.getLocalBounds().height / 2);
	position_.x = Game::Width / 2;
	position_.y = Game::Height / 2;
	headSprite_.setPosition(position_);
	initNodes();

	pickupBuffer_.loadFromFile("Sounds/pickup.aiff");
	pickupSound_.setBuffer(pickupBuffer_);
	pickupSound_.setVolume(30);

	dieBuffer_.loadFromFile("Sounds/die.wav");
	dieSound_.setBuffer(dieBuffer_);
	dieSound_.setVolume(50);
}

void Snake::initNodes()
{
	float h = headSprite_.getGlobalBounds().height;
	for (int i = 0; i < Snake::InitialSize; ++i)
	{
		nodes_.push_back(SnakeNode(sf::Vector2f(position_.x,
												position_.y + h + (SnakeNode::Width * i))));
	}
}

void Snake::setDirectionToMouse(sf::Vector2f mousePosition)
{
	sf::Vector2f direction(mousePosition - position_);
	float length = getLength(direction);
	direction.x = direction.x / length;
	direction.y = direction.y / length;
	direction_ = direction;
	rotation_ = getAngle(direction_);
}

void Snake::handleInput(sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		setDirectionToMouse(sf::Vector2f(mousePosition.x, mousePosition.y));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction_ = sf::Vector2f(0, -1);
		rotation_ = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction_ = sf::Vector2f(0, 1);
		rotation_ = 180;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction_ = sf::Vector2f(-1, 0);
		rotation_ = 270;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction_ = sf::Vector2f(1, 0);
		rotation_ = 90;
	}
}

void Snake::update(sf::Time delta)
{
	move();
	checkEdgeCollisions();
	checkSelfCollisions();
}

void Snake::checkFruitCollisions(std::vector<Fruit> &fruits)
{
	decltype(fruits.begin()) toRemove = fruits.end();

	for (auto it = fruits.begin(); it != fruits.end(); ++it)
	{
		if (it->getBounds().intersects(headSprite_.getGlobalBounds()))
			toRemove = it;
	}

	if (toRemove != fruits.end())
	{
		switch (toRemove->getColor())
		{
		case FruitColor::red:
			grow();
			grow();
			grow();
			break;
		case FruitColor::blue:
			grow();
			grow();
			break;
		case FruitColor::green:
			grow();
			grow();
			break;
		case FruitColor::brown:
			break;
		case FruitColor::black:
			break;
		default:
			break;
		}
		pickupSound_.play();
		grow();
		fruits.erase(toRemove);
	}
}

void Snake::grow()
{
	nodes_.push_back(SnakeNode(nodes_[nodes_.size() - 1].getPosition(), nodes_[nodes_.size() - 1].getRotation()));
}

unsigned Snake::getSize() const
{
	return nodes_.size();
}

bool Snake::hitSelf() const
{
	return hitSelf_;
}

void Snake::checkSelfCollisions()
{
	sf::Vector2f centre = headSprite_.getPosition();
	sf::Vector2f head = getLoc(centre, SnakeNode::Radius, rotation_ + 270);
	for (decltype(nodes_.size()) i = 0; i < nodes_.size(); ++i)
	{
		if (getDistence(head, nodes_[i].getPosition()) < SnakeNode::Radius * 0.8)
		{
			dieSound_.play();
			sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
			hitSelf_ = true;
		}
	}
}

void Snake::checkEdgeCollisions()
{
	if (headSprite_.getPosition().x < 0)
	{
		position_.x = Game::Width;
	}
	else if (headSprite_.getPosition().x > Game::Width)
	{
		position_.x = 0;
	}

	if (headSprite_.getPosition().y < 0)
	{
		position_.y = Game::Height;
	}
	else if (headSprite_.getPosition().y > Game::Height)
	{
		position_.y = 0;
	}
	headSprite_.setPosition(position_);
}

void Snake::move()
{
	for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
	{
		nodes_[i].setPosition(nodes_.at(i - 1).getPosition());
		nodes_[i].setRotation(nodes_.at(i - 1).getRotation());
	}
	nodes_[0].setPosition(headSprite_.getPosition());
	nodes_[0].setRotation(headSprite_.getRotation());

	headSprite_.setRotation(rotation_);
	position_ += direction_ * speed;
	headSprite_.setPosition(position_);
}

void Snake::render(sf::RenderWindow &window)
{
	window.draw(headSprite_);
	for (auto &node : nodes_)
		node.render(window);
}