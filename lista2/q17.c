#include <stdio.h>

int strfind(char c, char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    int N;

    scanf("%d%*c", &N);

    int r;
    char c;
    char s[499 + 1];

    int i;
    for (i = 0; i < N; i++) {
        scanf("%c %[^\n]%*c", &c, s);

        r = strfind(c, s);

        if (r == -1) {
            printf("Caractere %c nao encontrado.\n", c);
        }
        else {
            printf("Caractere %c encontrado no indice %d da string.\n", c, r);
        }

        strfind(c, s);
    }

    return 0;
}