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

const Card::points_t& Card::points() const
{
	switch (this->m_value)
	{
	case 0:
		return 2;
		break;
	case 1:
		return 3;
		break;
	case 2:
		return 4;
		break;
	case 3:
		return 5;
		break;
	case 4:
		return 6;
		break;
	case 5:
		return 7;
		break;
	case 6:
		return 8;
		break;
	case 7:
		return 9;
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		return 10;
		break;
	case 12:
		return 11;

	}
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

