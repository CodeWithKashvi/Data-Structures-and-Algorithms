//Aim: To write a C program to input a binary matrix using user-defined rows and columns 
//and display the matrix along with the sum of each row

#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];     
    int rowSums[rows];          

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
