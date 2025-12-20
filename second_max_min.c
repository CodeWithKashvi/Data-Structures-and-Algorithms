#include <stdio.h>

void findSecondMaxMin(int arr[], int n) {
    int i;
    int max1, max2, min1, min2;

    if (arr[0] > arr[1]) {
        max1 = arr[0];
        max2 = arr[1];
        min1 = arr[1];
        min2 = arr[0];
    } else {
        max1 = arr[1];
        max2 = arr[0];
        min1 = arr[0];
        min2 = arr[1];
    }

    for (i = 2; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }

        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }

    printf("Second Maximum: %d\n", max2);
    printf("Second Minimum: %d\n", min2);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    printf("Array: ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    findSecondMaxMin(arr, n);
    return 0;
}
