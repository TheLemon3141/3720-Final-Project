#include "../../include/model/Deck.hpp"

#include <algorithm>
#include <random>
#include <vector>

Deck::Deck() {
  cards.reserve(52);
  fillDeck();
  shuffle();
}

Deck::~Deck() {
  for (Card* card : cards) {
    delete card;
  }
  cards.clear();
}

void Deck::fillDeck() {
    cards.clear();
    for (int suits = 0; suits <= 3; suits++) {
      for (int ranks = 0; ranks <= 12; ranks++) {
          cards.push_back(new Card(static_cast<RANK>(ranks),
          static_cast<SUITS>(suits)));
        }
    }
}

Card* Deck::drawCard() {
  Card* card = cards.back();
  cards.pop_back();
  return card;
}

void Deck::shuffle() { random_shuffle(cards.begin(), cards.end()); }

bool Deck::operator==(const Deck& other) const {
  if (this->cards.size() != other.cards.size()) {
      return false;
  }

  for (size_t i = 0; i < this->cards.size(); ++i) {
      if (*this->cards[i] != *other.cards[i]) {
          return false;
      }
  }

  return true;
}

bool Deck::operator!=(const Deck& other) const {
  return !(*this == other);
}
