#include "Card.h"


Card::Card(value_t value, const std::string& textureFileName)
	: m_value { value }
{
	this->m_texture.loadFromFile(textureFileName);
	this->m_sprite.setTexture(this->m_texture);

	this->m_sprite.setScale(0.25f, 0.2f);
}

const sf::Sprite &Card::sprite() const
{
	return this->m_sprite;
}

const sf::Texture &Card::texture() const 
{
	return this->m_texture;
}

const Card::value_t &Card::value() const
{
	return this->m_value;
}


void Card::loadTexture(const std::string& fileName)
{
	this->m_texture.loadFromFile(fileName);
}

void Card::setSpriteFromTexture()
{
	this->m_sprite.setTexture(this->m_texture);
}

void Card::setValue(const value_t& value)
{
	this->m_value = value;
}

void Card::setPosition(const sf::Vector2f& card_pos)
{
	this->m_sprite.setPosition(card_pos);
}

