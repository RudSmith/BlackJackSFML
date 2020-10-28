#include "Game.h"

Game::Game()
{
	// fully initialize playing window
	this->initWindow();
	this->initButtons();
	this->initPlayers();
}

Game::~Game()
{
	// delete window
	delete this->m_window;

	// delete stuff
	delete this->m_backgroundTexture;
	delete this->m_font;

	// delete buttons
	delete this->m_hit;
	delete this->m_stand;
	delete this->m_double;
	delete this->m_escape_to_menu;

	// delete players
	delete this->m_croupier;
	delete this->m_user;
}

// Main method, that starts the game and keeps it work
void Game::run()
{
	// this is basically the main loop of the prog
	while (this->m_window->isOpen())
	{
		this->update();
		this->render();
	}
}

// Setting properties of main window and its background
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

// Setting properties of buttons, that are in the main window
void Game::initButtons()
{
	// Set buttons
	this->m_hit = new Button(700, 550, 70, 50, this->m_font, "Hit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_stand = new Button(800, 550, 70, 50, this->m_font, "Stand", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_double = new Button(900, 550, 70, 50, this->m_font, "Double", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_escape_to_menu = new Button(0, 0, 70, 50, this->m_font, "Exit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
}

// Creating two players
void Game::initPlayers()
{
	const sf::Vector2f croupier_init_card_pos{ 100.f, 0.f };
	const sf::Vector2f player_init_card_pos{ 0.f, 300.f };

	this->m_croupier = new Player(croupier_init_card_pos, "Croupier");
	this->m_user = new Player(player_init_card_pos);

	this->m_croupier->addCard(this->m_deck.top_card());
	this->m_croupier->addCard(this->m_deck.top_card());

	this->m_user->addCard(this->m_deck.top_card());
	this->m_user->addCard(this->m_deck.top_card());
}

// Update SFML standart events
void Game::updateEvents()
{
	while (this->m_window->pollEvent(this->m_event))
	{
		if (this->m_event.type == sf::Event::Closed)
			this->m_window->close();
		else if (this->m_event.type == sf::Event::MouseButtonPressed && this->m_event.mouseButton.button == sf::Mouse::Left);
	}
}

// Update states of user objects
void Game::update()
{
	this->updateMousePosition();
	this->updateButtons();
	this->updateEvents();
}

// Calculate current mouse position in coords
void Game::updateMousePosition()
{
	this->m_pixelPos = sf::Mouse::getPosition(*m_window);
	this->m_worldPos = m_window->mapPixelToCoords(m_pixelPos);
}

void Game::updateButtons()
{
	// Upd buttons state
	this->m_hit->update(m_worldPos);
	this->m_stand->update(m_worldPos);
	this->m_double->update(m_worldPos);
	this->m_escape_to_menu->update(m_worldPos);
}

// Show background, buttons and cards
void Game::render()
{
	this->m_window->clear();
	this->m_window->draw(this->m_backgroundSprite);
	this->renderButtons();

	this->renderCards(this->m_croupier->Hand());
	this->renderCards(this->m_user->Hand());

	this->m_window->display();
}

void Game::renderButtons()
{
	this->m_hit->render(this->m_window);
	this->m_stand->render(this->m_window);
	this->m_double->render(this->m_window);
	this->m_escape_to_menu->render(this->m_window);
}

void Game::renderCards(const std::vector<Card>& hand)
{
	for (auto card_iter : hand)
	{
		this->m_window->draw(card_iter.sprite());
	}
}

