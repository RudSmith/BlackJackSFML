#include "Card.h"

void Card::loadTexture(const std::string fileName)
{
	this->m_texture.loadFromFile(fileName);
	this->m_texture.setSmooth(true);
}

void Card::setSpriteFromTexture()
{
	this->m_sprite.setTexture(this->m_texture);
}
