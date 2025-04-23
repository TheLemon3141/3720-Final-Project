#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Player.hpp"
#include "View.hpp"

int main() {
    UI* ui = new UI();
    Game* game = new Game(ui);

    Player* player1 = new Player("Player 1");
    Player* player2 = new Player("Dealer");

    game->addPlayer(player1);
    game->addPlayer(player2);
    srand(time(NULL));

    game->start();

    delete game;
    delete ui;

    return 0;
}
