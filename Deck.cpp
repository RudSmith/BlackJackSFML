#include "Deck.h"
#include <fstream>

////////////////////////////////////////////////////////
#include <iostream>
///////////////////////////////////////////////////////

Deck::Deck()
{
	this->init();
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

	if (card_textures_file.is_open())
		std::cout << "Good\n";

	size_t card_index{};
	const size_t max_dignity{ 13 };
	const size_t max_suit{ 4 };

	const size_t streamsize_count{ 16 };

	for (size_t suit{}; suit < max_suit; ++ suit)
		for (size_t dignity{}; dignity < max_dignity; ++dignity)
		{
			std::string current_texture;
			std::getline(card_textures_file, current_texture);
			std::cout << current_texture << std::endl;

			this->m_deck.at(card_index) = new Card{ Card::value_t(dignity), current_texture };
			++card_index;
		}
	
	card_textures_file.close();
}

void Deck::shuffle()
{
}
