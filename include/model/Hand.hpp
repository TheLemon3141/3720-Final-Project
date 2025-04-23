#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include <vector>
#include "Card.hpp"

/**
* @brief represents the hand of the each player
* @brief Serves as the model class.
*/
class Hand {
 public:
    /**
     * @brief addeds cards from the deck to players
     * 
     * @param card pointer to a card object.
     *
     */
    void addCard(Card* card);
    /**
     * @brief gets the total score of player
     * @brief if player has an ace it could be either 11 or 1
     *
     */
    int getTotal() const;
    /**
     * @brief clears players hand.
     *
     */
    void clear();
    /**
     * @brief vector of cards from the deck 
     *
     * @return returns card from the vector at random when called.
     *
     */
    const std::vector<Card*>& getCards() const;

 private:
 /**
     * @brief vector of cards
     *
     */
    std::vector<Card*> cards;
};

#endif // HAND_H_INCLUDED
