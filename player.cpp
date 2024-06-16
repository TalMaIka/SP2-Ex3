// Tal Malka 315734616 Tal.coder@gmail.com
#include "player.hpp"
#include "board.hpp"
#include <iostream>
#include <stdexcept>
#include <random>

Player::Player(const std::string &name) : name(name), points(0) {}

void Player::placeSettelemnt(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board) {
    if (!board.placeSettlement(name, places, placesNum)) {
        throw std::runtime_error("Invalid settlement placement.");
    }
    else{
        std::cout << name << " placed a settlement at " << places[0] << " " << placesNum[0] << " and " << places[1]  << " " << placesNum[1] << std::endl;
        points++;
    }
}

void Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board) {
    if (!board.placeRoad(name, places, placesNum)) {
        throw std::runtime_error("Invalid road placement.");
    }
    else{
        std::cout << name << " placed a road at " << places[0] << " " << placesNum[0] << " and " << places[1]  << " " << placesNum[1] << std::endl;
    }
}

void Player::BuyDevelopmentCard(Board &b){
    if(b.BuyDevelopmentCard(*this)){
        points++;
    }
        
}

int Player::rollDice() {
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 6); 

    // Roll two dice
    int die1 = distrib(gen);
    int die2 = distrib(gen);

    // Calculate sum of dice
    int rollSum = die1 + die2;
    std::cout << name << " rolled a " << rollSum << std::endl;
    return rollSum;
}

void Player::endTurn() {
    std::cout << name << " ends their turn." << std::endl;
}

void Player::printPoints() const {
    std::cout << name << " has " << points << " points." << std::endl;
}



