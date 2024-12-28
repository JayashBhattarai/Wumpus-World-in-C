#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 5 // Map size is 5x5

int map[MAP_SIZE][MAP_SIZE];
int player_x = 0, player_y = 0; // Player starts at (1,1)

// Function prototypes
void create_map();
void display_map();
void place_wumpus();
void place_doors();
void move_player();
void interact_with_map();

int main()
{
    srand(time(NULL)); // Seed for random placement
    create_map();
    display_map();
    
    while (1) {
        move_player();
        display_map();
    }

    return 0;
}

// Initialize the map
void create_map()
{
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0; // Empty space
        }
    }
    place_wumpus();
    place_doors();
}

// Display the map and player's position
void display_map()
{
    system("clear"); // Clear the console (use 'cls' for Windows)
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == player_y && j == player_x) {
                printf("P "); // Player position
            } else if (map[i][j] == 1) {
                printf("W "); // Wumpus
            } else if (map[i][j] == 4) {
                printf("D "); // Door
            } else {
                printf("+ "); // Empty space
            }
        }
        printf("\n");
    }
}

// Place Wumpus randomly on the map
void place_wumpus()
{
    int x = rand() % MAP_SIZE;
    int y = rand() % MAP_SIZE;
    map[y][x] = 1; // Wumpus position
}

// Place doors on the map
void place_doors()
{
    for (int i = 0; i < 3; i++) { // Place 3 doors
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        if (map[y][x] == 0) { // Ensure it's placed in an empty cell
            map[y][x] = 4; // Door position
        }
    }
}

// Allow the player to move and interact
void move_player()
{
    char move;
    printf("Move (WASD): ");
    scanf(" %c", &move);

    int new_x = player_x;
    int new_y = player_y;

    switch (move) {
        case 'w':
        case 'W':
            new_y = (player_y > 0) ? player_y - 1 : player_y;
            break;
        case 's':
        case 'S':
            new_y = (player_y < MAP_SIZE - 1) ? player_y + 1 : player_y;
            break;
        case 'a':
        case 'A':
            new_x = (player_x > 0) ? player_x - 1 : player_x;
            break;
        case 'd':
        case 'D':
            new_x = (player_x < MAP_SIZE - 1) ? player_x + 1 : player_x;
            break;
        default:
            printf("Invalid move!\n");
            return;
    }

    // Update player position
    player_x = new_x;
    player_y = new_y;

    // Interact with the current map cell
    interact_with_map();
}

// Interact with map elements
void interact_with_map()
{
    int cell = map[player_y][player_x];
    switch (cell) {
        case 1: // Wumpus
            printf("You encountered the Wumpus! Game Over.\n");
            exit(0);
        case 4: // Door
            printf("You found a door! Entering...\n");
            // Logic to move to another part of the map (e.g., teleportation)
            player_x = rand() % MAP_SIZE;
            player_y = rand() % MAP_SIZE;
            printf("You are now at (%d, %d).\n", player_y + 1, player_x + 1);
            break;
        default:
            printf("You move to an empty space.\n");
    }
}
