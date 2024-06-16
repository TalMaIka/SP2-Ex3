// Tal Malka 315734616 Tal.coder@gmail.com
#include "catan.hpp"
#include <iostream>

Catan::Catan(Player &p1, Player &p2, Player &p3) : currentPlayer(0) {
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
}

void Catan::ChooseStartingPlayer() {
    std::cout << "Starting player is: " << players[0].name << std::endl;
}

Board Catan::getBoard() const {
    return board;
}

void Catan::printWinner(Player &p1,Player &p2,Player &p3){
    if(p1.points > p2.points && p1.points > p3.points){
        std::cout << p1.name << " is the winner!" << std::endl;
    }
    else if(p2.points > p1.points && p2.points > p3.points){
        std::cout << p2.name << " is the winner!" << std::endl;
    }
    else if(p3.points > p1.points && p3.points > p2.points){
        std::cout << p3.name << " is the winner!" << std::endl;
    }
    else
    std::cout << "None" << std::endl;
}


