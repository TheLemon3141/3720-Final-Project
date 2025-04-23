#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "gtest/gtest.h"

TEST(TestDeck, drawCard) {
    Deck deck;
    Card* card = deck.drawCard();

    EXPECT_NE(card, nullptr);
    delete card;
}

TEST(TestDeck, ShuffleDeck) {
    Deck firstDeck;
    firstDeck.shuffle();
    Deck secondDeck;
    EXPECT_NE(firstDeck, secondDeck);
}
