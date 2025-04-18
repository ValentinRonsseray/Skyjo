#pragma once
#include <array>
#include "card.h"
#include "constants.h"
#include <stdexcept>

struct CardInDeck
{
	Card* card;
	bool is_visible;

	CardInDeck(Card* c = nullptr, bool visible = false) : card(c), is_visible(visible) {}
};

class Deck
{
public:
	Deck() : m_deck_cards({}), m_extra_card(nullptr) {};

	int get_score() const;
	Card* get_extra_card() const { return m_extra_card; }

	void set_card_in_deck(size_t index, Card* card, bool is_visible) {
		if (index < m_deck_cards.size()) {
			m_deck_cards[index] = CardInDeck(card, is_visible);
		}
		else {
			throw std::out_of_range("Index out of range");
		}
	}
	void set_extra_card(Card* card)
	{
		m_extra_card = card;
	}

	class Iterator
	{
	private:
		CardInDeck* m_ptr;
	public:
		explicit Iterator(CardInDeck* ptr) : m_ptr(ptr) {}

		CardInDeck& operator*() const { return *m_ptr; }

		Iterator& operator++() {
			++m_ptr;
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return m_ptr != other.m_ptr;
		}
	};

	class ConstIterator
	{
	private:
		const CardInDeck* m_ptr;
	public:
		explicit ConstIterator(const CardInDeck* ptr) : m_ptr(ptr) {}

		const CardInDeck& operator*() const { return *m_ptr; }
		ConstIterator& operator++() { ++m_ptr; return *this; }
		bool operator!=(const ConstIterator& other) const { return m_ptr != other.m_ptr; }
	};

	Iterator begin() { return Iterator(m_deck_cards.data()); }
	Iterator end() { return Iterator(m_deck_cards.data() + m_deck_cards.size()); }
	ConstIterator begin() const { return ConstIterator(m_deck_cards.data()); }
	ConstIterator end() const { return ConstIterator(m_deck_cards.data() + m_deck_cards.size()); }
	ConstIterator cbegin() const { return ConstIterator(m_deck_cards.data()); }
	ConstIterator cend() const { return ConstIterator(m_deck_cards.data() + m_deck_cards.size()); }
private:
	std::array<CardInDeck, Constants::Deck::N_ROW* Constants::Deck::N_COL> m_deck_cards;
	Card* m_extra_card;
};

