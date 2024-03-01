#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{

	class SnakeNode
	{
	public:
		SnakeNode(sf::Vector2f position, float rotation = 0.f);

		void setRotation(float rotation);
		void setPosition(sf::Vector2f position);

		void move(sf::Vector2f offset);
		void rotate(float angle);

		void render(sf::RenderWindow &window);
		sf::Vector2f getLeftBottom() const;
		sf::Vector2f getPosition() const;
		float getRotation() const;
		sf::FloatRect getBounds();

		static const float Width;
		static const float Height;
		static const float Radius;

	private:
		sf::RectangleShape rectangle;
		sf::CircleShape circle;
		sf::Vector2f position_;
		float rotation_;
	};
}

#endif