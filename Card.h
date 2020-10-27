#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class Card
{
	using value_t = unsigned short;

public:
	Card(value_t value = 0, const std::string &textureFileName = "");

	sf::Sprite sprite();
	sf::Texture texture();
	value_t value();

	void loadTexture(const std::string &fileName);
	void setSpriteFromTexture();
	void setValue(const value_t &value);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	value_t m_value;
};
