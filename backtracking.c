#include <stdio.h>
#include <string.h>

#define SUDO_SZ 9

int main(void) {
    int sudoku[SUDO_SZ][SUDO_SZ];

    for (int i = 0; i < SUDO_SZ; i++) {
        for (int j = 0; j < SUDO_SZ; j++) {
            int num = rand() % 9 + 1; // random integer between 1 -> 9
            if (num != sudoku[i][j] && ){ // after the and i want to check how to isolate the the row, col and the particular box the cell[i][j] is in..?
                /* code */
            }
            
        }
    }

    /*
        for num range(1,9) and num not in same row/col/box:
            arr[i][j] == 
    
    */
    

    return 0;
}