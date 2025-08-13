#include <stdio.h>

int main() {
    int rows, cols, th;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int zeroCount = 0, total = rows * cols;

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                zeroCount++;
    }

    printf("Enter threshold percentage (0-100): ");
    scanf("%d", &th);

    float zeroPercent = (zeroCount * 100.0) / total;

    printf("Zero entries: %d out of %d (%.2f%%)\n", zeroCount, total, zeroPercent);

    if (zeroPercent > th)
        printf("The matrix is a Sparse Matrix (zero entries > %d%%).\n", th);
    else
        printf("The matrix is NOT a Sparse Matrix (zero entries <= %d%%).\n", th);
        return 0;
}
}