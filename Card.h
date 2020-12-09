#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class Card
{
public:
	// Card ID in deck
	using value_t = unsigned short;
	// Amount of points that card gives to player
	using points_t = unsigned short;

	// Create a card
	Card(value_t value, const std::string &textureFileName);

	// Get card`s sprite
	const sf::Sprite &sprite() const;
	// Get card`s texture
	const sf::Texture &texture() const;
	// Get card`s value
	const value_t &value() const;
	// Get card`s points
	const points_t &points() const;

	// Methods to initialize a card;
	void loadTexture(const std::string &fileName);
	void setSpriteFromTexture();
	void setValue(const value_t &value);
	void setPosition(const sf::Vector2f& card_pos);

private:
	// Texture
	sf::Texture m_texture;
	// Sprite
	sf::Sprite m_sprite;
	// Id in deck
	value_t m_value;
};
