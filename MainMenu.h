#pragma once
#include "Game.h"
#include "Button.h"

class MainMenu
{
public:
	// Init window and buttons
	MainMenu();
	// Delete allocated memory
	~MainMenu();

	// Create main menu window
	void run();

private:
	// Create and init window
	void initWindow();
	// Create and init background
	void initBackground();
	// Create and init buttons
	void initButtons();

	// Start the game
	void startGame();
	// Show the window with all info about the game
	void showHelpWindow();
	// Exit the game
	void exit();

	// Update SFML events
	void updateEvents();
	// Update main menu states of objects
	void update();
	// Render main menu objects
	void render();
	// Update current mouse position
	void updateMousePosition();
	// Update the state of the buttons
	void updateButtons();

	// Game that will start when user cliks the "Play" button
	Game* m_game;

	// Mouse position in pixels 
	sf::Vector2i m_pixelPos;
	// Mouse position in coords
	sf::Vector2f m_worldPos;

	// Button to start the game
	Button* m_playBtn;
	// Button to show info about the game
	Button* m_helpBtn;
	// Button to exit the application
	Button* m_exitBtn;

	// The main window of the menu
	sf::RenderWindow* m_mainWindow;

	// Background texture
	sf::Texture* m_backgroundTexture;
	// Background sprite
	sf::Sprite* m_backgroundSprite;

	// Main font
	sf::Font* m_font;

	// Current event
	sf::Event m_event;

	// Do we currently need to close menu or not
	bool isRunning;
};

