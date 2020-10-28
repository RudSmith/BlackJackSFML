#pragma once

#include <array>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

	void init();
	void shuffle();

	const Card &top_card();

private:
	std::array<Card*, 52> m_deck;

	size_t m_top_card_index;
};

