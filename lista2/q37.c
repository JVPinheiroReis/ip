#include <stdio.h>

char lowercase(char c) {
    if ('A' <= c && c <= 'Z') {
        return c + 'a' - 'A';
    }
    return c;
}

char uppercase(char c) {
    if ('a' <= c && c <= 'z') {
        return c + 'A' - 'a';
    }
    return c;
}

int main(void) {
    int i, up;
    char s[50 + 1] = {0};

    while (scanf("%50[^\n]%*c", s) != EOF) {
        up = 1;
        for (i = 0; s[i] != '\0'; i++) {
            while (s[i] == ' ') {
                i++;
            }

            if (up) {
                s[i] = uppercase(s[i]);
            }
            else {
                s[i] = lowercase(s[i]);
            }

            up = !up;
        }

        printf("%s\n", s);
    }

    return 0;
}