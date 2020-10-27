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

	// Render all sprites
	void render();

	// -------------------------- MAIN OBJECT SECTION -------------------------- //
	// Window object 
	sf::RenderWindow *m_window;
	// Event object
	sf::Event m_event;

	// Mouse position in pixels 
	sf::Vector2i m_pixelPos;
	// Mouse position in coords
	sf::Vector2f m_worldPos;

	// Uploadable font
	sf::Font* m_font;

	// Button to take another card
	Button* m_hit;
	// Button to start croupier`s turn
	Button* m_stand;
	// Button to double your bet and take another card
	Button* m_double;
	// Button to escape to main menu
	Button* m_escape_to_menu;

	Deck deck;

	// -------------------------- PLAYERS SECTION -------------------------- //
	// Actual player
	Player *m_croupier;
	// Bot croupier
	Player *m_user;

	// -------------------------- TEXTURE SECTION -------------------------- //
	// Background image txtr
	sf::Texture *m_backgroundTexture;
	
	// -------------------------- SPRITE SECTION -------------------------- //
	// Background image sprite
	sf::Sprite m_backgroundSprite;

};

