#include <stdio.h>

int main(void) {
    int n;
    char b, f;

    scanf("%d %c %c", &n, &b, &f);

    if (n < 1 || 99 < n || n % 2 == 0) {
        printf("Dimensao invalida!\n");
        return 0;
    }

    int i, j;
    for (i = 0; i < (n + 1) / 2; i++) {
        for (j = 0; j < n - (2 * i + 1); j++) {
            printf(" ");
        }

        for (j = 0; j < (2 * i + 1); j++) {
            if (j == 0 || j == (2 * i + 1) - 1) {
                printf("%c ", b);
            }
            else {
                printf("%c ", f);
            }
        }

        printf("\n");
    }
    for (i = (n - 1) / 2 - 1; 0 <= i; i--) {
        for (j = 0; j < n - (2 * i + 1); j++) {
            printf(" ");
        }

        for (j = 0; j < (2 * i + 1); j++) {
            if (j == 0 || j == (2 * i + 1) - 1) {
                printf("%c ", b);
            }
            else {
                printf("%c ", f);
            }
        }

        printf("\n");
    }

    return 0;
}