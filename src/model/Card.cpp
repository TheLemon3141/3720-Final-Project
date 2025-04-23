#include "../../include/model/Card.hpp"

Card::Card(RANK rank, SUITS suit) : rank(rank), suit(suit) {}

Card::~Card() {}

RANK Card::getRank() const { return rank; }

SUITS Card::getSuit() const { return suit; }

bool Card::operator==(const Card& other) const {
    return this->rank == other.rank && this->suit == other.suit;
}

bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}
int Card::getNumericalValue() const {
    switch (rank) {
        case RANK::JACK:
        case RANK::QUEEN:
        case RANK::KING:
            return 10;
        case RANK::ACE:
            return 11;
        default:
            return static_cast<int>(rank) + 2;
    }
}
