#include <stdio.h>
#include <stdlib.h>

// Function to read a polynomial
void readPoly(int *poly, int degree) {
    for (int i = degree; i >= 0; i--) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

// Function to print a polynomial
void printPoly(int *poly, int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i != degree && poly[i] > 0)
                printf(" + ");
            else if (poly[i] < 0)
                printf(" - ");
            if (abs(poly[i]) != 1 || i == 0)
                printf("%d", abs(poly[i]));
            else if (poly[i] == -1 && i != 0)
                printf("-");
            if (i > 0)
                printf("x");
            if (i > 1)
                printf("^%d", i);
        }
    }
    printf("\n");
}

// Function to add two polynomials
void addPoly(int *a, int *b, int *result, int degree) {
    for (int i = 0; i <= degree; i++)
        result[i] = a[i] + b[i];
}

// Function to subtract two polynomials
void subPoly(int *a, int *b, int *result, int degree) {
    for (int i = 0; i <= degree; i++)
        result[i] = a[i] - b[i];
}

int main() {
    int deg1, deg2, maxDeg;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);

    maxDeg = (deg1 > deg2) ? deg1 : deg2;

    int *poly1 = (int *)calloc(maxDeg + 1, sizeof(int));
    int *poly2 = (int *)calloc(maxDeg + 1, sizeof(int));
    int *sum = (int *)calloc(maxDeg + 1, sizeof(int));
    int *diff = (int *)calloc(maxDeg + 1, sizeof(int));

    printf("Enter first polynomial:\n");
    readPoly(poly1, deg1);

    printf("Enter second polynomial:\n");
    readPoly(poly2, deg2);

    addPoly(poly1, poly2, sum, maxDeg);
    subPoly(poly1, poly2, diff, maxDeg);

    printf("First Polynomial: ");
    printPoly(poly1, maxDeg);

    printf("Second Polynomial: ");
    printPoly(poly2, maxDeg);

    printf("Sum: ");
    printPoly(sum, maxDeg);

    printf("Difference (First - Second): ");
    printPoly(diff, maxDeg);

    free(poly1);
    free(poly2);
    free(sum);
    free(diff);

    return 0;
}
