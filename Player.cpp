#include "Player.h"

Player::Player(const sf::Vector2f card_init_pos, const name_t& name)
	: m_points{},
	  m_bet{},
	  m_name{ name },
	  m_card_init_position{ card_init_pos },
	  m_isWinner{ false },
	  m_isMoving{ false }
{ }

const Player::points_t& Player::Points()
{
	return this->m_points;
}

const Player::money_t& Player::Bet()
{
	return this->m_bet;
}

const Player::hand_t& Player::Hand()
{
	return this->m_hand;
}

const Player::name_t& Player::Name()
{
	return this->m_name;
}

const bool& Player::isWinner()
{
	return this->m_isWinner;
}

const bool& Player::isMoving()
{
	return this->m_isMoving;
}

void Player::makeBet(const money_t& bet)
{
	this->m_bet += bet;
}

void Player::addCard(const size_t& card_index_in_deck)
{
	this->m_hand.push_back(card_index_in_deck);
}

void Player::setMove(const bool& isMoving)
{
	this->m_isMoving = isMoving;
}
