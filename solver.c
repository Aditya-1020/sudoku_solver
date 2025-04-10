#include <stdio.h>
#include "sudoku.h"

int solver(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE]){
    for (int i = 0; i < SUDOKU_SIZE; i++){
        for (int j = 0; j < SUDOKU_SIZE; j++){
            if (puzzle[i][j] == 0){
                // iterate from 1->9 checking each number if its valid
                for (int k = 1; k <= 9; k++){
                    if (is_valid(i, j, k, puzzle)){
                        puzzle[i][j] = k;

                    if (solver(puzzle)) return 1; // Recursively attempt to fill the rest of the board
                    
                    puzzle[i][j] = 0; // backtracking
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[]){

    
    srand(time(NULL));
    generate_board(sudoku);
    
    for (int i = 0; i < SUDOKU_SIZE; i++){
        for (int j = 0; j < SUDOKU_SIZE; j++){
            generated_puzzle[i][j] = sudoku[i][j];
        }
    }

    puzzle_gen(argc, argv, generated_puzzle); // remove values

    printf("\nGenerated Puzzle:\n");
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            printf("%d ", generated_puzzle[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    clock_t start_time = clock(); // Start measuring time

    if (solver(generated_puzzle)) {
        printf("Solved Sudoku:\n");
        for (int i = 0; i < SUDOKU_SIZE; i++) {
            for (int j = 0; j < SUDOKU_SIZE; j++) {
                printf("%d ", generated_puzzle[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }
    
    printf("\n");

    clock_t end_time = clock(); // End measuring time
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time Taken to Solve: %f seconds\n\n", time_taken);
    
    
    return 0;
}