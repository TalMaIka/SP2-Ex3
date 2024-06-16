# Catan Board Game Simulation

This project simulates the classic board game "Catan" in a digital format, allowing players to build settlements, roads, and cities while managing resources and trading with each other.

## Features

- **Board Setup:** Initializes a game board with various resource tiles and numbers.
- **Settlement Placement:** Allows players to place settlements, checking for existing placements to avoid duplicates.
- **Road Placement:** Enables players to build roads, ensuring unique placement per player.
- **Resource Distribution:** Distributes resources based on dice rolls, except during a "7" roll which triggers resource theft.
- **Development Cards:** Implements buying and using development cards like Knight, Year of Plenty, and Road Building.
- **Trading:** Facilitates resource trading between players based on agreed terms.
- **Victory Conditions:** Tracks player points and declares a winner upon reaching the required points (typically 10).

## Implementation Details

### Board Class

- **tiles:** Represents the board as a 2D array of tiles with resource types and numbers.
- **printBoard():** Prints the current configuration of the game board.
- **placeSettlement():** Checks and adds settlements for players, ensuring no duplicate placements.
- **placeRoad():** Manages road placements for players, validating uniqueness.
- **distribute_initial_resources():** Initializes players with starting resources: 3 Brick, 4 Lumber, 4 Wheat, 3 Ore, and 4 Sheep.
- **distribute_resources():** Distributes resources to players based on dice rolls, updating their resource counts accordingly.

### Player Class

- **name:** Player's name.
- **points:** Player's current points.
- **resources:** Maps resource types to their respective counts for each player.
- **trade():** Facilitates resource exchanges between players.
- **buyDevelopmentCard():** Allows players to purchase development cards, increasing their points upon successful purchase.

### Usage

1. **Installation:**
   - Clone the repository:
     ```bash
     git clone https://github.com/TalMaIka/SP2-Ex3.git
     cd SP2-Ex3
     ```

2. **Running the Simulation:**
   - Execute the compiled binary:
     ```bash
     make main
     ```
   - Follow the on-screen instructions to play and interact with the simulation.

3. **Gameplay:**
   - Place settlements and roads strategically.
   - Roll dice to produce resources and manage your inventory.
   - Trade resources with other players to gain advantages.
   - Purchase development cards to boost your points towards victory.
