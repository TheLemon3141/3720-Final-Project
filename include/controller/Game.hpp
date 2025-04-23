// Blackjack rules:
// https://bicyclecards.com/how-to-play/blackjack

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <vector>
#include <string>
#include "../model/Deck.hpp"
#include "../model/Player.hpp"
#include "../view/View.hpp"

//Serves as the controller class.
class Game {
 public:
   /**
     * @brief Game constructor.
     * @param[in] ui A pointer to a user interface to be used for the game.
     * @param[in] deck A pointer to a deck to be used for the game.
     */
    Game(UI* _ui);

   /**
     * @brief Game destructor.
     */
    ~Game();

   /**
     * @brief Adds a player to the game.
     * @param[in] player A pointer to the player to be added.
     */
    void addPlayer(Player* player);
   /**
     * @brief Runs a game of blackjack: deals cards, lets players hit or stand, returns winners.
     */
    void start();

    /**
     * @brief Returns a vector with pointers to the winners (the players with the highest scores <= 21)
     * @return a vector with pointers to all players with the highest scores <= 21
     */
    std::vector<Player*> getWinners();
        //Should pass this to the UI to print eventually

    /**
     * @brief Tells whether to stop the game loop and declare winners.
     * @return true if if _playersStillIn has 0 items, false if not.
     */
    bool isOver();

    /**
     * @brief Initializes Game.
     * @details Deals 2 cards to each player.
     */
    void init();

    /**
     * @brief player list getter.
     * @return vector of player pointers.
     */
    std::vector<Player*> getPlayers();

    /**
     * @brief Deletes all players in game.
     */
    void clearPlayers();

    /**
     * @brief simualtes beign able to hit and stand for endpoints.
     */
    void performAction(const std::string& playerName, const std::string& action);
    
    /**
     * @brief AI decision maker
     * 
     * @return "hit" if decision is hit, "stand" otherwise.
     */
    std::string dealerDecision(Hand* hand);

     /*
     //A specific setup for a test game
     void testGameSetup() {
      //Make some test cards
      Card* cardAce = new Card(RANK::ACE, SUITS::HEARTS);
      Card* cardKing = new Card(RANK::KING, SUITS::SPADES);
      Card* cardFive = new Card(RANK::FIVE, SUITS::DIAMONDS);
      Card* cardSix = new Card(RANK::SIX, SUITS::DIAMONDS);

      //Clear players' hands
      for (auto player : _players) {
          int size = player->getHand().getCards().size();
          for (Card* card : player->getHand().getCards()) {
          delete card;
          }
      }
      //Add cards to players' hands
      Player* player1 = _players[0];
      player1->getHand().addCard(cardAce);
      player1->getHand().addCard(cardKing);
    
      Player* dealer = _players[1];
      dealer->getHand().addCard(cardFive);
      dealer->getHand().addCard(cardSix);
      }
    */

 private:

    std::vector<Player*> _players;
    Deck* _deck;
    UI* _ui;
};


#endif //GAME_HPP_INCLUDED
