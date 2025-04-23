#include "gtest/gtest.h"

#include "Game.hpp"
#include "View.hpp"
#include "Player.hpp"

TEST(game, getWinners) {
    // UI* uiPointer = new UI;
    // Game myGame(uiPointer);
    // Player* player1 = new Player("Shrek");
    // myGame.addPlayer(Player);
    // Player* player2 = new Player("Donkey");
    // myGame.addPlayer(Player);
    // //Give them some cards

    // std::vector<Player*> winners;
    // winners = myGame.getWinners();
    // std::vector<Player*>::iterator it;
    // for (int i=0; i < winners.size(); i++) {cd
    //     //call ui's showWinners function
    //     std::cout << i << std::endl;
    // }
}

//Test bust

//Test stand

//Test ace

//Game with 1 player and dealer

//Game with 2 players and dealer
TEST(game, twoHumanPlayers) {
    /*

    //MockUI myUI;
    //UI* uiPointer = (&myUI);
    MockDeck myDeck;
    Deck* deckPointer = (&myDeck);

    Game myGame(uiPointer, deckPointer);
    Player* player1 = new Player("Shrek");
    myGame.addPlayer(Player);
    Player* player2 = new Player("Donkey");
    myGame.addPlayer(Player);
    //dealer?

    //Create some hands to give the players

    EXPECT_CALL(myDeck, shuffle())   //Part of dealCards
    .Times(1);

    EXPECT_CALL(player1, getHand())   //Part of dealCards
    .Times(2)
    .WillOnce(testing::Return(hand we want to give them));

    EXPECT_CALL(player2, getHand())   //Part of dealCards
    .Times(2)
    .WillOnce(testing::Return(/*hand we want to give them));

    //...

    myGame.start();
    */
}

//Game where 2 players win
