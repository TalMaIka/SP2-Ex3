// Tal Malka 315734616 Tal.coder@gmail.com
#ifndef CATAN_HPP
#define CATAN_HPP

#include "player.hpp"
#include "board.hpp"
#include <vector>

class Catan {
private:
    std::vector<Player> players;
    Board board;
    int currentPlayer;

public:
    Catan(Player &p1, Player &p2, Player &p3);
    void ChooseStartingPlayer();
    Board getBoard() const;
    void printWinner(Player &p1,Player &p2,Player &p3);
};

#endif // CATAN_HPP
