#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Button
{
	// Current button state
	enum class ButtonState
	{
		BTN_IDLE = 0,
		BTN_HOVER,
		BTN_ACTIVE,
	};

public:
	// Create button with given coords and size
	Button(float x, float y, float width, float height,
		sf::Font *font, std::string text = 0, sf::Color idleColor = sf::Color::White,
		sf::Color hoverColor = sf::Color::White, sf::Color activeColor = sf::Color::White);

	// Update button state
	void update(const sf::Vector2f mousePos);
	// Display the button
	void render(sf::RenderTarget* target);

	// Check if button is currently pressed
	const bool isPressed() const;


private:
	// The shape of the button
	sf::RectangleShape m_shape;
	// Font on the button
	sf::Font *m_font;
	// Text of the button
	sf::Text m_text;
	
	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_activeColor;

	// Current state of the button
	ButtonState m_state;
};

