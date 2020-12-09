#pragma once

#include "Card.h"
#include <vector>
#include <string>

/*
	NOTE: player helds card indexes, but not the cards
	Reason is that it is more efficient to process
*/

class Player
{
	// Player`s points
	using points_t = unsigned short;
	// Player`s hand
	using hand_t = std::vector<size_t>;
	// Player`s name 
	using name_t = std::string;

public:
	// Create a player
	Player(const sf::Vector2f card_init_pos, const name_t &name = "User");

	// Get player`s points
	const points_t &Points();
	// Get player`s hand
	const hand_t &Hand();
	// Get player`s name
	const name_t &Name();
	// Check if player is moving now
	const bool &isMoving();
	// Get initial cards position of the player
	const sf::Vector2f card_init_pos();
	// Get player`s aces quantity in his hand
	const size_t &aces_count();

	// Add card to player`s hand
	void addCard(const size_t &card_index_in_deck);
	// Pass the move to the player
	void setMove(const bool &isMoving);
	// Set player`s points
	void setPoints(const points_t &points);
	// Set player`s aces quantity
	void setAcesCount(const size_t &aces_count);
	
private:
	// Player`s points
	points_t m_points;
	// Player`s cards in hand
	hand_t m_hand;
	// Player`s name
	name_t m_name;

	// Player`s aces quantity
	size_t m_aces_count;

	// Position on the window where player`s cards are displaying
	sf::Vector2f m_card_init_position;
	
	// Checks if it is player`s move now
	bool m_isMoving;

};

