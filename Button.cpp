#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text,
				sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	// Set the position and the size 
	m_shape.setPosition(sf::Vector2f(x, y));
	m_shape.setSize(sf::Vector2f(width, height));

	// Initialize the font
	m_font = font;
	m_text.setFont(*m_font);
	m_text.setString(text);
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(20);
	m_text.setPosition(
		m_shape.getPosition().x + (m_shape.getGlobalBounds().width / 2.f) - m_text.getGlobalBounds().width / 2.f,
		m_shape.getPosition().y + (m_shape.getGlobalBounds().height / 2.f) - m_text.getGlobalBounds().height / 2.f);

	// Set colours
	m_idleColor = idleColor;
	m_hoverColor = hoverColor;
	m_activeColor = activeColor;
	m_shape.setFillColor(this->m_idleColor);

	// Set default state
	m_state = ButtonState::BTN_IDLE;
}

// Update current button state
void Button::update(const sf::Vector2f mousePos)
{
	m_state = ButtonState::BTN_IDLE;

	if (m_shape.getGlobalBounds().contains(mousePos))
	{
		m_state = ButtonState::BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_state = ButtonState::BTN_ACTIVE;
		}
	}

	switch (m_state)
	{
	case ButtonState::BTN_IDLE:
		m_shape.setFillColor(m_idleColor);
		break;

	case ButtonState::BTN_HOVER:
		m_shape.setFillColor(m_hoverColor);
		break;

	case ButtonState::BTN_ACTIVE:
		m_shape.setFillColor(m_activeColor);
		break;
	}
}

// Render button to the target
void Button::render(sf::RenderTarget* target)
{
	target->draw(m_shape);
	target->draw(m_text);
}

void Button::disable()
{
	m_shape.setSize(sf::Vector2f(0.f, 0.f));
}

const bool Button::isPressed() const
{
	if (m_state == ButtonState::BTN_ACTIVE)
		return true;

	return false;
}
