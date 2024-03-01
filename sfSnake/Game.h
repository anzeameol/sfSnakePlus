#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>
#include <cmath>

#include "Screen.h"
#include "Grid.h"

namespace sfSnake
{
	enum class BackgroundColor
	{
		white,
		black,
		brown
	};

	class Game
	{
	public:
		Game();

		void run();

		void handleInput();
		void update(sf::Time delta);
		void render();

		static void setBackgroundColor(BackgroundColor color);
		static void setBackgroundColor(int color);
		static unsigned int Width;
		static unsigned int Height;

		static BackgroundColor backgroundColor;
		static Grid grid;
		static sf::RectangleShape background;
		static bool isGridOpen;
		static std::shared_ptr<Screen> Screen;

	private:
		sf::RenderWindow window_;
		sf::Music bgMusic_;

		static const sf::Time TimePerFrame;
	};
}

#endif