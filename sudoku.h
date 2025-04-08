#ifndef SUDOKU_H // include guards check notes
#define SUDOKU_H
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SUDOKU_SIZE 9

// below these are basically a reference to the file this header is being included in
extern int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
extern int generated_puzzle[SUDOKU_SIZE][SUDOKU_SIZE];

bool generate_board(int arr[SUDOKU_SIZE][SUDOKU_SIZE]);
bool is_valid(int row, int col, int num, int arr[SUDOKU_SIZE][SUDOKU_SIZE]);
void puzzle_gen(int argc, char *argv[], int generated_puzzle[SUDOKU_SIZE][SUDOKU_SIZE]);


#endif // SUDOKU_H