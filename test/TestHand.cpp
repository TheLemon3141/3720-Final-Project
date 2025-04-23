#include "gtest/gtest.h"
#include "Hand.hpp"
#include "Card.hpp"


class TestHand : public ::testing::Test {
 protected:
    void SetUp() override {
        createCards();
    }

    void TearDown() override {
        deleteCards();
    }
    void createCards() {
        cardAce = new Card(RANK::ACE, SUITS::HEARTS);
        cardKing = new Card(RANK::KING, SUITS::SPADES);
        cardFive = new Card(RANK::FIVE, SUITS::DIAMONDS);
    }

    void deleteCards() {
        delete cardAce;
        delete cardKing;
        delete cardFive;
    }

    Card* cardAce;
    Card* cardKing;
    Card* cardFive;
};

TEST_F(TestHand, AddCard) {
    Hand hand;
    hand.addCard(cardAce);
    hand.addCard(cardKing);

    const std::vector<Card*>& cards = hand.getCards();
    ASSERT_EQ(cards.size(), 2);
    EXPECT_EQ(cards[0], cardAce);
    EXPECT_EQ(cards[1], cardKing);
}


TEST_F(TestHand, GetTotal) {
    Hand hand;

    EXPECT_EQ(hand.getTotal(), 0);

    hand.addCard(cardKing);
    hand.addCard(cardFive);
    EXPECT_EQ(hand.getTotal(), 15);

    hand.addCard(cardAce);
    EXPECT_EQ(hand.getTotal(), 16);

    hand.addCard(cardAce);
    EXPECT_EQ(hand.getTotal(), 17);
}

TEST_F(TestHand, Clear) {
    Hand hand;
    hand.addCard(cardAce);
    hand.addCard(cardKing);

    hand.clear();
    EXPECT_TRUE(hand.getCards().empty());
    EXPECT_EQ(hand.getTotal(), 0);
}

TEST_F(TestHand, GetCards) {
    Hand hand;
    hand.addCard(cardAce);
    hand.addCard(cardKing);

    const std::vector<Card*>& cards = hand.getCards();
    ASSERT_EQ(cards.size(), 2);
    EXPECT_EQ(cards[0], cardAce);
    EXPECT_EQ(cards[1], cardKing);
}
