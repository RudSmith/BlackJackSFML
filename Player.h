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
	const money_t &Bet();
	const hand_t &Hand();
	const name_t &Name();
	const bool &isWinner();
	const bool &isMoving();
	const sf::Vector2f card_init_pos();

	// ----------- Setters ----------- //
	void makeBet(const money_t &bet);
	void addCard(const size_t &card_index_in_deck);
	void setMove(const bool &isMoving);
	void setPoints(const points_t &points);
	
private:
	points_t m_points;
	money_t m_bet;
	hand_t m_hand;
	name_t m_name;

	sf::Vector2f m_card_init_position;

	bool m_isWinner;
	bool m_isMoving;

};

