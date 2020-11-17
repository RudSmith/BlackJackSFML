#include "Player.h"

Player::Player(const sf::Vector2f card_init_pos, const name_t& name)
	: m_points{},
	  m_name{ name },
	  m_card_init_position{ card_init_pos },
	  m_isWinner{ false },
	  m_isMoving{ false },
	  m_aces_count{}
{ }

const Player::points_t& Player::Points()
{
	return this->m_points;
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

const sf::Vector2f Player::card_init_pos()
{
	return this->m_card_init_position;
}

const size_t& Player::aces_count()
{
	return m_aces_count;
}

void Player::addCard(const size_t& card_index_in_deck)
{
	this->m_hand.push_back(card_index_in_deck);
}

void Player::setMove(const bool& isMoving)
{
	this->m_isMoving = isMoving;
}

void Player::setPoints(const points_t& points)
{
	this->m_points = points;
}

void Player::setAcesCount(const size_t& aces_count)
{
	m_aces_count = aces_count;
}
