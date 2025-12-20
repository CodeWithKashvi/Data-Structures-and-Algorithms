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
    int first = 1;
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!first && poly[i] > 0)
                printf(" + ");
            if (poly[i] < 0)
                printf(" - ");
            if (abs(poly[i]) != 1 || i == 0)
                printf("%d", abs(poly[i]));
            else if (poly[i] == -1 && i != 0)
                printf("-");
            if (i > 0)
                printf("x");
            if (i > 1)
                printf("^%d", i);
            first = 0;
        }
    }
    if (first) printf("0");
    printf("\n");
}

// Function to multiply two polynomials
void multiplyPoly(int *a, int degA, int *b, int degB, int *result) {
    for (int i = 0; i <= degA; i++) {
        for (int j = 0; j <= degB; j++) {
            result[i + j] += a[i] * b[j];
        }
    }
}

int main() {
    int deg1, deg2;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);

    int *poly1 = (int *)calloc(deg1 + 1, sizeof(int));
    int *poly2 = (int *)calloc(deg2 + 1, sizeof(int));
    int *product = (int *)calloc(deg1 + deg2 + 1, sizeof(int));

    printf("Enter first polynomial:\n");
    readPoly(poly1, deg1);

    printf("Enter second polynomial:\n");
    readPoly(poly2, deg2);

    multiplyPoly(poly1, deg1, poly2, deg2, product);

    printf("First Polynomial: ");
    printPoly(poly1, deg1);

    printf("Second Polynomial: ");
    printPoly(poly2, deg2);

    printf("Product: ");
    printPoly(product, deg1 + deg2);

    free(poly1);
    free(poly2);
    free(product);

    return 0;
}
