#include "Deck.h"
#include <fstream>
#include <ctime>

Deck::Deck()
{
	this->init();
	this->m_top_card_index = 0;
	this->shuffle();
}

Deck::~Deck()
{
	for (Card* &iter_card : m_deck)
		delete iter_card;
}

void Deck::init()
{
	const std::string file_path{ "card_textures.txt" };
	std::fstream card_textures_file;
	card_textures_file.open(file_path, std::ios::in);

	size_t card_index{};
	const size_t max_dignity{ 13 };
	const size_t max_suit{ 4 };

	const size_t streamsize_count{ 16 };

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

void Deck::shuffle()
{
	srand(time(NULL));

	for (size_t card_ind{}; card_ind < m_deck.size(); ++card_ind)
	{
		int card_swap_index{ rand() % 52 };

		Card* temp = this->m_deck.at(card_ind);
		this->m_deck.at(card_ind) = this->m_deck.at(card_swap_index);
		this->m_deck.at(card_swap_index) = temp;
	}
}

const Card& Deck::top_card()
{ 
	++this->m_top_card_index;
	return *this->m_deck.at(this->m_top_card_index - 1);
}
