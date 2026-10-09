#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    if (n < 2) {
        printf("Campeonato invalido!\n");
        return 0;
    }

    int i;
    int j;
    int c = 0;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            c++;
            printf("Final %d: Time%d X Time%d\n", c, i, j);
        }
    }

    return 0;
}
