// Tal Malka 315734616 Tal.coder@gmail.com
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <map>
#include <string>
#include "player.hpp"

struct Tile {
    std::string resourceType;
    int number;
};

class Board {
private:
    std::vector<std::vector<Tile>> tiles;

public:
   // map of maps
   std::map<std::string, std::map<std::string, std::string>> settlements;
   std::map<std::string, std::map<std::string, std::string>> roads;
   std::map<std::string, std::map<std::string, int>> resources;

    Board();
    void printBoard();
    bool placeSettlement(const std::string &playerName, const std::vector<std::string> &places, const std::vector<int> &placesNum);
    bool placeRoad(const std::string &playerName, const std::vector<std::string> &places, const std::vector<int> &placesNum);
    void add_settlement(const std::string &playerName, const std::vector<std::string> &places, const std::vector<int> &placesNum);
    void add_road(const std::string &playerName, const std::vector<std::string> &places, const std::vector<int> &placesNum);
    void distribute_initial_resources(Player &p);
    void distribute_initial_resources(Player &p,vector<string> places);
    void distribute_resources(int roll_result);
    void trade(Player &Sender, Player &Receiver, std::string giveResource, std::string receiveResource, int giveAmount, int receiveAmount);
    bool BuyDevelopmentCard(Player &p);
    
};

#endif // BOARD_HPP
