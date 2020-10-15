#include "Game.h"

// Initializers
void Game::initWindow()
{
	// create a new sfml window 
	this->window = new sf::RenderWindow(sf::VideoMode(1100, 650), "BlackJack", sf::Style::Titlebar | sf::Style::Close);
}

// Constructors/Destructors
Game::Game()
{
	// initialize a window
	this->initWindow();
	this->initButtons();
}

Game::~Game()
{
	// free the allocated memory for the window
	delete this->window;
	delete this->hit;
}

// Methods
void Game::updateEvents()
{
	// this loop is updating events
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateEvents();

	this->pixelPos = sf::Mouse::getPosition(*window);
	this->worldPos = window->mapPixelToCoords(pixelPos);

	this->hit->update(worldPos);
}

void Game::render()
{
	this->window->clear();

	this->hit->render(this->window);

	this->window->display();
}

void Game::run()
{
	// this is basically the main loop of the prog
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::initDeck()
{
}

void Game::initButtons()
{
	this->hit = new Button(100, 100, 150, 50, this->font, "Hit", sf::Color::White, sf::Color::Red, sf::Color::Blue);
}

