#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
	enum class FruitColor
	{
		red,
		green,
		blue,
		brown,
		black
	};

	class Fruit
	{
	public:
		Fruit(FruitColor color, sf::Vector2f position);

		void render(sf::RenderWindow &window);
		FruitColor getColor();
		sf::FloatRect getBounds() const;

	private:
		sf::CircleShape shape_;
		FruitColor fruitColor;
		static const float Radius;
	};
}

#endif