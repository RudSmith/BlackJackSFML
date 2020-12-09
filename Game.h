#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Player.h"
#include "Deck.h"

class Game
{
public:
	// Create a game
	Game();
	// Destroy the game
	~Game();
	
	// Start the game
	void run();
	// Check if game is running
	bool isRunning();

private:
	// Inititalize the main window
	void initWindow();
	// Initialize the buttons
	void initButtons();
	// Inititalize the players
	void initPlayers();



	// Update current events
	void updateEvents();
	// Update all the states of the window`s objects
	void update();
	// Update current mouse position
	void updateMousePosition();
	// Update current state of the buttons
	void updateButtons();
	


	// Render all the objects of the window
	void render();
	// Render hit and stand buttons
	void renderGameplayButtons();
	// Render the cards
	void renderCards(const std::vector<size_t> &hand);



	// Handler of the hit button press
	void hitPressHandle();
	// Handler of the stand button press
	void standPressHandle();
	// Handler of the exit button press
	void exitPressHandle();
	// Handler of the retry button press
	void retryPressHandle();



	// Put a card into croupier`s hand
	void croupierGetsCard();
	// In this metod croupier makes his move
	void croupierMakesMove();



	// Check player points condition when taking a card
	void analyzePlayerPoints(Player &player);
	// Pick a winner
	void detectTheWinner();



	// Window object 
	sf::RenderWindow *m_window;
	// Event object
	sf::Event m_event;

	// Mouse position in pixels 
	sf::Vector2i m_pixelPos;
	// Mouse position in coords
	sf::Vector2f m_worldPos;

	// Where to print a card = player.initCardPos + cardPrintOffset
	const sf::Vector2f m_card_print_offset{ 35.f, 0.f };

	// Uploadable font
	sf::Font* m_font;


	// Button to take another card
	Button* m_hit;
	// Button to start croupier`s turn
	Button* m_stand;
	// Button to escape to main menu
	Button* m_escape_to_menu;
	// Button to recreate the game
	Button* m_retry;

	// Deck with cards
	Deck m_deck;

	// Croupier
	Player *m_croupier;
	// User
	Player *m_player;

	// Background image texture
	sf::Texture *m_backgroundTexture;
	// Background image sprite
	sf::Sprite m_backgroundSprite;

	// This text is shown where game ends
	sf::Text m_winnerInfoText;
	
	// Card face up texture
	sf::Texture m_cardFaceUpTexture;
	// Card face up sprite
	sf::Sprite m_cardFaceUpSprite;

};

