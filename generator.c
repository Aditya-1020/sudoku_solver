#include <stdio.h>
#include "sudoku.h"

int sudoku[SUDOKU_SIZE][SUDOKU_SIZE] = {0};
int generated_puzzle[SUDOKU_SIZE][SUDOKU_SIZE];


void puzzle_gen(int argc, char *argv[], int generated_puzzle[SUDOKU_SIZE][SUDOKU_SIZE]) {
    const char *difficulty = (argc < 2) ? "medium" : argv[1]; // Default to medium

    if (strcmp(difficulty, "medium") != 0 && strcmp(difficulty, "hard") != 0) {
        printf("Invalid argument. Please use 'medium' or 'hard'.\n");
        exit(1);
    }

    int cells_to_remove = 0;

    if (strcmp(difficulty, "hard") == 0) {
        cells_to_remove = 50 + rand() % 8; // 50–57
    } else {
        cells_to_remove = 36 + rand() % 10; // 36–45
    }

    int removed = 0;

    while (removed < cells_to_remove) {
        int row = rand() % SUDOKU_SIZE;
        int col = rand() % SUDOKU_SIZE;

        if (generated_puzzle[row][col] != 0) {
            generated_puzzle[row][col] = 0;
            removed++;
        }
    }
}

bool is_valid(int row, int col, int num, int arr[SUDOKU_SIZE][SUDOKU_SIZE]){
    for (int k = 0; k < SUDOKU_SIZE; k++){
        if (arr[row][k] == num) return false; // row check
        if (arr[k][col] == num) return false; // column check
    }

    int start_Row = (row / 3) * 3;
    int start_Col = (col / 3) * 3;

    for (int r = start_Row; r < start_Row + 3; r++) {
        for (int c = start_Col; c < start_Col + 3; c++) {
            if (arr[r][c] == num) return false;
        }
    }

    return true;
}

// Fisher–Yates shuffle to randomize numbers 1–9
void get_shuffled_numbers(int nums[9]) {
    for (int i = 0; i < 9; i++) {
        nums[i] = i + 1;
    }

    for (int i = 8; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

bool generate_board(int arr[SUDOKU_SIZE][SUDOKU_SIZE]) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            if (arr[i][j] == 0) {
                int nums[9];
                
                get_shuffled_numbers(nums);

                for (int k = 0; k < 9; k++) {
                    int num = nums[k];
                    if (is_valid(i, j, num, arr)) {
                        arr[i][j] = num;

                        if (generate_board(arr)) return true;

                        arr[i][j] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed RNG

    generate_board(sudoku);
    
    puzzle_gen(argc, argv, sudoku);

    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    return 0;
}