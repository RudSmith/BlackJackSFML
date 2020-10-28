#pragma once

#include "Card.h"
#include <vector>
#include <string>

class Player
{
	// ----------- Aliases ----------- //
	using points_t = unsigned short;
	using money_t = unsigned int;
	using deck_t = std::vector<Card*>;
	using name_t = std::string;

public:
	// ----------- Constructors and destructors ----------- //
	Player(const name_t &name = "User");
	~Player();

	// ----------- Getters ----------- //
	const points_t &Points();
	const money_t &Bet();
	const deck_t &Deck();
	const name_t &Name();
	const bool &isWinner();
	const bool &isMoving();

	// ----------- Setters ----------- //
	void makeBet(const money_t &bet);
	void addCard(Card &card);
	void setMove(const bool &isMoving);
	
private:
	points_t m_points;
	money_t m_bet;
	deck_t m_deck;
	name_t m_name;

	bool m_isWinner;
	bool m_isMoving;

};

