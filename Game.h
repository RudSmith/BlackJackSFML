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
	void updateEvents();
	void update();
	void render();
	void run();

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
	Button* hit;
	//Button stand;

	// Deck
	//std::array <Card, 52> deck;

};

