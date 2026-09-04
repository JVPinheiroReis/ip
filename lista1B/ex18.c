#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    if (n < 2) {
        printf("Fatoracao nao e possivel para o numero %d!\n", n);
        return main();
    }

    printf("%d = ", n);

    int i;
    for (i = 2; i <= n; i++) {
        while (n % i == 0) {
            if (n == i) {
                printf("%d", i);
                break;
            }

            printf("%d x ", i);

            n /= i;
        }
    }

    return 0;
}
