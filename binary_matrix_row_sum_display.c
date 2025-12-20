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
    int rowSums[MAX_ROWS];

    printf("Enter the binary matrix (only 0s and 1s):\n");
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            rowSums[i] += matrix[i][j];
        }
    }

    printf("Matrix with row sums:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("| %d\n", rowSums[i]);
    }

    return 0;
}
