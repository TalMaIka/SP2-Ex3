// Tal Malka 315734616 Tal.coder@gmail.com
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <stdexcept>

class Board; 
using namespace std;

class Player {
public:
    std::string name;
    int points;

    Player(const std::string &name);
    void placeSettelemnt(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
    void placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
    int rollDice();
    void BuyDevelopmentCard(Board &b);
    void endTurn();
    void printPoints() const;
    
};

#endif // PLAYER_HPP
