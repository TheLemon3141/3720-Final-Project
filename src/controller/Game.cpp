#include <iostream>
#include <string>
#include <vector>
#include "../../include/controller/Game.hpp"
#include "../../include/model/Player.hpp"
#include "../../include/view/View.hpp"

Game::Game(UI* _ui) : _ui(_ui) {
    _deck = new Deck();
}

//Destructor
Game::~Game() {
    delete _deck;

    for (Player* player : _players) {
        delete player;
    }
}

void Game::addPlayer(Player* player) {
    _players.push_back(player);
}

void Game::start() {
    _deck->shuffle();

    this->init();

    for (Player* player : _players) {
        player->getHand().clear();
        player->getHand().addCard(_deck->drawCard());
        _ui->showDealt(player->getHand().getCards().back());
        player->getHand().addCard(_deck->drawCard());
        _ui->showDealt(player->getHand().getCards().back());
        _ui->showHand(&player->getHand(), player->getName());
    }

    for (Player* player : _players) {
        _ui->showTurn(player);

        while (true) {
            _ui->showHand(&player->getHand(), player->getName());
            _ui->showActions();

            std::string input;

            if (player->getName() == "Dealer") {
                input = this->dealerDecision(&player->getHand());
            } else {
                std::cin >> input;
            }

            if (input == "hit") {
                player->getHand().addCard(_deck->drawCard());
                _ui->showDealt(player->getHand().getCards().back());
                _ui->showHand(&player->getHand(), player->getName());
                if (player->getHand().getTotal() > 21) {
                    _ui->showDefeat();
                    break;
                }
            } else if (input == "stand") {
                break;
            } else {
                _ui->errorMessage();
            }
        }
    }
    std::vector<Player*> winners = getWinners();
    _ui->showWinners(winners);
}

void Game::init() {
    if (_deck = nullptr) {
        _deck = new Deck();
    } else {
        delete _deck;
        _deck = new Deck();
    }
    _deck->shuffle();

    for (Player* player : _players) {
        player->getHand().clear();
        player->getHand().addCard(_deck->drawCard());
        player->getHand().addCard(_deck->drawCard());
    }
}

std::vector<Player*> Game::getWinners() {
    std::vector<Player*> winners;
    int bestScore = 0;

    for (Player* it : _players) {
        int score = it->getHand().getTotal();
        if (score > 21) continue;

        if (score > bestScore) {
            winners.clear();
            winners.push_back(it);
            bestScore = score;
        } else if (score == bestScore) {
            winners.push_back(it);
        }
    }

    return winners;
}

std::string Game::dealerDecision(Hand* hand) {
    unsigned total = hand->getTotal();

    if (total < 17)
        return "hit";
    else
        return "stand";
}

std::vector<Player*> Game::getPlayers() {
    return _players;
}

void Game::clearPlayers() {
    for (auto player : _players)
        delete player;
}

void Game::performAction(const std::string& playerName,
    const std::string& action) {
        for (Player* player : _players) {
            if (player->getName() == playerName) {
                if (action == "stand") {
                    // _ui->showHand(&player->getHand(), player->getName());
                    // _ui->showTurn(player);
                    break;
                } else if (action == "hit") {
                    player->getHand().addCard(_deck->drawCard());
                    // _ui->showDealt(player->getHand().getCards().back());
                    // _ui->showHand(&player->getHand(), player->getName());

                    if (player->getHand().getTotal() > 21) {
                        // _ui->showDefeat();
                        break;
                    }
                }
                break;
            }
        }
}
