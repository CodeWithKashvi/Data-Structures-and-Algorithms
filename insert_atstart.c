#include <stdio.h>

void insertFirst(int arr[], int *n, int elements) {
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = elements;
    (*n)++;
}

int main() {
    int arr[10] = {10, 20, 30};
    int n = 3;
    int element = 5;
    printf("Before: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    insertFirst(arr, &n, element);
    printf("\nAfter: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
