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

    int a, b;

    int i, j;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);

        for (j = a; j <= b; j++) {
            printf("%d", j);
        }

        for (j = b; j >= a; j--) {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}