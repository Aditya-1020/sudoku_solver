#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SZ 9

// random number between 1 and 9
int get_random_number() {
    return rand() % 9 + 1;
}

// checks if placing 'num' at sudoku[row][col] is valid
int is_valid(int sudoku[SUDO_SZ][SUDO_SZ], int row, int col, int num) {
    //Check if 'num' is already in row, column 'col' and 3x3 block

    for (int j = 0; j < 9; j++) {
        if(sudoku[row][j] == num){
            return 0; // not validd
        }
    }
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == num) {
            return 0; // not valid
        }
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < (startRow + 3); i++) {
        for (int j = startCol; j < (startCol + 3); j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }   
        }
    }
    
    return 1; // if all valid
}

// Fill block with valid numbers
void blocky(int sudoku[SUDO_SZ][SUDO_SZ]) {
    for (int block = 0; block < SUDO_SZ; block++) {
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {

                int attempts = 0;
                int num;
                do {
                    num = get_random_number();
                    attempts++;

                    // You may want to limit attempts to prevent infinite loops
                    if (attempts > 1000) {
                        printf("Too many attempts at (%d,%d)\n", i, j);
                        return; // gedddouuuttt bi*ch
                    }

                } while (!is_valid(sudoku, i, j, num));

                sudoku[i][j] = num; // assign if vlad
            }
        }
    }
}

void print_sudoku(int sudoku[SUDO_SZ][SUDO_SZ]) {
    for (int i = 0; i < SUDO_SZ; i++) {
        for (int j = 0; j < SUDO_SZ; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int sudoku[SUDO_SZ][SUDO_SZ] = {0}; // elements are null at start

    srand(time(NULL)); // RNG

    blocky(sudoku);    // Fill the blocks
    print_sudoku(sudoku); // Show the result (for debugging)

    return 0;
}
