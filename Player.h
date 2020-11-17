#pragma once

#include "Card.h"
#include <vector>
#include <string>

class Player
{
	// ----------- Aliases ----------- //
	using points_t = unsigned short;
	using money_t = unsigned int;
	using hand_t = std::vector<size_t>;
	using name_t = std::string;

public:
	// ----------- Constructors and destructors ----------- //
	Player(const sf::Vector2f card_init_pos, const name_t &name = "User");

	// ----------- Getters ----------- //
	const points_t &Points();
	const hand_t &Hand();
	const name_t &Name();
	const bool &isMoving();
	const sf::Vector2f card_init_pos();
	const size_t &aces_count();

	// ----------- Setters ----------- //
	void addCard(const size_t &card_index_in_deck);
	void setMove(const bool &isMoving);
	void setPoints(const points_t &points);
	void setAcesCount(const size_t &aces_count);
	
private:
	points_t m_points;
	hand_t m_hand;
	name_t m_name;

	size_t m_aces_count;

	sf::Vector2f m_card_init_position;

	bool m_isMoving;

};

