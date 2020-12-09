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
	delete this->m_escape_to_menu;
	delete m_retry;

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

bool Game::isRunning()
{
	return m_window->isOpen();
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
	this->m_hit = new Button(800, 550, 70, 50, this->m_font, "Hit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_stand = new Button(900, 550, 70, 50, this->m_font, "Stand", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	this->m_escape_to_menu = new Button(1030, 0, 70, 50, this->m_font, "Exit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	m_retry = new Button(950, 0, 70, 50, this->m_font, "Retry", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
}

// Creating two players
void Game::initPlayers()
{
	const sf::Vector2f croupier_init_card_pos{ 0.f, 0.f };
	const sf::Vector2f player_init_card_pos{ 0.f, 440.f };

	this->m_croupier = new Player(croupier_init_card_pos, "Croupier");
	this->m_user = new Player(player_init_card_pos);

	this->m_cardFaceUpTexture.loadFromFile("Images/back.png");
	this->m_cardFaceUpSprite.setTexture(this->m_cardFaceUpTexture);
	this->m_cardFaceUpSprite.setScale(0.25f, 0.2f);
	this->m_cardFaceUpSprite.setPosition(this->m_croupier->card_init_pos());

	this->m_user->setMove(true);

	croupierGetsCard();
	croupierGetsCard();

	hitPressHandle();
	hitPressHandle();
}

// Update SFML standart events
void Game::updateEvents()
{
	while (this->m_window->pollEvent(this->m_event))
	{
		if (this->m_event.type == sf::Event::Closed)
			this->m_window->close();
		else if (this->m_event.type == sf::Event::MouseButtonPressed && this->m_event.mouseButton.button == sf::Mouse::Left)
		{
			if (this->m_hit->isPressed())
			{
				hitPressHandle();
			}
			else if (this->m_stand->isPressed())
			{
				standPressHandle();
			}
			else if (this->m_escape_to_menu->isPressed())
			{
				exitPressHandle();
			}
			else if (m_retry->isPressed())
			{
				retryPressHandle();
			}
		}
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
	this->m_escape_to_menu->update(m_worldPos);
	m_retry->update(m_worldPos);
}

// Show background, buttons and cards
void Game::render()
{
	this->m_window->clear();
	this->m_window->draw(this->m_backgroundSprite);

	if(this->m_user->isMoving())
		this->renderGameplayButtons();

	this->m_escape_to_menu->render(this->m_window);
	m_retry->render(this->m_window);

	this->renderCards(this->m_croupier->Hand());
	this->renderCards(this->m_user->Hand());

	this->m_window->draw(m_winnerInfoText);

	this->m_window->display();
}

void Game::renderGameplayButtons()
{
	this->m_hit->render(this->m_window);
	this->m_stand->render(this->m_window);
}

void Game::renderCards(const std::vector<size_t>& hand)
{
	if (hand == this->m_croupier->Hand() && m_user->isMoving())
	{
		this->m_window->draw(this->m_cardFaceUpSprite);

		for (size_t card_iter{ 1 }; card_iter < hand.size(); ++card_iter)
			this->m_window->draw(this->m_deck.at(hand.at(card_iter)).sprite());
	}
	else
	{
		for (auto card : hand)
			this->m_window->draw(this->m_deck.at(card).sprite());
	}
}

void Game::hitPressHandle()
{

	if (this->m_user->Hand().empty())
		this->m_deck.at(this->m_deck.look_at_top_card()).setPosition(this->m_user->card_init_pos());
	else
		this->m_deck.at(this->m_deck.look_at_top_card()).setPosition(this->m_deck.at(this->m_user->Hand().at(this->m_user->Hand().size() - 1)).sprite().getPosition() + this->m_card_print_offset);

	this->m_user->setPoints(m_user->Points() + m_deck.at(m_deck.look_at_top_card()).points());
	this->m_user->addCard(this->m_deck.pop_top_card());
	this->analyzePlayerPoints(*m_user);

}

void Game::standPressHandle()
{
	this->m_user->setMove(false);
	this->m_croupier->setMove(true);
	croupierMakesMove();
}

void Game::exitPressHandle()
{
	m_window->close();
}

void Game::retryPressHandle()
{
	m_window->close();
	Game newGame;
	newGame.run();
}

void Game::croupierGetsCard()
{
	if (this->m_croupier->Hand().empty())
		this->m_deck.at(this->m_deck.look_at_top_card()).setPosition(this->m_croupier->card_init_pos());
	else
		this->m_deck.at(this->m_deck.look_at_top_card()).setPosition(this->m_deck.at(this->m_croupier->Hand().at(this->m_croupier->Hand().size() - 1)).sprite().getPosition() + this->m_card_print_offset);

	this->m_croupier->setPoints(m_croupier->Points() + m_deck.at(m_deck.look_at_top_card()).points());
	this->m_croupier->addCard(this->m_deck.pop_top_card());
	this->analyzePlayerPoints(*m_croupier);
}

void Game::croupierMakesMove()
{
	while (m_croupier->Points() < 17)
		croupierGetsCard();

	detectTheWinner();
}

void Game::analyzePlayerPoints(Player& player)
{
	if (this->m_deck.at(player.Hand().at(player.Hand().size() - 1)).points() == 11)
		player.setAcesCount(player.aces_count() + 1);

	if (player.Points() > 21)
	{
		if (player.aces_count() > 0)
			for (size_t iter{}; iter < player.aces_count(); ++iter)
			{
				player.setPoints(player.Points() - 10);
				player.setAcesCount(player.aces_count() - 1);
			}
		else
			standPressHandle();
	}		
}

void Game::detectTheWinner()
{
	m_winnerInfoText.setFont(*m_font);
	m_winnerInfoText.setPosition(550.f, 325.f);

	if ((m_user->Points() <= 21 && m_user->Points() > m_croupier->Points()) || (m_croupier->Points() > 21 && m_user->Points() <= 21))
	{
		m_winnerInfoText.setString("You win!\n");
	}
	else if ((m_croupier->Points() <= 21 && m_croupier->Points() > m_user->Points()) || (m_user->Points() > 21 && m_croupier->Points() <= 21))
	{
		m_winnerInfoText.setString("You lose.\n");
	}
	else
	{
		m_winnerInfoText.setString("Round draw.\n");
	}

	m_winnerInfoText.setString(m_winnerInfoText.getString() + "You have " + std::to_string(m_user->Points()) + " points.\n");
	m_winnerInfoText.setString(m_winnerInfoText.getString() + "Croupier has " + std::to_string(m_croupier->Points()) + " points.\n");
}

