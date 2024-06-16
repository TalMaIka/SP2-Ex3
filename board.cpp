// Tal Malka 315734616 Tal.coder@gmail.com
#include "board.hpp"
#include "player.hpp"
#include <iostream>


Board::Board() {
    // 2D array of tiles
    tiles = {
        {Tile{"Sea", 0}, Tile{"Sea", 0}, Tile{"Sea", 0}, Tile{"Sea", 0}, Tile{"Sea", 0}},
        {Tile{"Sea", 0},Tile{"Brick", 9}, Tile{"Wood", 11}, Tile{"Sheep", 6},Tile{"Sea", 0}},
        {Tile{"Sea", 0},Tile{"Wheat", 4}, Tile{"Wood", 3}, Tile{"Wheat", 2}, Tile{"Sheep", 5},Tile{"Sea", 0}},
        {Tile{"Sea", 0},Tile{"Ore", 8}, Tile{"Desert", 0}, Tile{"Ore", 10}, Tile{"Wheat", 9},Tile{"Sea", 0}},
        {Tile{"Sea", 0},Tile{"Brick", 10}, Tile{"Sheep", 5}, Tile{"Brick", 12}, Tile{"Wheat", 4}, Tile{"Ore", 10},Tile{"Sea", 0}},
        {Tile{"Sea", 0},Tile{"Wood", 6}, Tile{"Wood", 3}, Tile{"Ore", 8},Tile{"Sea", 0}},
        {Tile{"Sea", 0}, Tile{"Sea", 0}, Tile{"Sea", 0}, Tile{"Sea", 0}, Tile{"Sea", 0}},
    };
    
}

//Print the board configuration
void Board::printBoard() {
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            std::cout << "[" << tile.resourceType << ", " << tile.number << "] ";
        }
        std::cout << std::endl;
    }
}

bool Board::placeSettlement(const std::string &playerName, const std::vector<std::string> &places, const std::vector<int> &placesNum) {
    // Check if the settlement location is already taken by any player
    for (const auto& player : settlements) {
        for (size_t i = 0; i < places.size(); ++i) {
            auto it = player.second.find(places[i]);
            if (it != player.second.end() && std::stoi(it->second) == placesNum[i]) {
                throw std::runtime_error("Invalid settlement placement.");
            }
        }
    }

    // Add the settlement since it's not taken
    add_settlement(playerName, places, placesNum);
    return true;
}

void Board::add_settlement(const std::string &playerName, const std::vector<std::string> &places, const std::vector<int> &placesNum) {
    for (size_t i = 0; i < places.size(); ++i) {
        settlements[playerName][places[i]] = std::to_string(placesNum[i]);
    }

}

bool Board::placeRoad(const std::string &playerName, const std::vector<std::string> &places, const std::vector<int> &placesNum) {
    // Check if the road is already taken by any player
    for (const auto& player : roads) {
        for (size_t i = 0; i < places.size(); ++i) {
            if (player.second.find(places[i]) != player.second.end() && player.second.at(places[i]) == std::to_string(placesNum[i])) {
                return false;
            }
        }
    }
    add_road(playerName, places, placesNum);
    return true;
}

//addroad
void Board::add_road(const std::string &playerName, const std::vector<std::string> &places, const std::vector<int> &placesNum) {
    for (size_t i = 0; i < places.size(); ++i) {
        roads[playerName][places[i]] = std::to_string(placesNum[i]);
    }
    
}

//Distribute initial resources to players
void Board::distribute_initial_resources(Player &p) {
    //Loop gives Each player starts with a total of 14 resource cards: 3 Brick, 4 Lumber, 4 Wheat, 3 Ore, and 4 Sheep.
            resources[p.name]["Bricks"]+=3;
            resources[p.name]["Wood"]+=4;
            resources[p.name]["Wheat"]+=4;
            resources[p.name]["Ore"]+=3;
            resources[p.name]["Sheep"]+=4;
    }
    

//Distribute initial resources to players
void Board::distribute_initial_resources(Player &p,vector<string> places) {
    // Go to the recource of the player and add the recouirces in the places
    for (size_t i = 0; i < places.size(); ++i) {
        cout << "Adding resources to " << p.name << " at " << places[i] << endl;
        resources[p.name][places[i]]++;
    }
}

// Distribute resources to players based on dice roll
void Board::distribute_resources(int roll_result) {
    // if roll_result is 7 no resources are distributed
    if (roll_result == 7) {
        cout << "No resources are distributed." << endl;
        return;
    }
    // Loop through all settlements and check if the settlement number matches the roll result for each player
    for (auto& player : settlements) {
        for (auto& settlement : player.second) {
            if(std::stoi(settlement.second) == roll_result){
                resources[player.first][settlement.first]++;
            }
        }
    }
    }

void Board::trade(Player &Sender, Player &Receiver, std::string giveResource, std::string receiveResource, int giveAmount, int receiveAmount){
    // Check if the sender has enough resources to trade
    if (resources[Sender.name][giveResource] >= giveAmount) {
            // Trade the resources
            resources[Sender.name][giveResource] -= giveAmount;
            resources[Receiver.name][receiveResource] += receiveAmount;
            std::cout << "Trade successful: " << Sender.name << " traded " << giveAmount << " " << giveResource << " to " << Receiver.name << " for " << receiveAmount << " " << receiveResource << std::endl;
        }
    else {
        std::cout << "Trade failed: " << Sender.name << " does not have enough " << giveResource << " to trade." << std::endl;
    }
}

bool Board::BuyDevelopmentCard(Player &p){
    // Check if the player has enough resources to buy a development card
    if (resources[p.name]["Wheat"] >= 1 && resources[p.name]["Wood"] >= 1 && resources[p.name]["Brick"] >= 1) {
        // Buy the development card
        resources[p.name]["Wheat"]--;
        resources[p.name]["Wood"]--;
        resources[p.name]["Brick"]--;
        std::cout << p.name << " bought a development card." << std::endl;
        p.points++;
        return true;
    }
    else {
        std::cout << p.name << " does not have enough resources to buy a development card." << std::endl;
        return false;
    }
}
