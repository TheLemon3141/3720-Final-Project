#include "gtest/gtest.h"

#include "View.hpp"
/*
TEST(UI, showHand) {
    UI* ui = new UI();
    Hand* hand = new Hand();

    hand->addCard(new Card(RANK::ACE, SUITS::SPADES));

    std::string singleCard =
    "-----\n"
    "|A S|\n"
    "-----\n";

    std::string result = ui->showHand(hand);

    EXPECT_EQ(singleCard, result);

    hand->addCard(new Card(RANK::KING, SUITS::HEARTS));
    hand->addCard(new Card(RANK::TEN, SUITS::DIAMONDS));
    hand->addCard(new Card(RANK::THREE, SUITS::CLUBS));

    std::string fourCard =
    "-----\n"
    "|A S|\n"
    "-----\n"
    "|K H|\n"
    "-----\n"
    "|10 D|\n"
    "-----\n"
    "|3 C|\n"
    "-----\n";

    result = ui->showHand(hand);

    EXPECT_EQ(fourCard, result);

    for (auto card : hand->getCards())
        delete card;
    delete hand;
    delete ui;
}
*/
TEST(UI, showWinners) {
    UI* ui = new UI();

    std::vector<Player*> players = {
        new Player("Derek"),
        new Player("Susan")
    };

    std::string expected =
        "Derek wins!\n"
        "Susan wins!\n";

    std::string result = ui->showWinners(players);

    EXPECT_EQ(expected, result);

    delete ui;

    for (auto player : players)
        delete player;
}

TEST(UI, showDealt) {
    UI* ui = new UI();

    Card* card_1 = new Card(RANK::FOUR, SUITS::DIAMONDS);

    std::string expected = "You were dealt the 4 of Diamonds.\n";

    std::string result = ui->showDealt(card_1);

    EXPECT_EQ(expected, result);

    Card* card_2 = new Card(RANK::QUEEN, SUITS::CLUBS);

    expected = "You were dealt the Queen of Clubs.\n";

    result = ui->showDealt(card_2);

    EXPECT_EQ(expected, result);

    delete ui;
    delete card_1;
    delete card_2;
}

TEST(UI, showTurn) {
    UI* ui = new UI();

    Player* player = new Player("Hubert");

    std::string expected = "Hubert's turn.\n";

    std::string result = ui->showTurn(player);

    EXPECT_EQ(expected, result);

    delete ui;
    delete player;
}
