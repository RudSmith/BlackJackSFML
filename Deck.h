#pragma once

#include <array>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

	void init();
	void shuffle_card_indexes();

	const size_t &top_card();

	const Card& at(const size_t& index);

private:
	std::array<Card*, 52> m_deck;
	std::array<size_t, 52> m_card_indexes;

	size_t m_top_card_index;
};

