#include <stdio.h>

void deleteElements(int arr[], int *n, int elements) {
    int i, pos = -1;

    for (i = 0; i < *n; i++) {
        if (arr[i] == elements) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Elements %d not found!\n", elements);
        return;
    }

    for (i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Elements %d deleted successfully!\n", elements);
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;
    int elements = 30;
    printf("Before: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    deleteElements(arr, &n, elements);
    printf("\nAfter: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
