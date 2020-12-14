#include "Game.h"

#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-window.lib")


Game::Game()
{
	// fully initialize playing window
	initWindow();
	initButtons();
	initPlayers();
}

Game::~Game()
{
	// delete window
	delete m_window;

	// delete font
	delete m_font;

	// delete buttons
	delete m_hit;
	delete m_stand;
	delete m_escape_to_menu;
	delete m_retry;

	// delete players
	delete m_croupier;
	delete m_player;
}

void Game::run()
{
	// this is basically the main loop of the prog
	while (m_window->isOpen())
	{
		update();
		render();
	}
}

bool Game::isRunning()
{
	// If the window is open, then game is running
	return m_window->isOpen();
}

void Game::initWindow()
{
	// create a new sfml window 
	m_window = new sf::RenderWindow(sf::VideoMode(1100, 650), "BlackJack", sf::Style::Titlebar | sf::Style::Close);
	m_font = new sf::Font;
	m_font->loadFromFile("Fonts/arial.ttf");

	// Set backgound image
	m_backgroundTexture = new sf::Texture;
	m_backgroundTexture->loadFromFile("Images/Background.jpg");
	m_backgroundSprite.setTexture(*m_backgroundTexture);
	m_backgroundSprite.setScale(1.757, 1.78);
}

void Game::initButtons()
{
	// Initialize the buttons
	m_hit = new Button(800, 550, 70, 50, m_font, "Hit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	m_stand = new Button(900, 550, 70, 50, m_font, "Stand", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	m_escape_to_menu = new Button(1030, 0, 70, 50, m_font, "Exit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	m_retry = new Button(950, 0, 70, 50, m_font, "Retry", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
}

void Game::initPlayers()
{
	// Set players`s initial card positions
	const sf::Vector2f croupier_init_card_pos{ 0.f, 0.f };
	const sf::Vector2f player_init_card_pos{ 0.f, 440.f };

	// Create players
	m_croupier = new Player(croupier_init_card_pos, "Croupier");
	m_player = new Player(player_init_card_pos, "Player");

	// Load a face up card texture and set its position to croupier first card`s position
	m_cardFaceUpTexture.loadFromFile("Images/back.png");
	m_cardFaceUpSprite.setTexture(m_cardFaceUpTexture);
	m_cardFaceUpSprite.setPosition(m_croupier->card_init_pos());

	// Pass the move to player
	m_player->setMove(true);

	// Give two cards to the croupier
	croupierGetsCard();
	croupierGetsCard();

	// Give two cards to the player
	hitPressHandle();
	hitPressHandle();
}

// Update SFML standart events
void Game::updateEvents()
{
	// Check if something is clicked and handle click events
	while (m_window->pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window->close();
		else if (m_event.type == sf::Event::MouseButtonPressed && m_event.mouseButton.button == sf::Mouse::Left)
		{
			if (m_hit->isPressed())
			{
				hitPressHandle();
			}
			else if (m_stand->isPressed())
			{
				standPressHandle();
			}
			else if (m_escape_to_menu->isPressed())
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

void Game::update()
{
	updateMousePosition();
	updateButtons();
	updateEvents();
}

void Game::updateMousePosition()
{
	m_pixelPos = sf::Mouse::getPosition(*m_window);
	// Calculate current mouse position in coords
	m_worldPos = m_window->mapPixelToCoords(m_pixelPos);
}

void Game::updateButtons()
{
	// Update buttons states
	m_hit->update(m_worldPos);
	m_stand->update(m_worldPos);
	m_escape_to_menu->update(m_worldPos);
	m_retry->update(m_worldPos);
}

void Game::render()
{
	// Clear the window
	m_window->clear();
	// Draw background texture
	m_window->draw(m_backgroundSprite);

	// If it is player`s move, render hit and stand buttons
	if(m_player->isMoving())
		renderGameplayButtons();

	// Render other buttons
	m_escape_to_menu->render(m_window);
	m_retry->render(m_window);

	// Render cards
	renderCards(m_croupier->Hand());
	renderCards(m_player->Hand());

	// Display the text that contains info about the winner
	// If game is not finished, it is empty
	m_window->draw(m_winnerInfoText);

	// Display the window
	m_window->display();
}

void Game::renderGameplayButtons()
{
	m_hit->render(m_window);
	m_stand->render(m_window);
}

void Game::renderCards(const std::vector<size_t>& hand)
{
	// If given hand is croupier`s hand and player is now moving, then draw the first card of the croupier with face up
	if (hand == m_croupier->Hand() && m_player->isMoving())
	{
		m_window->draw(m_cardFaceUpSprite);
		
		// Then draw other cards
		for (size_t card_iter{ 1 }; card_iter < hand.size(); ++card_iter)
			m_window->draw(m_deck.at(hand.at(card_iter)).sprite());
	}
	else
	{
		// If given hand is player`s card, then normally draw it
		for (auto &card : hand)
			m_window->draw(m_deck.at(card).sprite());
	}
}

void Game::hitPressHandle()
{
	// If player takes his first card, set it`s position = player`s initial card position
	if (m_player->Hand().empty())
		m_deck.at(m_deck.look_at_top_card()).setPosition(m_player->card_init_pos());
	else
		// Else card`s position = card initial position + offset
		m_deck.at(m_deck.look_at_top_card()).setPosition(m_deck.at(m_player->Hand().at(m_player->Hand().size() - 1)).sprite().getPosition() + m_card_print_offset);

	// Increase player`s points
	m_player->setPoints(m_player->Points() + m_deck.at(m_deck.look_at_top_card()).points());
	// Add card to player`s deck
	m_player->addCard(m_deck.pop_top_card());
	// Check what actually is happening with player`s deck and score
	// I mean, check if he took to much cards or has special case, when ace gives him only 1 point
	analyzePlayerPoints(*m_player);

}

void Game::standPressHandle()
{
	// Pass the move to the croupier
	m_player->setMove(false);
	m_croupier->setMove(true);
	m_hit->disable();
	m_stand->disable();
	croupierMakesMove();
}

void Game::exitPressHandle()
{
	m_window->close();
}

void Game::retryPressHandle()
{
	// Recreate the game
	m_window->close();
	Game newGame;
	newGame.run();
}

// This method is totally same as the hitPressHandle(), but it is for croupier only
void Game::croupierGetsCard()
{
	if (m_croupier->Hand().empty())
		m_deck.at(m_deck.look_at_top_card()).setPosition(m_croupier->card_init_pos());
	else
		m_deck.at(m_deck.look_at_top_card()).setPosition(m_deck.at(m_croupier->Hand().at(m_croupier->Hand().size() - 1)).sprite().getPosition() + m_card_print_offset);

	m_croupier->setPoints(m_croupier->Points() + m_deck.at(m_deck.look_at_top_card()).points());
	m_croupier->addCard(m_deck.pop_top_card());
	analyzePlayerPoints(*m_croupier);
}

void Game::croupierMakesMove()
{
	// Croupier draw enough cards
	while (m_croupier->Points() < 17)
		croupierGetsCard();

	// Game detects a winner
	detectTheWinner();
}

void Game::analyzePlayerPoints(Player& player)
{
	// If player got an ace, increment his aces counter
	if (m_deck.at(player.Hand().at(player.Hand().size() - 1)).points() == 11)
		player.setAcesCount(player.aces_count() + 1);

	// If player`s points > 21
	if (player.Points() > 21)
	{
		// And if he has aces
		if (player.aces_count() > 0)
			for (size_t iter{}; iter < player.aces_count(); ++iter)
			{
				// For each ace, reduce player`s points (10 for ace)
				player.setPoints(player.Points() - 10);
				player.setAcesCount(player.aces_count() - 1);
			}
		else
			// If he has no aces, then he took too much cards
			standPressHandle();
	}		
}

void Game::detectTheWinner()
{
	// Initialize the text about the winner
	m_winnerInfoText.setFont(*m_font);
	m_winnerInfoText.setPosition(550.f, 325.f);

	// If player won
	if ((m_player->Points() <= 21 && m_player->Points() > m_croupier->Points()) || (m_croupier->Points() > 21 && m_player->Points() <= 21))
	{
		// Output that he won
		m_winnerInfoText.setString("You win!\n");
	}
	// If player lose
	else if ((m_croupier->Points() <= 21 && m_croupier->Points() > m_player->Points()) || (m_player->Points() > 21 && m_croupier->Points() <= 21))
	{
		// Output that he lose
		m_winnerInfoText.setString("You lose.\n");
	}
	else
	{
		// If nobody won, output that game is draw
		m_winnerInfoText.setString("Round draw.\n");
	}

	// Output info about player`s points
	m_winnerInfoText.setString(m_winnerInfoText.getString() + "You have " + std::to_string(m_player->Points()) + " points.\n");
	m_winnerInfoText.setString(m_winnerInfoText.getString() + "Croupier has " + std::to_string(m_croupier->Points()) + " points.\n");
}

