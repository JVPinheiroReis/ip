#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    if (n <= 1) {
        printf("Numero invalido!\n");
        return 0;
    }

    int i;
    double t = 0;
    for (i = 1; i <= n; i++) {
        t += (double)1 / i;
    }

    printf("%f\n", t);

    return 0;
}
