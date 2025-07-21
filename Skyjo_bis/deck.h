#pragma once
#include <array>
#include "card.h"
#include "constants.h"
#include "discard_pile.h"
#include <stdexcept>

struct CardAndVisibility
{
	Card* card;
	bool is_visible;

	CardAndVisibility(Card* c = nullptr, bool visible = false) : card(c), is_visible(visible) {}
};

class Deck
{
public:
	Deck() : m_deck_cards({}), m_extra_card(nullptr) {};

	int get_score() const;
	inline Card* get_card_in_deck(size_t index) const { return m_deck_cards[index].card; }
	inline bool get_card_visibility(size_t index) const { return m_deck_cards[index].is_visible; }
	Card* get_extra_card() const { return m_extra_card; }
	inline size_t get_size() const { return m_deck_cards.size(); }
	std::vector<int> get_non_removed_columns() const;
	std::vector<size_t> get_replacable_card_indices() const;
	std::vector<size_t> get_hidden_card_indices() const;

	void set_card_and_visibility_in_deck(size_t index, Card* card, bool is_visible) {
		if (index < get_size()) {
			m_deck_cards[index] = CardAndVisibility(card, is_visible);
		}
		else {
			throw std::out_of_range("Index out of range");
		}
	}
	inline void set_extra_card(Card* card)
	{
		m_extra_card = card;
	}

	bool has_every_cards_visible() const;

	void discard_card(DiscardPile& discard_pile);
	void replace_card(DiscardPile& discard_pile, size_t card_index);

	class Iterator
	{
	private:
		CardAndVisibility* m_ptr;
	public:
		explicit Iterator(CardAndVisibility* ptr) : m_ptr(ptr) {}

		CardAndVisibility& operator*() const { return *m_ptr; }

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
		const CardAndVisibility* m_ptr;
	public:
		explicit ConstIterator(const CardAndVisibility* ptr) : m_ptr(ptr) {}

		const CardAndVisibility& operator*() const { return *m_ptr; }
		ConstIterator& operator++() { ++m_ptr; return *this; }
		bool operator!=(const ConstIterator& other) const { return m_ptr != other.m_ptr; }
	};

	Iterator begin() { return Iterator(m_deck_cards.data()); }
	Iterator end() { return Iterator(m_deck_cards.data() + get_size()); }
	ConstIterator begin() const { return ConstIterator(m_deck_cards.data()); }
	ConstIterator end() const { return ConstIterator(m_deck_cards.data() + get_size()); }
	ConstIterator cbegin() const { return ConstIterator(m_deck_cards.data()); }
	ConstIterator cend() const { return ConstIterator(m_deck_cards.data() + get_size()); }
private:
	std::array<CardAndVisibility, Constants::Deck::N_ROW* Constants::Deck::N_COL> m_deck_cards;
	Card* m_extra_card;
};

