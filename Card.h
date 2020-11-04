#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class Card
{
public:
	using value_t = unsigned short;
	using points_t = unsigned short;

	Card(value_t value, const std::string &textureFileName);

	const sf::Sprite &sprite() const;
	const sf::Texture &texture() const;
	const value_t &value() const;
	const points_t &points() const;

	void loadTexture(const std::string &fileName);
	void setSpriteFromTexture();
	void setValue(const value_t &value);
	void setPosition(const sf::Vector2f& card_pos);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	value_t m_value;
};
