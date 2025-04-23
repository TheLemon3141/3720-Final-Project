#include "Card.hpp"
#include "gtest/gtest.h"

TEST(TestCard, GetRank) {
  Card card(RANK::ACE, SUITS::HEARTS);
  EXPECT_EQ(card.getRank(), RANK::ACE);
}

TEST(TestCard, GetSuit) {
  Card card(RANK::ACE, SUITS::HEARTS);
  EXPECT_EQ(card.getSuit(), SUITS::HEARTS);
}

TEST(TestCard, GetNumericalValueFaceCards) {
  Card jackCard(RANK::JACK, SUITS::HEARTS);
  Card queenCard(RANK::QUEEN, SUITS::DIAMONDS);
  Card kingCard(RANK::KING, SUITS::CLUBS);

  EXPECT_EQ(jackCard.getNumericalValue(), 10);
  EXPECT_EQ(queenCard.getNumericalValue(), 10);
  EXPECT_EQ(kingCard.getNumericalValue(), 10);
}

TEST(TestCard, GetNumericalValueFaceAce) {
  Card aceCard(RANK::ACE, SUITS::HEARTS);
  EXPECT_EQ(aceCard.getNumericalValue(), 11);
}

TEST(TestCard, GetNumericalValueBasicCards) {
  Card twoCard(RANK::TWO, SUITS::HEARTS);
  Card eightCard(RANK::EIGHT, SUITS::HEARTS);
  EXPECT_EQ(twoCard.getNumericalValue(), 2);
  EXPECT_EQ(eightCard.getNumericalValue(), 8);
}
