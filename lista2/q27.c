#include <stdio.h>

char lowercase(char c) {
    if ('A' <= c && c <= 'Z') return c + 'a' - 'A';
    return c;
}

int is_letter(char c) {
    c = lowercase(c);

    if ('a' <= c && c <= 'z') {
        return 1;
    }

    return 0;
}

int main(void) {
    int N;

    scanf("%d", &N);

    int i, j;
    for (i = 0; i < N; i++) {
        char s[200 + 1] = "\0";
        scanf(" %[^\n]", s);

        int abc[26] = {0};
        for (j = 0; s[j] != '\0'; j++) {
            if (is_letter(s[j])) {
                abc[lowercase(s[j]) - 'a']++;
            }
        }

        int max = abc[0];
        for (j = 0; j < 26; j++) {
            if (abc[j] > max) {
                max = abc[j];
            }
        }

        for (j = 0; j < 26; j++) {
            if (abc[j] == max) {
                printf("%c", j + 'a');
            }
        }
        printf("\n");
    }

    return 0;
}