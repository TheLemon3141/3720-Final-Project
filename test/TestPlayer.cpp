#include "gtest/gtest.h"
#include "Player.hpp"
#include "Card.hpp"

TEST(TestPlayer, GetName) {
    Player player("Solomon");
    EXPECT_EQ(player.getName(), "Solomon");
}

TEST(TestPlayer, GetHandEmpty) {
    Player player("Solomon");

    EXPECT_TRUE(player.getHand().getCards().empty());
}

TEST(TestPlayer, GetHandWithCards) {
    Player player("Solomon");

    Card card(RANK::ACE, SUITS::SPADES);

    player.getHand().addCard(&card);

    const auto& cards = player.getHand().getCards();
    ASSERT_EQ(cards.size(), 1);
    EXPECT_EQ(cards[0], &card);
}
