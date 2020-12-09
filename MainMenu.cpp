#include "MainMenu.h"

void MainMenu::initWindow()
{
	// Create window
	m_mainWindow = new sf::RenderWindow(sf::VideoMode(1100, 650), "BlackJack", sf::Style::Titlebar | sf::Style::Close);
	// Create and load font
	m_font = new sf::Font;
	m_font->loadFromFile("Fonts/arial.ttf");
}

void MainMenu::initBackground()
{
	// Set backgound image
	m_backgroundTexture = new sf::Texture;
	m_backgroundTexture->loadFromFile("Images/Background.jpg");
	m_backgroundSprite = new sf::Sprite;
	m_backgroundSprite->setTexture(*m_backgroundTexture);
	m_backgroundSprite->setScale(1.757, 1.78);
}

void MainMenu::initButtons()
{
	// Create buttons and initialize them
	m_playBtn = new Button(430, 150, 200, 100, m_font, "Play", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	m_helpBtn = new Button(430, 300, 200, 100, m_font, "Help", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
	m_exitBtn = new Button(430, 450, 200, 100, m_font, "Exit", sf::Color(200, 200, 200), sf::Color(150, 150, 150), sf::Color(125, 125, 125));
}

MainMenu::MainMenu()
{
	// Create and initialize all resources
	initWindow();
	initBackground();
	initButtons();
}

MainMenu::~MainMenu()
{
	// Delete all allocated memory
	delete m_mainWindow;
	delete m_font;
	delete m_backgroundTexture;
	delete m_backgroundSprite;
	delete m_playBtn;
	delete m_helpBtn;
	delete m_exitBtn;
}

void MainMenu::run()
{
	// Main loop of the program
	while (m_mainWindow->isOpen())
	{
		update();
		render();
	}
}


void MainMenu::startGame()
{
	// Start the game and close the menu
	m_mainWindow->close();
	m_game = new Game();
	m_game->run();

	// Wait while game is running
	while (m_game->isRunning());

	// Recreate main menu window
	m_mainWindow->create(sf::VideoMode(1100, 650), "BlackJack", sf::Style::Titlebar | sf::Style::Close);

	// Delete the game
	delete m_game;
}

void MainMenu::showHelpWindow()
{
	// Open readme.txt
	system("start readme.txt");
}

void MainMenu::exit()
{
	// Close main menu
	m_mainWindow->close();
}

void MainMenu::updateEvents()
{
	// Update mouse clicks in loop
	while (m_mainWindow->pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_mainWindow->close();
		else if (m_event.type == sf::Event::MouseButtonPressed && m_event.mouseButton.button == sf::Mouse::Left)
		{
			if (m_playBtn->isPressed())
				startGame();
			else if (m_helpBtn->isPressed())
				showHelpWindow();
			else if (m_exitBtn->isPressed())
				exit();
		}
	}
}

void MainMenu::updateMousePosition()
{
	// Calculate mouse position in pixel and translate it to coords
	m_pixelPos = sf::Mouse::getPosition(*m_mainWindow);
	m_worldPos = m_mainWindow->mapPixelToCoords(m_pixelPos);
}

void MainMenu::updateButtons()
{
	// Update buttons using current mouse position
	m_playBtn->update(m_worldPos);
	m_helpBtn->update(m_worldPos);
	m_exitBtn->update(m_worldPos);
}

void MainMenu::update()
{
	// Update all elements
	updateMousePosition();
	updateButtons();
	updateEvents();
}

void MainMenu::render()
{
	// Clear the window
	m_mainWindow->clear();

	// Draw background texture
	m_mainWindow->draw(*m_backgroundSprite);

	// Draw buttons
	m_playBtn->render(m_mainWindow);
	m_helpBtn->render(m_mainWindow);
	m_exitBtn->render(m_mainWindow);

	// Display the window
	m_mainWindow->display();
}

