#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "SnakeNode.h"
#include "Fruit.h"

namespace sfSnake
{

	class Snake
	{
	public:
		Snake();

		void handleInput(sf::RenderWindow &window);
		void update(sf::Time delta);
		void render(sf::RenderWindow &window);
		void setDirectionToMouse(sf::Vector2f mousePosition);
		void checkFruitCollisions(std::vector<Fruit> &fruits);

		bool hitSelf() const;

		unsigned getSize() const;

	private:
		void move();
		void grow();
		void checkEdgeCollisions();
		void checkSelfCollisions();
		void initNodes();

		bool hitSelf_;

		sf::Vector2f position_;
		sf::Vector2f direction_;
		float rotation_;

		sf::SoundBuffer pickupBuffer_;
		sf::Sound pickupSound_;

		sf::SoundBuffer dieBuffer_;
		sf::Sound dieSound_;

		sf::Sprite headSprite_;
		sf::Texture headTexture_;
		std::vector<SnakeNode> nodes_;

		static const int InitialSize;
		static const float speed;
	};
}

#endif