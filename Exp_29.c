#include <stdio.h>

#define ROWS 5
#define COLS 5

// Initialize matrix lanes to zeros
void initializeMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Set nonzero lane (P0) and permute lanes
void permuteMatrix(int matrix[ROWS][COLS]) {
    matrix[0][0] = 1; // Set nonzero lane
    printf("Initial matrix with nonzero lane set:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // Simulate permutation
    printf("Simulating lane changes...\n");
}

int main() {
    int matrix[ROWS][COLS];
    initializeMatrix(matrix);
    permuteMatrix(matrix);
    return 0;
}
