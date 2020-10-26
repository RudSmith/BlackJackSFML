#include "Game.h"

Game::Game()
{
	// initialize a window
	this->initWindow();
	this->initButtons();
	this->initDeck();
	this->initPlayers();
}

Game::~Game()
{
	// free the allocated memory for the window
	delete this->m_window;

	// free the allocated memory for the buttons
	delete this->m_hit;
	delete this->m_stand;
	delete this->m_double;
	delete this->m_escape_to_menu;

	delete this->m_croupier;
	delete this->m_user;
}

void Game::initWindow()
{
	// create a new sfml window 
	this->m_window = new sf::RenderWindow(sf::VideoMode(1100, 650), "BlackJack", sf::Style::Titlebar | sf::Style::Close);
	this->m_font = new sf::Font;
	this->m_font->loadFromFile("Fonts/arial.ttf");

	// Set backgound image
	this->m_backgroundTexture = new sf::Texture;
	this->m_backgroundTexture->loadFromFile("Images/Background.jpg");
	this->m_backgroundSprite.setTexture(*this->m_backgroundTexture);
	this->m_backgroundSprite.setScale(1.757, 1.78);
}

void Game::initDeck()
{
}

void Game::initButtons()
{
	this->m_hit = new Button(700, 550, 70, 50, this->m_font, "Hit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_stand = new Button(800, 550, 70, 50, this->m_font, "Stand", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_double = new Button(900, 550, 70, 50, this->m_font, "Double", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_escape_to_menu = new Button(0, 0, 70, 50, this->m_font, "Exit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
}

void Game::initPlayers()
{
	this->m_croupier = new Player("Croupier");
	this->m_user = new Player();
}

void Game::updateEvents()
{
	while (this->m_window->pollEvent(this->m_event))
	{
		if (this->m_event.type == sf::Event::Closed)
			this->m_window->close();
	}
}

void Game::update()
{
	this->updateEvents();
	this->updateMousePosition();

	this->m_hit->update(m_worldPos);
	this->m_stand->update(m_worldPos);
	this->m_double->update(m_worldPos);
	this->m_escape_to_menu->update(m_worldPos);
}

void Game::render()
{
	this->m_window->clear();
	this->m_window->draw(this->m_backgroundSprite);

	this->m_hit->render(this->m_window);
	this->m_stand->render(this->m_window);
	this->m_double->render(this->m_window);
	this->m_escape_to_menu->render(this->m_window);

	this->m_window->display();
}

void Game::run()
{
	// this is basically the main loop of the prog
	while (this->m_window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updateMousePosition()
{
	this->m_pixelPos = sf::Mouse::getPosition(*m_window);
	this->m_worldPos = m_window->mapPixelToCoords(m_pixelPos);
}