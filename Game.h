#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <array>
#include "Button.h"
#include "Card.h"

class Game
{
public:
	// Constructors/Destructors
	Game();
	~Game();

	// Main methods

	// Update all events
	void updateEvents();
	// Update all states
	void update();
	// Render all sprites
	void render();
	// Start game
	void run();

	void updateMousePosition();

	// Card methods
	void initDeck();
	void initButtons();


private:
	// Initializers
	void initWindow();

	// Variables
	sf::RenderWindow *window;
	sf::Event event;
	sf::Vector2i pixelPos;
	sf::Vector2f worldPos;
	sf::Font* font;

	// Buttons
	Button* m_hit;
	Button* m_stand;
	Button* m_double;
	Button* m_escape_to_menu;
	//Button stand;

	// Deck
	//std::array <Card, 52> deck;

};

