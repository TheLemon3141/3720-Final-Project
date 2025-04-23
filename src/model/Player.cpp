#include "../../include/model/Player.hpp"

Player::Player(const std::string& name) : name(name) {}

std::string Player::getName() const { return name; }

Hand& Player::getHand() { return hand; }
