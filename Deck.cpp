#include "Deck.h"
#include <fstream>
#include <ctime>

Deck::Deck()
{
	// Inititalize the deck
	this->init();
	this->m_top_card_index = 0;
	this->shuffle_card_indexes();
}

Deck::~Deck()
{
	// Destroy all the cards;
	for (Card* &iter_card : m_deck)
		delete iter_card;
}

void Deck::init()
{
	// Load the textures from a file
	const std::string file_path{ "card_textures.txt" };
	std::fstream card_textures_file;
	card_textures_file.open(file_path, std::ios::in);

	// Current card index in the loop
	size_t card_index{};
	// Max card dignity
	const size_t max_dignity{ 13 };
	// Max card suit
	const size_t max_suit{ 4 };

	const size_t streamsize_count{ 16 };

	// Loop goes for 52 times and inits each card
	for (size_t suit{}; suit < max_suit; ++ suit)
		for (size_t dignity{}; dignity < max_dignity; ++dignity)
		{
			std::string current_texture;
			std::getline(card_textures_file, current_texture);

			this->m_deck.at(card_index) = new Card{ Card::value_t(dignity), current_texture };
			++card_index;
		}
	
	card_textures_file.close();
}

void Deck::shuffle_card_indexes()
{
	// Init indexes array
	for (size_t iter{}; iter < m_card_indexes.size(); ++iter)
	{
		m_card_indexes.at(iter) = iter;
	}

	srand(time(NULL));

	// Shuffle the indexes
	for (size_t iter{}; iter < m_card_indexes.size(); ++iter)
	{
		int swap_index{ rand() % 52 };
		size_t temp{ m_card_indexes.at(iter) };
		m_card_indexes.at(iter) = m_card_indexes.at(swap_index);
		m_card_indexes.at(swap_index) = temp;
	}
}

const size_t& Deck::pop_top_card()
{ 
	// Remove top card from the deck
	++m_top_card_index;
	return m_card_indexes.at(m_top_card_index - 1);
}

const size_t& Deck::look_at_top_card()
{
	// Get info about top card
	return m_card_indexes.at(m_top_card_index);
}

Card& Deck::at(const size_t& index)
{
	return *m_deck.at(index);
}
