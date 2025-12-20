#include <stdio.h>

void findmaxmin(int arr[], int n) {
    int i;
    int max = arr[0];
    int min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Maximum : %d\n Minimum : %d\n", max, min);
}

int main() {
    int arr[] = {15, -4, 23, 0, 8, 99, -50, 12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);
    findmaxmin(arr, n);
    return 0;
}
