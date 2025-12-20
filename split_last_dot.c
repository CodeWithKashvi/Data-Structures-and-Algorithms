#include <stdio.h>



void split(char s[], char c, int n) {

    int i;

    if (n == 0) {

        for (i = 0; s[i] != c && s[i] != '\0'; i++) {

            printf("%c", s[i]);

        }

    } else {

        int last = -1;

        for (i = 0; s[i] != '\0'; i++) {

            if (s[i] == c) {

                last = i;

            }

        }

        for (i = last + 1; s[i] != '\0'; i++) {

            printf("%c", s[i]);

        }

    }

    printf("\n");

}



int main() {

    char s[] = "r.kiit24!.jpg";

    split(s, '.', 0);

    split(s, '.', 1);

    return 0;

}
