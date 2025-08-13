#include <stdio.h>

void lemmatize(char word[]) {
    int i, len = 0;
    for (i = 0; word[i] != '\0'; i++) {
        len++;
    }

    if (len >= 3 && word[len - 1] == 'g' && word[len - 2] == 'n' && word[len - 3] == 'i') {
        word[len - 3] = '\0';
    } else if (len >= 3 && word[len - 1] == 's' && word[len - 2] == 'r' && word[len - 3] == 'e') {
        word[len - 3] = '\0';
    } else if (len >= 2 && word[len - 1] == 'r' && word[len - 2] == 'e') {
        word[len - 2] = '\0';
    } else if (len >= 2 && word[len - 1] == 's' && word[len - 2] == 'e') {
        word[len - 2] = '\0';
    } else if (len >= 1 && word[len - 1] == 's') {
        word[len - 1] = '\0';
    }

    printf("%s\n", word);
}

int main() {
    char word1[] = "fishing";
    char word2[] = "fishes";
    char word3[] = "readers";
    char word4[] = "reading";

    lemmatize(word1);
    lemmatize(word2);
    lemmatize(word3);
    lemmatize(word4);

    return 0;
}