#include <stdio.h>

void generateSubsequences(char s[], int n, int index, char current[], int currentIndex) {
    int i;
    if (index == n) {
        current[currentIndex] = '\0';
        printf("%s\n", current);
        return;
    }

    current[currentIndex] = s[index];
    generateSubsequences(s, n, index + 1, current, currentIndex + 1);

    generateSubsequences(s, n, index + 1, current, currentIndex);
}

void printAllSubsequences(char s[]) {
    int i, n = 0;
    char current[100];
    for (i = 0; s[i] != '\0'; i++) {
        n++;
    }
    printf("All subsequences of \"%s\":\n", s);
    generateSubsequences(s, n, 0, current, 0);
}

int main() {
    char s[] = "abc";
    printAllSubsequences(s);
    return 0;
}
