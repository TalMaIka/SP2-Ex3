// Tal Malka 315734616 Tal.coder@gmail.com
#include <iostream>
#include <stdexcept>
#include <vector>
#include <unistd.h>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"


using namespace std;

int main()
{
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    catan.ChooseStartingPlayer();   
    Board board = catan.getBoard(); 
    board.distribute_initial_resources(p1); // The init distributio of resources.
    board.distribute_initial_resources(p2); // The init distributio of resources.
    board.distribute_initial_resources(p3); // The init distributio of resources.

    // Simulate the initial placement of settlements and roads for each player
    vector<string> places = {"Wheat", "Brick"};
    vector<int> placesNum = {4, 9};
    p1.placeSettelemnt(places, placesNum, board);
    p1.placeRoad(places, placesNum, board);
    places = {"Wheat", "Wood"};
    placesNum = {3, 4};
    p1.placeSettelemnt(places, placesNum, board);
    p1.placeRoad(places, placesNum, board);
    
    places = {"Brick", "Wood"};
    placesNum = {10, 6};
    p2.placeSettelemnt(places, placesNum, board);
    p2.placeRoad(places, placesNum, board);
    places = {"Wood", "Sheep"};
    placesNum = {8 , 5};
    p2.placeSettelemnt(places, placesNum, board);
    p2.placeRoad(places, placesNum, board);

    places = {"Wheat", "Wheat"};
    placesNum = {5, 9};
    p3.placeSettelemnt(places, placesNum, board);
    p3.placeRoad(places, placesNum, board);
    places = {"Wheat", "Sheep"};
    placesNum = {6, 9};
    p3.placeSettelemnt(places, placesNum, board);
    p3.placeRoad(places, placesNum, board);


    // Simulate additional turns and actions to demonstrate a player reaching 10 points (p2 in this case)
    while (p3.points < 10 && p2.points < 10 && p1.points < 10) {
        // Simulate turns and actions
        board.distribute_resources(p1.rollDice());
        // Perform actions for player 1 (p1)
        board.BuyDevelopmentCard(p1); // p1 buys a development card, collects points, etc.
        p1.endTurn();

        board.distribute_resources(p2.rollDice());
        // Perform actions for player 2 (p2)
        board.BuyDevelopmentCard(p2); // p1 buys a development card, collects points, etc.
        p2.endTurn();
        
        board.distribute_resources(p3.rollDice());
        // Perform actions for player 3 (p3)
        board.BuyDevelopmentCard(p3); // p1 buys a development card, collects points, etc.
        p3.endTurn();
        cout << "Points:" << endl;
        cout << p1.name << " " << p1.points << " " << p2.name << " " << p2.points << " " << p3.name << " " << p3.points << endl << endl;
        cout << "Resources:" << endl;
        cout << "Player 1: ";
        cout << "Wood: " << board.resources[p1.name]["Wood"] << " ";
        cout << "Brick: " << board.resources[p1.name]["Brick"] << " ";
        cout << "Wheat: " << board.resources[p1.name]["Wheat"] << " ";
        cout << "Ore: " << board.resources[p1.name]["Ore"] << " ";
        cout << "Sheep: " << board.resources[p1.name]["Sheep"] << endl;
        cout << "Player 2: ";
        cout << "Wood: " << board.resources[p2.name]["Wood"] << " ";
        cout << "Brick: " << board.resources[p2.name]["Brick"] << " ";
        cout << "Wheat: " << board.resources[p2.name]["Wheat"] << " ";
        cout << "Ore: " << board.resources[p2.name]["Ore"] << " ";
        cout << "Sheep: " << board.resources[p2.name]["Sheep"] << endl;
        cout << "Player 3: ";
        cout << "Wood: " << board.resources[p3.name]["Wood"] << " ";
        cout << "Brick: " << board.resources[p3.name]["Brick"] << " ";
        cout << "Wheat: " << board.resources[p3.name]["Wheat"] << " ";
        cout << "Ore: " << board.resources[p3.name]["Ore"] << " ";
        cout << "Sheep: " << board.resources[p3.name]["Sheep"] << endl << endl;
        sleep(2); // Sleep for 1 second to simulate a delay between turns
    }

    catan.printWinner(p1,p2,p3); // Should print the name of the player who reached 10 points
}
