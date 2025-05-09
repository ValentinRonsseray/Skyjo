#pragma once
#include <string>
#include "deck.h"

class Player
{
private:
    inline static unsigned int s_nextId = 0;
    const unsigned int m_id;

    Deck m_deck;
public:
    Player() : m_id(s_nextId++), m_deck() {}

    inline unsigned int get_id() const { return m_id; }

    inline Deck& get_deck() { return m_deck; }
    int get_score() const;

    inline Card* get_card_in_deck(size_t index) const
    {
        return m_deck.get_card_in_deck(index);
    }
    inline bool get_card_visibility(size_t index) const
    {
        return m_deck.get_card_visibility(index);
    }
    inline Card* get_extra_card() const
    {
        return m_deck.get_extra_card();
    }

    inline void set_card_and_visibility_in_deck(size_t index, Card* card, bool is_visible)
    {
        m_deck.set_card_and_visibility_in_deck(index, card, is_visible);
    }
    inline void set_extra_card(Card* card)
    {
        m_deck.set_extra_card(card);
    }

    bool has_every_cards_visible() const;

    /**
     * @brief Returns the index of the column if all its cards are visible and have the same points. Otherwise returns -1.
     */
    int check_for_removable_column() const;
    /**
     * @brief Removes the column at the given index from the deck.
     * @param column_index The index of the column to remove. (0 <= column_index <= 3)
     */
    void remove_column(int column_index);
    /**
     * @brief Discards the extra card.
     * @param discard_pile The discard pile to which the card will be discarded.
     */
    void discard_card(DiscardPile& discard_pile);
    /**
     * @brief Replaces the card at the given index with the extra card.
     * @param discard_pile The discard pile to which the replaced card will be discarded.
     * @param card_index The index of the card to be replaced. (0 <= card_index <= 11)
     */
    void replace_card(DiscardPile& discard_pile, size_t card_index);
    /**
     * @brief Reveals all cards in the deck.
     */
    void reveal_card(size_t deck_index);
    void reveal_all_cards();
    void print_state() const;
    std::string get_tag() const
    {
		return "P" + std::to_string(m_id + 1);
    }
};
