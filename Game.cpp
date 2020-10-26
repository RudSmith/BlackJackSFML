#include "Game.h"

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

	// free the allocated memory for the buttons
	delete this->m_hit;
	delete this->m_stand;
	delete this->m_double;
	delete this->m_escape_to_menu;
}

void Game::initWindow()
{
	// create a new sfml window 
	this->window = new sf::RenderWindow(sf::VideoMode(1100, 650), "BlackJack", sf::Style::Titlebar | sf::Style::Close);
	this->font = new sf::Font;
	this->font->loadFromFile("Fonts/arial.ttf");
}

void Game::initDeck()
{
}

void Game::initButtons()
{
	this->m_hit = new Button(700, 550, 70, 50, this->font, "Hit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_stand = new Button(800, 550, 70, 50, this->font, "Stand", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_double = new Button(900, 550, 70, 50, this->font, "Double", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_escape_to_menu = new Button(0, 0, 70, 50, this->font, "Exit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateEvents();
	this->updateMousePosition();

	this->m_hit->update(worldPos);
	this->m_stand->update(worldPos);
	this->m_double->update(worldPos);
	this->m_escape_to_menu->update(worldPos);
}

//
void Game::render()
{
	this->window->clear();

	this->m_hit->render(this->window);
	this->m_stand->render(this->window);
	this->m_double->render(this->window);
	this->m_escape_to_menu->render(this->window);

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

void Game::updateMousePosition()
{
	this->pixelPos = sf::Mouse::getPosition(*window);
	this->worldPos = window->mapPixelToCoords(pixelPos);
}




