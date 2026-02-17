#include <stdio.h>
/*
 * AIM:
 * This program generates and prints all possible subsequences
 * of a given string using recursion.
 *
 * A subsequence is a sequence derived from another string
 * by deleting some or none of the characters without changing
 * the order of the remaining characters.
 *
 * Example:
 * Input: "abc"
 * Output subsequences:
 * "abc", "ab", "ac", "a", "bc", "b", "c", ""
 */
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
