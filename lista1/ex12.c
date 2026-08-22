#include <stdio.h>

int main(void) {
    unsigned int n;

    scanf("%d", &n);

    if (n < 2) {
        printf("Campeonato invalido!\n");
    }

    int i;
    int j;
    int c;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            c++;
            printf("Final %d: Time%d X Time%d\n", c, i, j);
        }
    }

    return 0;
}
