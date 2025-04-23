#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <vector>

#include "Card.hpp"
/**
 * @brief Represents a deck of playing cards.
 * @brief //Serves as the model class.
 */
class Deck {
 public:
  /**
   * @brief Constructer that makes a deck of cards (52 size), then shuffles it
   */
  Deck();
   /**
   * @brief Destructor for the Deck
   */
  ~Deck();
  /**
   * @brief Draws a card from the deck.
   * @return A pointer to the drawn Card.
   */
  Card* drawCard();
  /**
   * @brief Shuffles the deck of cards.
   */
  void shuffle();
  /**
   * @brief Fills the deck with 52 cards.
   * Clears any existing cards then fills
   * with 52 new cards, one for each combination of suit and rank.
   */
  void fillDeck();
  /**
   * @brief Compares this deck with another deck.
   * Considered not equal if two decks do not have same cards
   * @param other The deck that it is compare against.
   * @return 'true' if the deck is not equal, otherwise returns 'false'
   */
  bool operator!=(const Deck& other) const;
   /**
   * @brief Compares this deck with another deck.
   * Considered not equal if two decks do have same cards.
   * @param other The deck that it is compare against.
   * @return 'true' if the deck is equal, otherwise returns 'false'
   */
  bool operator==(const Deck& other) const;
  /**
   * @brief Gets the list of cards in the deck.
   * @return A constant reference to the vector of pointers to Card objects.
   */
  const std::vector<Card*>& getCards() const;

 private:
  std::vector<Card*> cards;
};
#endif  // DECK_HPP_INCLUDED
