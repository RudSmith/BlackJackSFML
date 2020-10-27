#include "Card.h"


Card::Card(value_t value, const std::string& textureFileName)
	: m_value { value }
{
	this->m_texture.loadFromFile(textureFileName);
	this->m_sprite.setTexture(this->m_texture);
}

sf::Sprite Card::sprite()
{
	return this->m_sprite;
}

sf::Texture Card::texture()
{
	return this->m_texture;
}

Card::value_t Card::value()
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
