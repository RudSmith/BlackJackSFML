#pragma once

#include <array>
#include "Card.h"

/*
	NOTE: We have 2 arrays, because we cannot swap card textures properly
	So, we have not to shuffle cards, but shuffle their positions in different array
*/

class Deck
{
public:
	// Create deck
	Deck();
	// Destroy deck
	~Deck();

	// Init the deck
	void init();
	// Shuffle the deck
	void shuffle_card_indexes();

	// Remove top card from the deck
	const size_t &pop_top_card();
	// Get info about top card of the deck
	const size_t &look_at_top_card();

	// Get the reference to the card in deck by it`s index
	Card& at(const size_t& index);

private:
	// Array of cards
	std::array<Card*, 52> m_deck;
	// Array of card indexes in deck
	std::array<size_t, 52> m_card_indexes;

	// Current top card
	size_t m_top_card_index;
};

