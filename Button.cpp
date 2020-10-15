#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text,
				sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->m_shape.setPosition(sf::Vector2f(x, y));
	this->m_shape.setSize(sf::Vector2f(width, height));

	this->m_font = font;
	this->m_text.setFont(*this->m_font);
	this->m_text.setString(text);
	this->m_text.setFillColor(sf::Color::White);
	this->m_text.setCharacterSize(12);
	this->m_text.setPosition(
		this->m_shape.getPosition().x + (this->m_shape.getPosition().x / 2.f) - this->m_text.getGlobalBounds().width / 2.f,
		this->m_shape.getPosition().y + (this->m_shape.getPosition().y / 2.f) - this->m_text.getGlobalBounds().height / 2.f
	);

	this->m_idleColor = idleColor;
	this->m_hoverColor = hoverColor;
	this->m_activeColor = activeColor;

	this->m_shape.setFillColor(this->m_idleColor);

	this->m_state = ButtonState::BTN_IDLE;
}

Button::~Button()
{
}

void Button::update(const sf::Vector2f mousePos)
{
	this->m_state = ButtonState::BTN_IDLE;

	if (this->m_shape.getGlobalBounds().contains(mousePos))
	{
		this->m_state = ButtonState::BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->m_state = ButtonState::BTN_ACTIVE;
		}
	}

	switch (this->m_state)
	{
	case ButtonState::BTN_IDLE:
		this->m_shape.setFillColor(m_idleColor);
		break;

	case ButtonState::BTN_HOVER:
		this->m_shape.setFillColor(m_hoverColor);
		break;

	case ButtonState::BTN_ACTIVE:
		this->m_shape.setFillColor(m_activeColor);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->m_shape);
	target->draw(this->m_text);
}

const bool Button::isPressed() const
{
	if (this->m_state == ButtonState::BTN_ACTIVE)
		return true;
	else
		return false;
}
