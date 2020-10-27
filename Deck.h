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

private:
	std::array<Card*, 52> m_deck;
};

