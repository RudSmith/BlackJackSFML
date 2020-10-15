#pragma once
#include "Game.h"

class Card
{
public:
	void loadTexture(const std::string fileName);
	void setSpriteFromTexture();


private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	unsigned short m_value;
};
