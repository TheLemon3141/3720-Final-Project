#include "../../include/view/View.hpp"
#include <iostream>

std::string UI::showHand(Hand* hand, const std::string& playerName) {
    std::vector<Card*> cards = hand->getCards();
    std::string hand_string = playerName + "'s hand:\n";
    hand_string += "-----\n"; // top of first card

    for (auto it : cards) {
        hand_string.append("|");
        hand_string.append(this->rank_symbol(it->getRank()));
        hand_string.append(" ");
        hand_string.append(this->suit_symbol(it->getSuit()));
        hand_string.append("|\n");
        hand_string.append("-----\n");
    }
    std::cout << hand_string;
    return hand_string;
}


void UI::showActions() {
    std::cout << "hit  or stand: \n";
}

std::string UI::showWinners(std::vector<Player*> winners) {
    std::string victoryMessage;
    if (winners.empty()) {
        victoryMessage = "No winners!\n";
    } else {
        for (Player* winner : winners) {
            victoryMessage.append(winner->getName() + " wins!\n");
        }
    }
    std::cout << victoryMessage;
    return victoryMessage;
}

std::string UI::showTurn(Player* player) {
    std::string message = player->getName();
    message.append("'s turn.\n");

    return message;
}

void UI::errorMessage() {
    std::cout << "incorrect input. type either hit or stand\n";
}

void UI::showDefeat() {
    std::cout << "You Busted! \n";
}

std::string UI::showDealt(Card* card) {
    std::string message = "You were dealt the ";
    message.append(this->rank_name(card->getRank()));
    message.append(" of ");
    message.append(this->suit_name(card->getSuit()));
    message.append(".\n");

    return message;
}

std::string UI::suit_symbol(SUITS suit) {
    switch (suit) {
        case SUITS::SPADES:
            return "S";
        case SUITS::CLUBS:
            return "C";
        case SUITS::DIAMONDS:
            return "D";
        case SUITS::HEARTS:
            return "H";
        default:
            std::string message = "suit_symbol did not recognise suit";
            throw std::runtime_error(message);
    }
}

std::string UI::suit_name(SUITS suit) {
    switch (suit) {
        case SUITS::SPADES:
            return "Spades";
        case SUITS::CLUBS:
            return "Clubs";
        case SUITS::DIAMONDS:
            return "Diamonds";
        case SUITS::HEARTS:
            return "Hearts";
        default:
            std::string message = "suit_name did not recognise suit";
            throw std::runtime_error(message);
    }
}

std::string UI::rank_symbol(RANK rank) {
    switch (rank) {
        case RANK::TWO:
            return "2";
        case RANK::THREE:
            return "3";
        case RANK::FOUR:
            return "4";
        case RANK::FIVE:
            return "5";
        case RANK::SIX:
            return "6";
        case RANK::SEVEN:
            return "7";
        case RANK::EIGHT:
            return "8";
        case RANK::NINE:
            return "9";
        case RANK::TEN:
            return "10";
        case RANK::JACK:
            return "J";
        case RANK::QUEEN:
            return "Q";
        case RANK::KING:
            return "K";
        case RANK::ACE:
            return "A";
        default:
            std::string message = "rank_symbol did not recognize rank";
            throw std::runtime_error(message);
    }
}

std::string UI::rank_name(RANK rank) {
    switch (rank) {
        case RANK::TWO:
            return "2";
        case RANK::THREE:
            return "3";
        case RANK::FOUR:
            return "4";
        case RANK::FIVE:
            return "5";
        case RANK::SIX:
            return "6";
        case RANK::SEVEN:
            return "7";
        case RANK::EIGHT:
            return "8";
        case RANK::NINE:
            return "9";
        case RANK::TEN:
            return "10";
        case RANK::JACK:
            return "Jack";
        case RANK::QUEEN:
            return "Queen";
        case RANK::KING:
            return "King";
        case RANK::ACE:
            return "Ace";
        default:
            std::string message = "rank_name did not recognize rank";
            throw std::runtime_error(message);
    }
}
