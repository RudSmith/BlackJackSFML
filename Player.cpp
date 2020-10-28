#include "Player.h"

Player::Player(const name_t& name)
	: m_points{},
	  m_bet{},
	  m_name{ name },
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

const Player::deck_t& Player::Deck()
{
	return this->m_deck;
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

void Player::addCard(Card& card)
{
	this->m_deck.push_back(&card);
}

void Player::setMove(const bool& isMoving)
{
	this->m_isMoving = isMoving;
}
