#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED
/**
 * @brief Enumeration that represents the suit of the playing card.
 */
enum class SUITS { SPADES, CLUBS, HEARTS, DIAMONDS };
/**
 * @brief Enumeration that represents the rank of the playing card.
 */
enum class RANK {
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE
};

/**
 * @brief Card class, representing a playing card with rank and suit.
 * @brief //Serves as the model class.
 */
class Card {
 public:
  /**
   * @brief Card Constructor.
   * @param rank The rank of the card.
   * @param suit The suit of the card.
   */
  Card(RANK rank, SUITS suit);
  /**
   * @brief Card Destructor
   */
  ~Card();
  /**
   * @brief gets the rank of the card.
   * @return returns The rank of the card.
   */
  RANK getRank() const;
  /**
   * @brief gets the suit of the card.
   * @return returns The suit of the card.
   */
  SUITS getSuit() const;
  /**
   * @brief gets the numerical value of the card. Face cards returning 10, Ace
   * returning 11, and number cards returning the value shown
   * @return returns the numerical value of the card in a integer.
   */
  int getNumericalValue() const;
   /**
   * @brief Compares this card with another card.
   * Considered equal if they have the same suit and Rank.
   * @param other The card that it is compare against.
   * @return 'true' if the cards are equal, otherwise returns false.
   */
  bool operator==(const Card& other) const;
    /**
   * @brief Compares this card with another card if they are not equal.
   * Card is not considered equal if they do not have same rank and suit.
   * @param other The card that it is compare against.
   * @return 'true' if the cards are not equal, otherwise returns 'false.'
   */
  bool operator!=(const Card& other) const;

 private:
  RANK rank;
  SUITS suit;
};
#endif  // CARD_HPP_INCLUDED

