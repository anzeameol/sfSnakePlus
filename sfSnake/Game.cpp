#include <SFML/Graphics.hpp>

#include <memory>

#include "MenuScreen.h"
#include "Game.h"

using namespace sfSnake;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 10.f);

std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();

unsigned int Game::Width = 1280;
unsigned int Game::Height = 960;
Grid Game::grid(GridColor::white);
bool Game::isGridOpen = 0;
sf::RectangleShape Game::background(sf::Vector2f(Width, Height));
BackgroundColor Game::backgroundColor = BackgroundColor::black;

Game::Game()
	: window_(sf::VideoMode(Game::Width, Game::Height), "sfSnake", sf::Style::Titlebar | sf::Style::Close)
{
	bgMusic_.openFromFile("Music/bg_music.wav");
	bgMusic_.setLoop(true);
	bgMusic_.play();
}

void Game::setBackgroundColor(BackgroundColor color)
{
	backgroundColor = color;
	switch (backgroundColor)
	{
	case BackgroundColor::white:
		background.setFillColor(sf::Color::White);
		break;
	case BackgroundColor::black:
		background.setFillColor(sf::Color::Black);
		break;
	case BackgroundColor::brown:
		background.setFillColor(sf::Color(96, 57, 18, 255));
		break;
	default:
		break;
	}
}

void Game::setBackgroundColor(int color)
{
	switch (color)
	{
	case 0:
		backgroundColor = BackgroundColor::white;
		background.setFillColor(sf::Color::White);
		break;
	case 1:
		backgroundColor = BackgroundColor::black;
		background.setFillColor(sf::Color::Black);
		break;
	case 2:
		backgroundColor = BackgroundColor::brown;
		background.setFillColor(sf::Color(96, 57, 18, 255));
		break;
	default:
		break;
	}
}

void Game::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Resized)
		{
			window_.setSize(sf::Vector2u(Width, Height));
		}
		if (event.type == sf::Event::Closed)
			window_.close();
	}

	Game::Screen->handleInput(window_);
}

void Game::update(sf::Time delta)
{
	Game::Screen->update(delta);
}

void Game::render()
{
	window_.clear();
	Game::Screen->render(window_);
	window_.display();
}

void Game::run()
{
	background.setFillColor(sf::Color::Black);

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}