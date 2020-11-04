#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Player.h"
#include "Deck.h"

class Game
{
public:
	// ----------- Constructors and desctructors ----------- // 
	Game();
	~Game();
	
	// Start game
	void run();
	

private:
	// ----------- Initializers ----------- //
	void initWindow();
	void initButtons();
	void initPlayers();

	// ----------- Updaters ----------- //
	void updateEvents();
	void update();
	void updateMousePosition();
	void updateButtons();

	// ----------- Renderers ----------- //
	void render();
	void renderButtons();
	void renderCards(const std::vector<size_t> &hand);

	// ----------- Button click handlers ----------- //
	void hitPressHandle();
	void standPressHandle();
	void doublePressHandle();
	void exitPressHandle();
	// Croupier special case
	void croupierGetsCard();

	// Check player points condition when taking a card
	void analyzePlayerPoints(Player &player);

	// -------------------------- MAIN OBJECT SECTION -------------------------- //
	// Window object 
	sf::RenderWindow *m_window;
	// Event object
	sf::Event m_event;

	// Mouse position in pixels 
	sf::Vector2i m_pixelPos;
	// Mouse position in coords
	sf::Vector2f m_worldPos;

	const sf::Vector2f m_card_print_offset{ 35.f, 0.f };

	// Uploadable font
	sf::Font* m_font;

	// -------------------------- BUTTONS SECTION -------------------------- //
	// Button to take another card
	Button* m_hit;
	// Button to start croupier`s turn
	Button* m_stand;
	// Button to double your bet and take another card
	Button* m_double;
	// Button to escape to main menu
	Button* m_escape_to_menu;

	Deck m_deck;

	// -------------------------- PLAYERS SECTION -------------------------- //
	// Croupier
	Player *m_croupier;
	// User
	Player *m_user;

	// -------------------------- TEXTURE SECTION -------------------------- //
	// Background image txtr
	sf::Texture *m_backgroundTexture;
	sf::Texture m_cardFaceUpTexture;
	
	// -------------------------- SPRITE SECTION -------------------------- //
	// Background image sprite
	sf::Sprite m_backgroundSprite;
	sf::Sprite m_cardFaceUpSprite;

};

