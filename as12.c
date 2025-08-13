#include <stdio.h>

void shiftString(char *str, int offset) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = str[i] + offset;
        i++;
    }
}

int main() {
    char str[100];
    int offset;
    int i = 0;

    printf("Enter a string: ");
    while (i < 99) {
        char ch = getchar();
        if (ch == '\n' || ch == EOF) {
            break;
        }
        str[i] = ch;
        i++;
    }
    str[i] = '\0';

    printf("Enter an offset: ");
    scanf("%d", &offset);

    shiftString(str, offset);

    printf("Transformed string: %s\n", str);

    return 0;
}