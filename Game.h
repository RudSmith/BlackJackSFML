#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class Game
{
public:
	// Default constructor
	Game();
	// Default destructor
	~Game();
	
	// Start game
	void run();
	

private:
	// Initialize window properties
	void initWindow();
	// Initialize deck properties
	void initDeck();
	// Initialize buttons properties
	void initButtons();

	// Update all sfml events
	void updateEvents();
	// Update all objects states
	void update();
	// Render all sprites
	void render();

	// Get current mouse position
	void updateMousePosition();

	// Window object 
	sf::RenderWindow *m_window;
	// Event object
	sf::Event m_event;

	// Mouse position in pixels 
	sf::Vector2i m_pixelPos;
	// Mouse position in float
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

	// -------------------------- TEXTURE SECTION -------------------------- //
	sf::Texture *m_backgroundTexture;
	
	// -------------------------- SPRITE SECTION -------------------------- //
	sf::Sprite m_backgroundSprite;

};

