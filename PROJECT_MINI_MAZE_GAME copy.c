#include <stdio.h>
#include <stdlib.h>

// Define the structure for a cell in the maze
typedef struct Cell {
    int x, y;           // Coordinates of the cell
    struct Cell* next;  // Pointer to the next cell in the linked list
} Cell;

// Function to create a new cell
Cell* createCell(int x, int y) {
    Cell* newCell = (Cell*)malloc(sizeof(Cell));
    newCell->x = x;
    newCell->y = y;
    newCell->next = NULL;
    return newCell;
}

// Function to print the maze
void printMaze(Cell* current, Cell* exitCell) {
    // Assuming the maze is a 2D grid
    // You can customize the size and walls as needed
    int mazeSize = 5;  // Adjust the size of the maze
    char maze[mazeSize][mazeSize];

    // Initialize the maze
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            maze[i][j] = ' ';
        }
    }

    // Mark visited cells
    while (current != NULL) {
        maze[current->x][current->y] = '.';
        current = current->next;
    }

    // Print the maze
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create the maze linked list
    Cell* startCell = createCell(0, 0);
    Cell* exitCell = createCell(4, 4);  // Adjust exit cell coordinates

    // Initialize player location
    Cell* playerLocation = startCell;

    while (1) {
        // Print the maze
        printMaze(startCell, exitCell);

        // Check if the player has reached the exit
        if (playerLocation->x == exitCell->x && playerLocation->y == exitCell->y) {
            printf("Congratulations! You've reached the exit!\n");
            break;
        }

        // Get player's input for the next move
        printf("Enter direction (u/d/l/r): ");
        char direction;
        scanf(" %c", &direction);

        // Calculate the next location based on the input
        int nextX = playerLocation->x;
        int nextY = playerLocation->y;

        switch (direction) {
            case 'u':
                nextX--;
                break;
            case 'd':
                nextX++;
                break;
            case 'l':
                nextY--;
                break;
            case 'r':
                nextY++;
                break;
            default:
                printf("Invalid direction. Please enter u/d/l/r.\n\n");
                continue;
        }

        // Check if the next location is within bounds
        if (nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5) {
            playerLocation->next = createCell(nextX, nextY);
            playerLocation = playerLocation->next;
        }
    }

    // Free memory
    while (startCell != NULL) {
        Cell* temp = startCell;
        startCell = startCell->next;
        free(temp);
    }

    return 0;
}