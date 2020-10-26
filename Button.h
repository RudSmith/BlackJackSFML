#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Button
{
	enum class ButtonState
	{
		BTN_IDLE = 0,
		BTN_HOVER,
		BTN_ACTIVE,
	};

public:
	Button(float x, float y, float width, float height,
		sf::Font *font, std::string text = 0, sf::Color idleColor = sf::Color::White,
		sf::Color hoverColor = sf::Color::White, sf::Color activeColor = sf::Color::White);
	~Button();

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

	const bool isPressed() const;


private:
	sf::RectangleShape m_shape;
	sf::Font *m_font;
	sf::Text m_text;

	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_activeColor;

	ButtonState m_state;
};

