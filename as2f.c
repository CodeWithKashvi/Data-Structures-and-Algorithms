#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// Function to convert matrix to triplet
int **toTriplet(int **matrix, int rows, int cols, int *tripletRows) {
    int count = 0;
    // Count non-zero elements
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
                count++;
    *tripletRows = count + 1; // +1 for header row

    int **triplet = (int **)malloc((*tripletRows) * sizeof(int *));
    for (int i = 0; i < *tripletRows; i++)
        triplet[i] = (int *)malloc(3 * sizeof(int));

    // Header row
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = count;

    int k = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
            }
    return triplet;
}

// Function to print triplet
void printTriplet(int **triplet, int tripletRows) {
    printf("Triplet Representation:\n");
    printf("Row Col Value\n");
    for (int i = 0; i < tripletRows; i++)
        printf("%3d %3d %5d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
}

// Function to transpose triplet
int **transposeTriplet(int **triplet, int tripletRows) {
    int **trans = (int **)malloc(tripletRows * sizeof(int *));
    for (int i = 0; i < tripletRows; i++)
        trans[i] = (int *)malloc(3 * sizeof(int));
    // Header
    trans[0][0] = triplet[0][1];
    trans[0][1] = triplet[0][0];
    trans[0][2] = triplet[0][2];
    int k = 1;
    for (int col = 0; col < triplet[0][1]; col++) {
        for (int i = 1; i < tripletRows; i++) {
            if (triplet[i][1] == col) {
                trans[k][0] = triplet[i][1];
                trans[k][1] = triplet[i][0];
                trans[k][2] = triplet[i][2];
                k++;
            }
        }
    }
    return trans;
}

// Function to add two triplets
int **addTriplets(int **t1, int r1, int **t2, int r2, int *resRows) {
    if (t1[0][0] != t2[0][0] || t1[0][1] != t2[0][1]) {
        *resRows = 0;
        return NULL; // Incompatible sizes
    }
    int maxSize = t1[0][2] + t2[0][2] + 1;
    int **res = (int **)malloc(maxSize * sizeof(int *));
    for (int i = 0; i < maxSize; i++)
        res[i] = (int *)malloc(3 * sizeof(int));
    res[0][0] = t1[0][0];
    res[0][1] = t1[0][1];
    int k = 1, i = 1, j = 1;
    while (i < r1 && j < r2) {
        if (t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1])) {
            res[k][0] = t1[i][0];
            res[k][1] = t1[i][1];
            res[k][2] = t1[i][2];
            i++; k++;
        } else if (t2[j][0] < t1[i][0] || (t2[j][0] == t1[i][0] && t2[j][1] < t1[i][1])) {
            res[k][0] = t2[j][0];
            res[k][1] = t2[j][1];
            res[k][2] = t2[j][2];
            j++; k++;
        } else {
            res[k][0] = t1[i][0];
            res[k][1] = t1[i][1];
            res[k][2] = t1[i][2] + t2[j][2];
            i++; j++; k++;
        }
    }
    while (i < r1) {
        res[k][0] = t1[i][0];
        res[k][1] = t1[i][1];
        res[k][2] = t1[i][2];
        i++; k++;
    }
    while (j < r2) {
        res[k][0] = t2[j][0];
        res[k][1] = t2[j][1];
        res[k][2] = t2[j][2];
        j++; k++;
    }
    res[0][2] = k - 1;
    *resRows = k;
    return res;
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Dynamic allocation for matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    // a) Print the matrix
    printMatrix(matrix, rows, cols);

    // b) Print the triplet
    int tripletRows;
    int **triplet = toTriplet(matrix, rows, cols, &tripletRows);
    printTriplet(triplet, tripletRows);

    // c) Transpose the triplet
    int **transTriplet = transposeTriplet(triplet, tripletRows);
    printf("Transposed Triplet:\n");
    printTriplet(transTriplet, tripletRows);

    // d) Add two triplets (for demonstration, add the matrix to itself)
    int addRows;
    int **addTrip = addTriplets(triplet, tripletRows, triplet, tripletRows, &addRows);
    printf("Addition of two triplets (matrix + matrix):\n");
    printTriplet(addTrip, addRows);

    // Free memory
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    for (int i = 0; i < tripletRows; i++) free(triplet[i]);
    free(triplet);
    for (int i = 0; i < tripletRows; i++) free(transTriplet[i]);
    free(transTriplet);
    for (int i = 0; i < addRows; i++) free(addTrip[i]);
    free(addTrip);

    return 0;
}