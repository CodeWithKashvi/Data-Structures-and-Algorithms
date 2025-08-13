#include <stdio.h>

int main() {
    int a[10];
    int n, i;
    int max, min;

    printf("Enter number of elements (1 to 10): ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0 || n > 10) {
        printf("Invalid input. Please enter a number between 1 and 10.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Initialization
    max = min = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    printf("Max = %d\nMin = %d\n", max, min);
    return 0;
}
