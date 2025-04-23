#ifndef VIEW_HPP
#define VIEW_HPP

#include <string>
#include <vector>
#include "../model/Hand.hpp"
#include "../model/Player.hpp"


/**
* @brief represents the output for the game
* @brief Serves as the view class.
*/
class UI {
 public:
    /**
     * @brief constructor
     */
    UI() = default;

    /**
     * @brief returns string representation of hand.
     * 
     * @param hand pointer to a Hand object.
     * 
     * @param playerName reference to eitehr player 1 or 2.
     *
     * @return string representation of hand.
     */
     std::string showHand(Hand* hand, const std::string& playerName);

    /**
     * @brief return string prompt to either hit or stand.
     * 
     * @return string prompt.
     */
     void showActions();

    /**
     * @brief return victory message for winners.
     * 
     * @param winners Vector of Player pointers to winners.
     * 
     * @return string message.
     */
    std::string showWinners(std::vector<Player*> winners);

    /**
     * @brief return player turn message
     * 
     * @return string
     */
    std::string showTurn(Player* player);

    /**
     * @brief gives message showing which card was drawn.
     * 
     * @param Card* card pointer to drawn card.
     * 
     * @return string.
     */
    std::string showDealt(Card* card);

    /**
     * @brief gives you lsot and busted message to player.
     */
    void showDefeat();
    /**
     * @brief gives error message for incorrect input.
     */
    void errorMessage();

    /**
     * @brief return string symbol of suit
     * 
     * @param SUITS suit enum from card
     * 
     * @return string
     */
    std::string suit_symbol(SUITS suit);

    /**
     * @brief return name of suit
     * 
     * @param SUITS suit enum from card
     * 
     * @return string
     */
    std::string suit_name(SUITS suit);

    /**
     * @brief return symbol representation of rank
     * 
     * @param RANK rank enum from card
     * 
     * @return string
     */
    std::string rank_symbol(RANK rank);

    /**
     * @brief return name of rank.
     * 
     * @param RANK rank enum from card.
     * 
     * @return string.
     */
    std::string rank_name(RANK rank);
};

#endif // VIEW_HPP
