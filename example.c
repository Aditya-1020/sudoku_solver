#include <stdio.h>

int main() {
    // Example 9x9 grid
    int grid9x9[9][9];

    // Fill the 9x9 grid using for loops
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid9x9[i][j] = rand() % 9 + 1; // Assign a random integer from 1 to 9
        }
    }
    // Print 3x3 parts of the grid
    printf("3x3 Parts of the Grid:\n");
    for (int block = 0; block < 9; block++) { // Loop through each 3x3 block
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // Loop through rows in the block
            for (int j = startCol; j < startCol + 3; j++) { // Loop through columns in the block
                printf("%d ", grid9x9[i][j]); // Print the current element in the block
            }
            printf("\n"); // Move to the next row in the block
        }
        printf("\n"); // Add a blank line after each block
    }
    
    /*
    printf("9x9 Grid:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid9x9[i][j]);
        }
        printf("\n");
    }
    */

    return 0;
}