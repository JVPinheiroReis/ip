#include <stdio.h>

int main(void) {
    int n;
    int a1, a2, a3, a4;

    scanf("%d", &n);

    a1 = ((int)n / 100) % 10;
    a2 = ((int)n / 10) % 10;
    a3 = ((int)n / 1) % 10;

    a4 = (a1 + 3 * a2 + 5 * a3) % 7;

    n = 1000 * a1 + 100 * a2 + 10 * a3 + 1 * a4;

    printf("O NOVO NUMERO E = %d\n", n);

    return 0;
}
