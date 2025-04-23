#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include "Hand.hpp"

/**
* @brief represents each player in the game
* @brief Serves as the model class.
*/
class Player {
 public:
    /**
     * @brief constructor for player
     *
     * @param reference of string to players name in this case player 1 or 2.
     *
     */
    Player(const std::string& name);
    /**
     * @brief gets players name and returns it
     *
     * @return returns players name.
     *
     */
    std::string getName() const;
    /**
     * @brief gets players hand and returns it
     *
     * @return returns players hand.
     *
     */
    Hand& getHand();

 private:
    /**
     * @brief string name of players
     *
     */
    std::string name;
    /**
     * @brief hand object of players
     *
     */
    Hand hand;
};

#endif // PLAYER_H_INCLUDED
