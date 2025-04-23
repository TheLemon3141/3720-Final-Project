#include "../../include/model/Hand.hpp"

void Hand::addCard(Card* card) { cards.push_back(card); }

int Hand::getTotal() const {
    int total = 0;
    int aces = 0;
    for (const Card* card : cards) {
        total += card->getNumericalValue();
        if (card->getRank() == RANK::ACE) aces++;
    }
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }
    return total;
}

void Hand::clear() { cards.clear(); }

const std::vector<Card*>& Hand::getCards() const { return cards; }
