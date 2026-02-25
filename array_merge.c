// Aim: To write a C program to merge two arrays into a single array and display the merged array

#include <stdio.h>

void mergeArrays(int arr1[], int arr2[], int merged[], int n1, int n2) {
    int i;
    for (i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }
    for (i = 0; i < n2; i++) {
        merged[n1 + i] = arr2[i];
    }
}

int main() {
    int arr1[] = {10, 20, 30};
    int arr2[] = {40, 50, 60, 70};
    int merged[10];
    int n1 = 3, n2 = 4;

    printf("Array 1: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\nArray 2: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }

    mergeArrays(arr1, arr2, merged, n1, n2);

    printf("\nMerged Array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
