#include <stdio.h>
#include <stdlib.h>

// Function to create a 2D array dynamically
int** create2DArray(int rows, int cols) {
    int **arr;
    arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }

    return arr;
}

// Function to input elements into the 2D array
void input2DArray(int **arr, int rows, int cols) {
    printf("Enter elements of the 2D array (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

// Function to display the 2D array
void display2DArray(int **arr, int rows, int cols) {
    printf("2D Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int rows, cols;
    int **myArray;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    myArray = create2DArray(rows, cols);
    input2DArray(myArray, rows, cols);
    display2DArray(myArray, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(myArray[i]);
    }
    free(myArray);

    return 0;
}