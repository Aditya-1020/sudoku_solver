#include <stdio.h>

#define SIZE 3

void copy_array(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr2[i][j] = arr1[i][j];
        }
    }
}

int main() {
    int arr1[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arr2[SIZE][SIZE] = {0};

    copy_array(arr1, arr2);

    // Print arr2 to verify the copy
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}