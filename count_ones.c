#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[MAX_ROWS][MAX_COLS];
    int onesCount = 0; // Counter for number of 1s

    printf("Enter the binary matrix (only 0s and 1s):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1) {
                onesCount++; // Increment if input is 1
            }
        }
    }

    printf("Total number of 1s in the matrix: %d\n", onesCount);

    return 0;
}
